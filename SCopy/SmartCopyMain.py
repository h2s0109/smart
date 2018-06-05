from Mcalcopytab import Ui_Dialog
from PyQt5 import QtCore
from PyQt5.QtGui import QPainter, QFont, QStandardItemModel, QStandardItem
from PyQt5.QtWidgets import QDialog, QStyledItemDelegate, QStyleOptionViewItem, QFileDialog, QApplication
from PyQt5.QtCore import QItemSelectionModel, Qt, pyqtSignal, pyqtSlot, QItemSelection, QAbstractItemModel, QDir, QFile
from sort import import_data, gen_c_h_dic, export_data, copy_mcalmodule, gen_sort, moduledatashow
import json
import os
from re import search, sub, match, fullmatch
from distutils.dir_util import remove_tree
from UpdateCombo import Class_UpdateCombo


class ImageDialog(QDialog, Ui_Dialog, Class_UpdateCombo):
    def __init__(self):
        super().__init__()
        # Set up the user interface from Designer
        self.setupUi(self)
        self.RelieveModuleModel = QStandardItemModel()
        self.SetModuleModel = QStandardItemModel()
        THIS_DIR = os.path.dirname(__file__)
        # Module name will be changed at official release.
        self.DATABASE_PATH = os.path.realpath(
            "{0}/Database/sort_key.json".format(THIS_DIR))
        self.TEMP_DATABASE_PATH = os.path.realpath(
            "{0}/Database/data_key.json".format(THIS_DIR))
        self.module_sort_result = dict()
        self.refine_result = dict()
        self.CopyProcessValid = False
        self.CopyProcessValid_NoSelect = True
        # Call the folder list which were opened recently
        self.create_recent_handler('Mcal.ini', 5)
        self.UpdateRecentOpenFile(self.McalComboBox, 'Mcal')
        self.UpdateRecentOpenFile(self.ModuleComboBox, 'Module')
        self.UpdateRecentOpenFile(self.SmoduleComboBox, 'Smodule')
        self.McalComboBox.currentIndexChanged.connect(
            lambda: self.ComboxBoxClick(self.McalComboBox))
        self.McalDirButton.clicked.connect(
            lambda: self.setExistingDirectory2(self.McalComboBox, 'Mcal',  'Mcal'))
        self.ModuleDirButton.clicked.connect(
            lambda: self.setExistingDirectory2(self.ModuleComboBox, 'Module', 'Module'))
        self.SmoduleDirButton.clicked.connect(
            lambda: self.setExistingDirectory2(self.SmoduleComboBox, 'Smodule', 'Module'))

        self.SetModuleButton.clicked.connect(lambda: self.SetModuleTreeViewUpdate(
            self.RelieveModuleModel, self.SetModuleModel))
        self.RelieveModuleButton.clicked.connect(lambda: self.SetModuleTreeViewUpdate_Relieve(
            self.SetModuleModel, self.RelieveModuleModel))
        self.CopyButton.clicked.connect(self.CopyProcess)

    def RebuildtreeInit(self, elements):
        rebuildtree = dict()
        for module in elements:
            rebuildtree.update({module: []})
        return rebuildtree

    def SetModuleTreeViewUpdate_Relieve(self, SetModuleParent, RelieveModuleParent):
        if self.CopyProcessValid is True:
            self.plainTextEdit_Install.appendPlainText("Selected item removed")
            rebuildtree = dict()
            for k_num in range(0, SetModuleParent.rowCount()):
                index_basemodule = SetModuleParent.index(k_num, 0)
                data = SetModuleParent.data(index_basemodule)
                rowCount_child = SetModuleParent.rowCount(index_basemodule)
                listcheck = list()
                item_child = SetModuleParent.itemFromIndex(index_basemodule)
                for j_num in range(0, rowCount_child):
                    index_basemodule_child = SetModuleParent.index(
                        j_num, 0, index_basemodule)
                    item = SetModuleParent.itemFromIndex(
                        index_basemodule_child)
                    data2 = SetModuleParent.data(index_basemodule_child)
                    print(data, data2, rowCount_child, j_num)
                    if item_child.checkState() == Qt.Checked:
                        item_child.setCheckState(Qt.Unchecked)
                        item_child.setFlags(Qt.ItemIsTristate)
                        data_child = SetModuleParent.data(
                            index_basemodule_child)
                        listcheck = [msls for msls in range(0, rowCount_child)]
                        listcheck.sort(reverse=True)
                        rebuildtree.update({index_basemodule: listcheck})
                        break
                        # SetModuleParent.removeRows(k_num,0,index_basemodule)
                    elif item.checkState() == Qt.Checked:
                        data_child = SetModuleParent.data(
                            index_basemodule_child)
                        listcheck.append(j_num)
                    listcheck.sort(reverse=True)
                    rebuildtree.update({index_basemodule: listcheck})
            for lll in rebuildtree:
                if len(rebuildtree[lll]):
                    for y in rebuildtree[lll]:
                        mkz = SetModuleParent.removeRow(y, lll)
            parentCount = SetModuleParent.rowCount()
            tempCount = 0
            for k_num in range(0, parentCount):
                index_basemodule = SetModuleParent.index(k_num, 0)
                if not SetModuleParent.hasChildren(index_basemodule):
                    item2 = SetModuleParent.itemFromIndex(index_basemodule)
                    item2.setFlags(Qt.ItemIsTristate)
                    tempCount += 1
                    # if all module is selected, no more copy process progresses
                    if tempCount is parentCount:
                        self.CopyProcessValid_NoSelect = True
                        self.plainTextEdit_Install.appendPlainText(
                            "All modules are unselected")
        else:
            self.plainTextEdit_Install.setPlainText("Module is not yet loaded")

    def SetModuleTreeViewUpdate(self, Relieve_parent, SetModuleParent):
        if self.CopyProcessValid is True:
            self.CopyProcessValid_NoSelect = False
            rebuildtree = dict()
            for k_num in range(0, Relieve_parent.rowCount()):
                index_basemodule = Relieve_parent.index(k_num, 0)
                data = Relieve_parent.data(index_basemodule)
                listcheck = list()
                item2 = Relieve_parent.itemFromIndex(index_basemodule)
                for j_num in range(0, Relieve_parent.rowCount(index_basemodule)):
                    index_basemodule2 = Relieve_parent.index(
                        j_num, 0, index_basemodule)
                    item = Relieve_parent.itemFromIndex(index_basemodule2)
                    if item2.checkState() == Qt.Checked:
                        data2 = Relieve_parent.data(index_basemodule2)
                        listcheck.append(data2)
                    elif item.checkState() == Qt.Checked:
                        data2 = Relieve_parent.data(index_basemodule2)
                        listcheck.append(data2)
                rebuildtree.update({data: listcheck})
            sort_data = import_data(self.DATABASE_PATH, "SORTING")
            sorkey_datas = import_data(self.DATABASE_PATH, "SORTINGKEY")
            smodule_data = rebuildtree["SERVICEMODULE"]
            module_data = rebuildtree["MODULELIST"] + \
                rebuildtree["BASICMODULE"]
            smodule_sort_result = gen_c_h_dic(
                self.McalComboBox.currentText(), sort_data, smodule_data, True)
            self.module_sort_result = gen_c_h_dic(
                self.McalComboBox.currentText(), sort_data, module_data)
            self.refine_result = gen_sort(
                self.module_sort_result, smodule_sort_result, sorkey_datas)
            SetModuleParent.clear()
            self.SetModuleBuildtree(SetModuleParent, rebuildtree)
            self.SetModuleTreeView.expandAll()
        else:
            self.plainTextEdit_Install.setPlainText("Module is not yet loaded")

    def SetModuleBuildtree(self, parent, elements):
        module_inform = dict()
        for module in elements:
            module_inform.update({module: {'indexnum': 0}})
            item_module = QStandardItem(module)
            item_module.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsTristate)
            item_module.setCheckState(Qt.Unchecked)
            if len(elements[module]):
                item_module.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                item_module.setCheckState(Qt.Unchecked)
                checkvalue = Qt.Unchecked
                option = Qt.ItemIsUserCheckable | Qt.ItemIsEnabled
                self.build_child(
                    item_module, elements[module], checkvalue, option)
            parent.appendRow(item_module)
            module_inform[module]['indexnum'] = parent.rowCount() - 1
        self.plainTextEdit_Install.appendPlainText("Selected item inserted")
        return module_inform

    def modulecheck(self, elements, pop_elements):
        """Remove pop_elements from the elements"""
        for k_pop_elements in pop_elements:
            for j_elements in elements[k_pop_elements]:
                print(j_elements)
                try:
                    indexnum = elements['MODULELIST'].index(j_elements)
                    elements['MODULELIST'].pop(indexnum)
                except:
                    print("can not find")

    def checkboxclick(self, parent, tree_inform):
        for j_basemodule in tree_inform:
            indexnum = tree_inform[j_basemodule]['indexnum']
            index_basemodule = parent.index(indexnum, 0)
            count_basemodule = parent.rowCount(index_basemodule)
            # a = parent.data(index_basemodule)
            item = parent.itemFromIndex(index_basemodule)
            if item.checkState() == Qt.Unchecked:
                for k_num in range(0, count_basemodule):
                    child_index_basemodule = parent.index(
                        k_num, 0, index_basemodule)
                    child_item = parent.itemFromIndex(child_index_basemodule)
                    child_item.setFlags(
                        Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
            elif item.checkState() == Qt.Checked:
                for k_num in range(0, count_basemodule):
                    child_index_basemodule = parent.index(
                        k_num, 0, index_basemodule)
                    child_item = parent.itemFromIndex(child_index_basemodule)
                    child_item.setFlags(Qt.NoItemFlags)
                    # child_item.setCheckState(Qt.Checked)

    def build_child(self, item_perent, child_elements, checkstate, flag):
        childcount = 0
        for text2 in child_elements:
            item_child = QStandardItem(text2)
            item_child.setCheckState(checkstate)
            item_child.setFlags(flag)
            item_perent.setChild(childcount, item_child)
            childcount += 1
        return

    def RelieveModuleBuildtree(self, parent, elements, basemodule):
        module_inform = dict()
        for module in elements:
            module_inform.update({module: {'indexnum': 0}})
            item_module = QStandardItem(module)
            item_module.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
            if module in basemodule:
                item_module.setCheckState(Qt.Checked)
                checkvalue = Qt.Checked
                option = Qt.ItemIsUserCheckable
            else:
                item_module.setCheckState(Qt.Unchecked)
                checkvalue = Qt.Unchecked
                option = Qt.ItemIsUserCheckable | Qt.ItemIsEnabled
            self.build_child(item_module, elements[module], checkvalue, option)
            parent.appendRow(item_module)
            module_inform[module]['indexnum'] = parent.rowCount() - 1
        return module_inform

    def ComboxBoxClick(self, targetcombo):
        directory = targetcombo.currentText()
        if directory is not "":
            self.SetModuleModel.clear()
            self.RelieveModuleModel.clear()
            self.McalFolderHandlingProcedure(directory)
        else:
            self.SetModuleModel.clear()
            self.RelieveModuleModel.clear()
            self.CopyProcessValid = False
        return

    def CopyProcess(self):
        """File copy process"""
        if self.CopyProcessValid is True and self.CopyProcessValid_NoSelect is False:
            # To support Korean language.
            Temp_Module = self.ModuleComboBox.currentText().replace('\\', '/')
            Temp_Smodule = self.SmoduleComboBox.currentText().replace('\\', '/')
            if Temp_Module and Temp_Smodule is not "":
                if not os.path.exists(Temp_Module):
                    os.makedirs(Temp_Module)
                else:
                    if self.UpdateCheckBox.checkState() == Qt.Unchecked:
                        remove_tree(Temp_Module)
                        os.makedirs(Temp_Module)
                if not os.path.exists(Temp_Smodule):
                    os.makedirs(Temp_Smodule)
                else:
                    if self.UpdateCheckBox.checkState() == Qt.Unchecked:
                        remove_tree(Temp_Smodule)
                        os.makedirs(Temp_Smodule)
                copy_mcalmodule(self.refine_result, Temp_Smodule, True)
                copy_mcalmodule(self.module_sort_result, Temp_Module)
                include = self.belong(Temp_Module, Temp_Smodule)
                includelist = self.includepath(
                    Temp_Module, Temp_Smodule, include)
                self.plainTextEdit.clear()
                for k_list in includelist:
                    self.plainTextEdit.appendPlainText(k_list)
            else:
                self.plainTextEdit.setPlainText(
                    "Warning: There are no destination")
        else:
            self.plainTextEdit.setPlainText(
                "Warning: Modules are not configured")
        return

    def includepath(self, firstdir, seconddir, include_inform):
        pathlist = list()
        if include_inform[0] is True:
            if (include_inform[1] == 'BOTH') or (include_inform[1] == 'FIRST'):
                findresult = self._includepathfind(firstdir)
                pathlist.append(findresult)
            elif include_inform[1] == 'SECOND':
                findresult = self._includepathfind(seconddir)
                pathlist.append(findresult)
        else:
            findresult1 = self._includepathfind(firstdir)
            findresult2 = self._includepathfind(seconddir)
            findresult = findresult1 + findresult2
        return findresult

    def _includepathfind(self, dirpath):
        includelist = list()
        delete_path = search('^.*/', dirpath).group()
        for tmp_dir, tmp_folder, tmp_file in os.walk(dirpath):
            tmp_dir = tmp_dir.replace('\\', '/')
            if len(tmp_file):
                for filelist in tmp_file:
                    if match('^.*\.h', filelist):
                        # print(tmp_dir)
                        print(sub(delete_path, '', tmp_dir))
                        print('{}{}{}'.format(
                            '${workspace_loc:/${ProjName}/{TEMPLETE}/', sub(delete_path, '', tmp_dir), '}'))
                        includelist.append(
                            '"${workspace_loc:/${ProjName}/{TEMPLETE}/' + sub(delete_path, '', tmp_dir) + '}"')
                        # '${workspace_loc:/${ProjName}/SourceCode/'+sub(y,'',tmp_dir)+'}'
                        print(filelist)
                        break
        return includelist

    def belong_check(self, firstdir, seconddir):
        if fullmatch(firstdir, seconddir):
            # Exactly match with each other
            return True
        else:
            # Partial match check
            if match(firstdir, seconddir):
                temp_seconddir = sub(firstdir, '', seconddir)
                if match('^/', temp_seconddir):
                    # Partial match
                    # _belong('C:/Testfolder','C:/Testfolder')
                    return True
                else:
                    # _belong('C:/Testfolder','C:/Testfolderadd')
                    return False
            else:
                # Does not match
                return False

    def belong(self, firstdir, seconddir):
        first_include = self.belong_check(firstdir, seconddir)
        second_include = self.belong_check(seconddir, firstdir)
        if (first_include and second_include) is True:
            return (True, 'BOTH')
        elif first_include is True:
            return (True, 'FIRST')
        elif second_include is True:
            return (True, 'SECOND')
        else:
            return (False, 'NONE')

    def McalFolderHandlingProcedure(self, directory):
        SORT_PATH = directory
        QFile.remove(self.TEMP_DATABASE_PATH)
        sort_data = import_data(self.DATABASE_PATH, "SORTING")
        # module_data = import_data(self.DATABASE_PATH, "MODULE")
        bmodule_data = import_data(self.DATABASE_PATH, "BASICMODULE")
        smodule_data = import_data(self.DATABASE_PATH, "SERVICEMODULE")

        displasydata = dict()
        displasydata.update({"MODULEDATA": {
                            "BASICMODULE": bmodule_data, "SERVICEMODULE": smodule_data, "MODULELIST": []}})
        # Generate the module data
        moduledatashow(SORT_PATH, sort_data, displasydata)

        if QFile.exists(self.TEMP_DATABASE_PATH):
            modulelist = import_data(self.TEMP_DATABASE_PATH, "MODULEDATA")
            basemodule = ['BASICMODULE', 'SERVICEMODULE']
            # Remove the basemodule from modulelist
            self.modulecheck(modulelist, basemodule)
            RelieveModuleTreeInform = self.RelieveModuleBuildtree(
                self.RelieveModuleModel, modulelist, basemodule)
            self.RelieveModuleTreeView.setModel(self.RelieveModuleModel)
            self.RelieveModuleTreeView.expandAll()
            self.RelieveModuleTreeView.setHeaderHidden(True)
            self.rebuildtree = self.RebuildtreeInit(modulelist)
            SetModuleTreeInform = self.SetModuleBuildtree(
                self.SetModuleModel, self.rebuildtree)
            self.SetModuleTreeView.setModel(self.SetModuleModel)
            self.SetModuleTreeView.setHeaderHidden(True)
            self.RelieveModuleModel.itemChanged.connect(
                lambda: self.checkboxclick(self.RelieveModuleModel, RelieveModuleTreeInform))
            self.SetModuleModel.itemChanged.connect(
                lambda: self.checkboxclick(self.SetModuleModel, SetModuleTreeInform))
            self.CopyProcessValid = True
            self.plainTextEdit_Install.setPlainText(
                "Installed MCAL model is loaded successfully.")
        else:
            self.SetModuleModel.clear()
            self.RelieveModuleModel.clear()
            self.CopyProcessValid = False
            self.plainTextEdit_Install.setPlainText(
                "Loading failed for Installed MCAL model.")
        return self.CopyProcessValid

    def closeEvent(self, exits):
        """Close the application"""
        exits.accept()


if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    Scopy_Dialog = ImageDialog()
    Scopy_Dialog.show()
    sys.exit(app.exec_())
