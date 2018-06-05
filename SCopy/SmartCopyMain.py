import os
from Mcalcopytab import Ui_Dialog
from PyQt5.QtGui import QStandardItemModel, QStandardItem
from PyQt5.QtWidgets import QDialog, QApplication
from PyQt5.QtCore import Qt, QFile
from distutils.dir_util import remove_tree
from UpdateCombo import Class_UpdateCombo
from compiler import Class_comiler_path
from sort import gen_c_h_dic, copy_mcalmodule, gen_sort, moduledatashow
import sort 
import copy

class ImageDialog(QDialog, Ui_Dialog, Class_UpdateCombo, Class_comiler_path):
    def __init__(self):
        super().__init__()

        # Set up the user interface from Designer
        self.setupUi(self)
        self.leftsideModel = QStandardItemModel()
        self.rightsideModel = QStandardItemModel()
        CurrentDir = os.path.dirname(__file__)
        self.test_value = dict()
        # Module name will be changed at official release.        
        self.data_handling = dict()
        self.data_handling.update(SORTKEY_PATH = os.path.join(CurrentDir,"Database","sort_key.json" ))
        self.data_handling.update(SORTKEYRESULT_PATH = os.path.join(CurrentDir,"Database","data_key.json"))
        self.data_handling.update(MCAL_PATH = '')
        self.module_sort_result = dict()
        self.refine_result = dict()
        self.CopyProcessValid = False
        self.CopyProcessValid_NoSelect = True
        
        # Call the folder list which were opened recently
        self.create_recent_handler('Mcal.ini', 5)
        self.UpdateRecentOpenFile(self.McalComboBox, 'Mcal')
        self.UpdateRecentOpenFile(self.ModuleComboBox, 'Module')
        self.UpdateRecentOpenFile(self.SmoduleComboBox, 'Smodule')

        #data_key_creation is called at here
        self.McalDirButton.clicked.connect(
            lambda: self.setExistingDirectory(self.McalComboBox, 'Mcal', True))
        self.ModuleDirButton.clicked.connect(
            lambda: self.setExistingDirectory(self.ModuleComboBox, 'Module', True))
        self.SmoduleDirButton.clicked.connect(
            lambda: self.setExistingDirectory(self.SmoduleComboBox, 'Smodule',True))

        #data_key_creation is called at here.
        self.McalComboBox.currentIndexChanged.connect(lambda: self.combobox_change(self.McalComboBox))
        self.leftright_button.clicked.connect(lambda:self.left_tree_update(self.leftsideModel, self.rightsideModel))
        self.rightleft_button.clicked.connect(lambda:self.right_tree_update(self.rightsideModel))
        self.CopyButton.clicked.connect(self.CopyProcess)
        
        #UPDATE: 모듈 로딩 되지 않았을때 어떻게 처리?
        self.rightsideModel.itemChanged.connect(lambda: self.rightcheckbox_click(self.rightsideModel, self.righttreeinform))
        self.leftsideModel.itemChanged.connect(lambda: self.leftcheckbox_click(self.leftsideModel, self.lefttreeinform))

        self.righttreeinform = 0
        self.lefttreeinform = 0

    def right_tree_update(self,right_parent):
        if self.CopyProcessValid is True:
            self.progresstxt_source.appendPlainText("Selected item removed")
            rebuildtree = dict()
            for level_1_idx in range(0, right_parent.rowCount()):
                index_basemodule = right_parent.index(level_1_idx, 0)
                level_1_data = right_parent.data(index_basemodule)
                rowCount_child = right_parent.rowCount(index_basemodule)
                listcheck = list()
                level_1_item = right_parent.itemFromIndex(index_basemodule)
                for level_2_idx in range(0,rowCount_child):
                    index_basemodule_child = right_parent.index(level_2_idx, 0, index_basemodule)
                    level_2_item = right_parent.itemFromIndex(index_basemodule_child)
                    level_2_data = right_parent.data(index_basemodule_child)
                    print(level_1_data,level_2_data,rowCount_child,level_2_idx)
                    #if Leve_1 checked whole item will be removed
                    if level_1_item.checkState() == Qt.Unchecked:
                        print(level_1_data,"will be removed")
                        level_1_item.setCheckState(Qt.Checked)
                        level_1_item.setFlags(Qt.ItemIsTristate)                                               
                        for tmplevel_2_idx in range(0,rowCount_child):
                            listcheck.append(tmplevel_2_idx)
                            index_basemodule_child = right_parent.index(tmplevel_2_idx, 0, index_basemodule)
                            tmplevel_2_data = right_parent.data(index_basemodule_child)
                            if tmplevel_2_data in self.module_sort_result:
                                self.module_sort_result.pop(tmplevel_2_data)
                            if tmplevel_2_data in self.refine_result:
                                self.refine_result.pop(tmplevel_2_data)
                        listcheck.sort(reverse=True)
                        rebuildtree.update({index_basemodule:listcheck})
                        break
                    #if Leve_2 checked only selected item wil be removed
                    elif level_2_item.checkState() == Qt.Unchecked:
                        print(level_2_data,"will be removed")                        
                        if level_2_data in self.module_sort_result:
                            self.module_sort_result.pop(level_2_data)
                        if level_2_data in self.refine_result:
                            self.refine_result.pop(level_2_data)
                        listcheck.append(level_2_idx)
                        listcheck.sort(reverse=True)
                        rebuildtree.update({index_basemodule:listcheck})
            self.item_remove(rebuildtree, right_parent)       
            self.tristate_view(right_parent)
        else:
            self.progresstxt_source.setPlainText("Module is not yet loaded")
        return

    def item_remove(self,rebuildtree, right_parent):
        for key in rebuildtree:
            if len(rebuildtree[key]):
                for idx in rebuildtree[key]:
                    right_parent.removeRow(idx,key)
        return

    def tristate_view(self, right_parent):
        parentCount = right_parent.rowCount()
        tempCount = 0            
        for k_num in range(0, parentCount):
            index_basemodule = right_parent.index(k_num, 0)
            if not right_parent.hasChildren(index_basemodule):
                level_1_item2 = right_parent.itemFromIndex(index_basemodule)
                level_1_data2 = right_parent.data(index_basemodule)
                print("Debug",level_1_data2)
                level_1_item2.setCheckState(Qt.Unchecked)
                level_1_item2.setFlags(Qt.ItemIsTristate)                
                tempCount+=1
                # if all module is selected, no more copy process progresses
                if tempCount is parentCount:
                    self.CopyProcessValid_NoSelect = True
                    self.progresstxt_source.appendPlainText("All modules are unselected")
        return

    def left_tree_update(self, left_parent, right_Parent):
        if self.CopyProcessValid is True:
            self.CopyProcessValid_NoSelect = False
            rebuildtree = dict()
            for cnt1 in range(0, left_parent.rowCount()):
                listcheck = list()
                level_1_idx = left_parent.index(cnt1, 0)
                level_1_data = left_parent.data(level_1_idx)                
                level_1_itm = left_parent.itemFromIndex(level_1_idx)
                for cnt2 in range(0, left_parent.rowCount(level_1_idx)):
                    level_2_idx = left_parent.index(cnt2, 0, level_1_idx)
                    item = left_parent.itemFromIndex(level_2_idx)
                    if level_1_itm.checkState() == Qt.Checked:
                        level_2_data = left_parent.data(level_2_idx)
                        listcheck.append(level_2_data)
                    elif item.checkState() == Qt.Checked:
                        level_2_data = left_parent.data(level_2_idx)
                        listcheck.append(level_2_data)
                    print('level_1_data:',level_1_data,'level_2_data:',level_2_data)                 
                rebuildtree[level_1_data] = listcheck
            sort_data = sort.import_data(self.data_handling['SORTKEY_PATH'], "SORTING")
            sorkey_datas = sort.import_data(self.data_handling['SORTKEY_PATH'], "SORTINGKEY")
            smodule_data = rebuildtree["SERVICEMODULE"]
            module_data = rebuildtree["MODULELIST"] + rebuildtree["BASICMODULE"]
            smodule_sort_result = gen_c_h_dic(self.McalComboBox.currentText(), sort_data, smodule_data, True)
            self.module_sort_result = gen_c_h_dic(self.McalComboBox.currentText(), sort_data, module_data)
            self.refine_result = gen_sort(self.module_sort_result, smodule_sort_result, sorkey_datas)
            right_Parent.clear()
            self.RightModuleBuildtree(right_Parent, rebuildtree)
            self.right_tree.expandAll()
        else:
            self.CopyProcessValid_NoSelect = True
            self.progresstxt_source.setPlainText("Modules are not yet loaded")

    def leftcheckbox_click(self, parent, tree_inform):
        for j_basemodule in tree_inform:
            indexnum = tree_inform[j_basemodule]['indexnum']
            index_basemodule = parent.index(indexnum, 0)
            count_basemodule = parent.rowCount(index_basemodule)
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
        return

    def rightcheckbox_click(self, parent, tree_inform):
        self.rightsideModel.itemChanged.disconnect()    
        for j_basemodule in tree_inform:
            indexnum = tree_inform[j_basemodule]['indexnum']
            index_basemodule = parent.index(indexnum, 0)
            count_basemodule = parent.rowCount(index_basemodule)
            count_value = count_basemodule
            item = parent.itemFromIndex(index_basemodule)
            if self.test_value[j_basemodule] == item.checkState():
                if item.checkState() == Qt.Unchecked:
                    for k_num in range(0, count_basemodule):
                        child_index_basemodule = parent.index(k_num, 0, index_basemodule)
                        child_item = parent.itemFromIndex(child_index_basemodule)
                        child_item.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        # child_item.setFlags(Qt.NoItemFlags)
                elif item.checkState() == Qt.Checked:                    
                    for k_num in range(0, count_basemodule):
                        child_index_basemodule = parent.index(k_num, 0, index_basemodule)
                        child_item = parent.itemFromIndex(child_index_basemodule)
                        child_item.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        if child_item.checkState() == Qt.Unchecked:
                            count_value = count_value - 1
                if count_value is 0:
                    print(parent.data(index_basemodule))                           
                    item.setCheckState(Qt.Unchecked)
            else:
                if item.checkState() == Qt.Unchecked:
                    for k_num in range(0, count_basemodule):
                        child_index_basemodule = parent.index(k_num, 0, index_basemodule)
                        child_item = parent.itemFromIndex(child_index_basemodule)
                        child_item.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        child_item.setCheckState(Qt.Unchecked)
                elif item.checkState() == Qt.Checked:
                    for k_num in range(0, count_basemodule):
                        child_index_basemodule = parent.index(k_num, 0, index_basemodule)
                        child_item = parent.itemFromIndex(child_index_basemodule)
                        child_item.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        child_item.setCheckState(Qt.Checked)
            self.test_value[j_basemodule] = item.checkState()
        self.rightsideModel.itemChanged.connect(lambda: self.rightcheckbox_click(self.rightsideModel, self.righttreeinform))
        return    

    def build_child(self, item_perent, child_elements, checkstate, flag):
        childcount = 0
        for text2 in child_elements:
            item_child = QStandardItem(text2)
            item_child.setCheckState(checkstate)
            item_child.setFlags(flag)
            item_perent.setChild(childcount, item_child)
            childcount += 1
        return

    def RightModuleBuildtree(self, parent, elements):
        module_inform = dict()
        for module in elements:
            module_inform[module] = {'indexnum': 0}
            item_module = QStandardItem(module)
            item_module.setFlags(Qt.ItemIsUserCheckable)
            item_module.setCheckState(Qt.Unchecked)
            if len(elements[module]):
                item_module.setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                item_module.setCheckState(Qt.Checked)
                checkvalue = Qt.Checked
                option = Qt.ItemIsUserCheckable | Qt.ItemIsEnabled
                self.build_child(item_module, elements[module], checkvalue, option)
            parent.appendRow(item_module)
            module_inform[module]['indexnum'] = parent.rowCount() - 1            
            self.test_value[module] =  item_module.checkState()
        self.progresstxt_source.appendPlainText("Selected items are inserted")
        return module_inform

    def LeftModuleBuildtree(self, parent, elements, basemodule):
        module_inform = dict()
        for module in elements:
            module_inform[module] = {'indexnum': 0}
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

    def combobox_change(self, combo_name):
        if combo_name.currentText() is not "":
            self.rightsideModel.clear()
            self.leftsideModel.clear()
            self.data_handling['MCAL_PATH'] = combo_name.currentText()
            result = self.data_key_creation(self.data_handling)            
            self.BuildTree(result, self.data_handling['SORTKEYRESULT_PATH'])
        else:
            self.rightsideModel.clear()
            self.leftsideModel.clear()
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
                includelist = self.Compiler_include(Temp_Module, Temp_Smodule)
                self.progresstxt_dest.clear()
                for k_list in includelist:
                    self.progresstxt_dest.appendPlainText(k_list)
            else:
                self.progresstxt_dest.setPlainText(
                    "Warning: There are no destination")
        else:
            self.progresstxt_dest.setPlainText(
                "Warning: Modules are not configured")
        return
    
    def data_key_creation(self, DATA_PATH):
        QFile.remove(DATA_PATH['SORTKEYRESULT_PATH'])
        sort_data = sort.import_data(DATA_PATH['SORTKEY_PATH'], "SORTING")
        # module_data = import_data(DATA_PATH['SORTKEY_PATH'], "MODULE")
        bmodule_data = sort.import_data(DATA_PATH['SORTKEY_PATH'], "BASICMODULE")
        smodule_data = sort.import_data(DATA_PATH['SORTKEY_PATH'], "SERVICEMODULE")

        displasydata = dict()
        displasydata.update({"MODULEDATA": {
                            "BASICMODULE": bmodule_data, "SERVICEMODULE": smodule_data, "MODULELIST": []}})
        # data_key.json is created at here.
        moduledatashow(DATA_PATH['MCAL_PATH'], sort_data, displasydata)
        if QFile.exists(DATA_PATH['SORTKEYRESULT_PATH']):
            data_key_created = True
        else:
            data_key_created = False
        return data_key_created

    def RebuildtreeInit(self, elements):
        rebuildtree = dict()
        for module in elements:            
            rebuildtree[module] = []
        return rebuildtree

    def BuildTree(self, data_key_created, DATA_PATH):
        if data_key_created is True:
            modulelist = sort.import_data(DATA_PATH, "MODULEDATA")
            modulelist['MODULELIST'] = set(modulelist['MODULELIST'])-(set(modulelist['BASICMODULE'])|set(modulelist['SERVICEMODULE']))
            modulelist['MODULELIST'] = sorted(modulelist['MODULELIST'])            
            basemodule = ['BASICMODULE', 'SERVICEMODULE']
            
            self.lefttreeinform = self.LeftModuleBuildtree(self.leftsideModel, modulelist, basemodule)           
            self.left_tree.setModel(self.leftsideModel)            
            self.left_tree.setHeaderHidden(True)            
            self.left_tree.expandAll()
    
            self.righttreeinform = self.RightModuleBuildtree(self.rightsideModel, self.RebuildtreeInit(modulelist))       
            self.right_tree.setModel(self.rightsideModel)
            self.right_tree.setHeaderHidden(True)

            self.progresstxt_source.setPlainText("Installed MCAL model is loaded successfully.")
            self.CopyProcessValid = True
        else:
            self.rightsideModel.clear()
            self.leftsideModel.clear()
            self.progresstxt_source.setPlainText("Loading failed for Installed MCAL model.")
            self.CopyProcessValid = False
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
