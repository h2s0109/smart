from Mcalcopytab import Ui_Dialog

from PyQt5.QtGui import QStandardItemModel, QStandardItem
from PyQt5.QtWidgets import QDialog, QApplication
from PyQt5.QtCore import Qt, QFile

from distutils.dir_util import remove_tree
import os

from UpdateCombo import Class_UpdateCombo
from compiler import Class_comiler_path
import sort
class ImageDialog(QDialog, Ui_Dialog, Class_UpdateCombo, Class_comiler_path):
    def __init__(self):
        super().__init__()

        # Set up the user interface from Designer
        self.setupUi(self)

        self.leftsideModel = QStandardItemModel()
        self.rightsideModel = QStandardItemModel()
        
        self.before_checkstate = dict()

        # Module name will be changed at official release.
        #current_dir = os.path.dirname(__file__)
        current_dir = os.getcwd()

        self.data_handling = dict()
        self.data_handling.update(SORTKEY_PATH = os.path.join(current_dir,"Database","sort_key.json" ))
        self.data_handling.update(SORTKEYRESULT_PATH = os.path.join(current_dir,"Database","data_key.json"))
        self.data_handling.update(MCAL_PATH = '')

        self.copylist = dict()
        self.CopyProcessValid = False
        self.CopyProcessValid_NoSelect = True

        # Call the folder list which were opened recently
        self.create_recent_handler('Mcal.ini', 5)
        self.UpdateRecentOpenFile(self.McalComboBox, 'Mcal')
        self.UpdateRecentOpenFile(self.ModuleComboBox, 'Module')
        self.UpdateRecentOpenFile(self.SmoduleComboBox, 'Smodule')

        self.license = False
        self.licensetime_check()

        if self.license is True:
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
            
            self.righttreeinform = 0
            self.lefttreeinform = 0    
            self.rightsideModel.itemChanged.connect(lambda: self.right_checkbox_click(self.rightsideModel, self.righttreeinform))
            self.leftsideModel.itemChanged.connect(lambda: self.left_checkbox_click(self.leftsideModel, self.lefttreeinform))
        else:
            self.progresstxt_source.setPlainText("license is expired")

    def licensetime_check(self):
        import datetime
        defaultdaydate = datetime.datetime(2018, 1, 23, 00, 00)
        setdate = datetime.datetime(2018, 5, 5, 00, 00)
        todaydate  = datetime.datetime.today()
        readate = self.settings.value('DATE' + '/install')
        if readate is None:
            if todaydate > setdate:
                print("notvalid")
                self.license = False
            else:
                print("valid")
                self.license = True
                self.timeinstall('Mcal.ini', setdate)
            if todaydate < defaultdaydate:
                print("notvalid")
                self.license = False             
        else:
            # todaydate = datetime.datetime(2018, 5, 5, 00, 00)
            # expiredate = datetime.timedelta(days=3)
            if todaydate > readate:
                print("notvalid")
                self.license = False
            else:
                print("valid")
                self.license = True
            if todaydate < defaultdaydate:
                print("Don`t cheat")
                self.license = False
        return

    def tree_inform_setup(self, tree, cnt, *uppderidx):
        treeinform = dict()
        if not uppderidx:
            treeinform['idx'] = tree.index(cnt, 0)
        else:
            treeinform['idx'] = tree.index(cnt, 0, *uppderidx)
        treeinform['item'] = tree.itemFromIndex(treeinform['idx'])
        treeinform['data'] = tree.data(treeinform['idx'])
        treeinform['childcnts'] = tree.rowCount(treeinform['idx'])
        treeinform['row'] = cnt
        return treeinform

    def right_tree_update(self,right_parent):
        if self.CopyProcessValid is True:
            self.progresstxt_source.clear()
            unchecked_item = dict()
            level_1_rowcnts = right_parent.rowCount()
            for level1_cnt in range(0, level_1_rowcnts):                
                uncheck_list = list()                       
                level1 = self.tree_inform_setup(right_parent, level1_cnt)
                #DEBUG:
                print(level1['data'],"here",level1_cnt)
                #if Leve_1 checked whole item will be removed
                if level1['item'].checkState() == Qt.Unchecked:
                    #DEBUG:
                    print(level1['data'],"will be removed")
                    level1['item'].setCheckState(Qt.Checked)
                    level1['item'].setFlags(Qt.ItemIsTristate)                                               
                    for tmplevels_2_cnt in range(0,level1['childcnts']):        
                        templevel2 = self.tree_inform_setup(right_parent, tmplevels_2_cnt, level1['idx'])
                        uncheck_list = self.collect_uncheck_item(templevel2, tmplevels_2_cnt, uncheck_list, self.copylist)
                    unchecked_item[level1['idx']] = uncheck_list
                else:
                    print(level1['data'])                    
                    for level2_cnt in range(0,level1['childcnts']):
                        level2 = self.tree_inform_setup(right_parent, level2_cnt, level1['idx'])
                        #DEBUG:
                        print(level1['data'], level2['data'], level1['childcnts'], level2_cnt)
                        #if Leve_2 checked only selected item wil be removed
                        if level2['item'].checkState() == Qt.Unchecked:
                            #DEBUG:
                            print(level2['data'],"will be removed")   
                            uncheck_list = self.collect_uncheck_item(level2, level2_cnt,  uncheck_list, self.copylist)                     
                            unchecked_item[level1['idx']] = uncheck_list
            self.item_remove(right_parent, unchecked_item)       
            self.tristate_view(right_parent)
        else:
            self.progresstxt_source.setPlainText("Module is not yet loaded")
        return

    def collect_uncheck_item(self, item, cnt, removelist, database):
        for database_item in database:
            if item['data'] in database[database_item]:
                database[database_item].pop(item['data'])
                removelist.append(cnt)
                removelist.sort(reverse=True)
                textremove = item['data'] +" is removed"
                self.progresstxt_source.appendPlainText(textremove)
                return removelist

    def item_remove(self, right_parent, unchecked_item):
        for key in unchecked_item:
            if len(unchecked_item[key]):
                for idx in unchecked_item[key]:
                    right_parent.removeRow(idx,key)
        return

    def tristate_view(self, right_parent):
        parentCount = right_parent.rowCount()
        tempCount = 0            
        for k_num in range(0, parentCount):
            level1 = self.tree_inform_setup(right_parent, k_num)
            if not right_parent.hasChildren(level1['idx']):
                print("Debug",level1['data'])
                level1['item'].setCheckState(Qt.Unchecked)
                level1['item'].setFlags(Qt.ItemIsTristate)                
                tempCount+=1
                # if all module is selected, no more copy process progresses
                if tempCount is parentCount:
                    self.CopyProcessValid_NoSelect = True
                    self.progresstxt_source.appendPlainText("All modules are unselected")
        return

    def left_tree_update(self, left_parent, right_Parent):
        if self.CopyProcessValid is True:
            self.CopyProcessValid_NoSelect = False
            data_selected = dict()
            for cnt1 in range(0, left_parent.rowCount()):                
                level1 = self.tree_inform_setup(left_parent, cnt1)
                level_2_selected = list()
                for cnt2 in range(0, level1['childcnts']):
                    level2 = self.tree_inform_setup(left_parent, cnt2, level1['idx'])      
                    if level1['item'].checkState() | level2['item'].checkState() == Qt.Checked:                        
                        level_2_selected.append(level2['data'])
                    print('level_1_data:',level1['data'],'level_2_data:',level2['data'])                 
                data_selected[level1['data']] = level_2_selected
            
            sort_data = sort.import_data(self.data_handling['SORTKEY_PATH'], "SORTING")
            sorkey_datas = sort.import_data(self.data_handling['SORTKEY_PATH'], "SORTINGKEY")
            smodule_data = data_selected["SERVICEMODULE"]
            module_data = data_selected["MODULELIST"] + data_selected["BASICMODULE"]
            smodule_sort_result = sort.gen_c_h_dic(self.McalComboBox.currentText(), sort_data, smodule_data, True)
            module_sort_result = sort.gen_c_h_dic(self.McalComboBox.currentText(), sort_data, module_data)
            refine_result = sort.gen_sort(module_sort_result, smodule_sort_result, sorkey_datas)

            self.copylist['modulebaic'] = module_sort_result
            self.copylist['service'] =  refine_result
            
            right_Parent.clear()
            self.right_tree_build(right_Parent, data_selected)
            self.right_tree.expandAll()
        else:
            self.CopyProcessValid_NoSelect = True
            self.progresstxt_source.setPlainText("Modules are not yet loaded")

    def left_checkbox_click(self, parent, tree_inform):
        for j_basemodule in tree_inform:
            level1_cnt = tree_inform[j_basemodule]['indexnum']
            level1 = self.tree_inform_setup(parent, level1_cnt)  
            if level1['item'].checkState() == Qt.Unchecked:
                flag = Qt.ItemIsUserCheckable | Qt.ItemIsEnabled                
            elif level1['item'].checkState() == Qt.Checked:                
                flag = Qt.NoItemFlags
            for level2_cnt in range(0, level1['childcnts']):
                level2 = self.tree_inform_setup(parent, level2_cnt, level1['idx']) 
                level2['item'].setFlags(flag)
        return

    def right_checkbox_click(self, parent, tree_inform):
        self.rightsideModel.itemChanged.disconnect()    
        for j_basemodule in tree_inform:
            level1_cnt = tree_inform[j_basemodule]['indexnum']
            level1 = self.tree_inform_setup(parent, level1_cnt)   
            count_value = level1['childcnts']
            if self.before_checkstate[j_basemodule] == level1['item'].checkState():
                if level1['item'].checkState() == Qt.Unchecked:
                    for level2_cnt in range(0, level1['childcnts']):
                        level2 = self.tree_inform_setup(parent, level2_cnt, level1['idx'])                         
                        level2['item'].setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        # child_item.setFlags(Qt.NoItemFlags)
                elif level1['item'].checkState() == Qt.Checked:                    
                    for level2_cnt in range(0, level1['childcnts']):
                        level2 = self.tree_inform_setup(parent, level2_cnt, level1['idx']) 
                        level2['item'].setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        if level2['item'].checkState() == Qt.Unchecked:
                            count_value = count_value - 1
                if count_value is 0:
                    print(level1['data'])
                    level1['item'].setCheckState(Qt.Unchecked)
            else:
                if level1['item'].checkState() == Qt.Unchecked:
                    for level2_cnt in range(0, level1['childcnts']):
                        level2 = self.tree_inform_setup(parent, level2_cnt, level1['idx'])                        
                        level2['item'].setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        level2['item'].setCheckState(Qt.Unchecked)
                elif level1['item'].checkState() == Qt.Checked:
                    for level2_cnt in range(0, level1['childcnts']):
                        level2 = self.tree_inform_setup(parent, level2_cnt, level1['idx'])  
                        level2['item'].setFlags(Qt.ItemIsUserCheckable | Qt.ItemIsEnabled)
                        level2['item'].setCheckState(Qt.Checked)
            self.before_checkstate[j_basemodule] = level1['item'].checkState()
        self.rightsideModel.itemChanged.connect(lambda: self.right_checkbox_click(self.rightsideModel, self.righttreeinform))
        return    

    def right_tree_build_child(self, item_perent, child_elements, checkstate, flag):
        childcount = 0
        for text2 in child_elements:
            text = text2 +" is inserted"
            self.progresstxt_source.appendPlainText(text)
            item_child = QStandardItem(text2)
            item_child.setCheckState(checkstate)
            item_child.setFlags(flag)
            item_perent.setChild(childcount, item_child)
            childcount += 1
        return

    def right_tree_build(self, parent, elements):
        self.progresstxt_source.clear()
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
                self.right_tree_build_child(item_module, elements[module], checkvalue, option)
            parent.appendRow(item_module)
            module_inform[module]['indexnum'] = parent.rowCount() - 1            
            self.before_checkstate[module] =  item_module.checkState()
        return module_inform

    def left_tree_build(self, parent, elements, basemodule):
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
            self.right_tree_build_child(item_module, elements[module], checkvalue, option)
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

    def Copypath_creation(self, copypath):
        if not os.path.exists(copypath):
            os.makedirs(copypath)
        else:
            if self.UpdateCheckBox.checkState() == Qt.Unchecked:
                remove_tree(copypath)
                os.makedirs(copypath)
        return

    def CopyProcess(self):
        """File copy process"""
        self.progresstxt_dest.clear()
        if self.CopyProcessValid is True and self.CopyProcessValid_NoSelect is False:
            # To support Korean language.
            Temp_Module = self.ModuleComboBox.currentText().replace('\\', '/')
            Temp_Smodule = self.SmoduleComboBox.currentText().replace('\\', '/')
            if Temp_Module and Temp_Smodule is not "":                
                self.Copypath_creation(Temp_Module)
                self.Copypath_creation(Temp_Smodule)
                sort.copy_mcalmodule(self.copylist['service'], Temp_Smodule, True)
                sort.copy_mcalmodule(self.copylist['modulebaic'], Temp_Module)

                includelist = self.Compiler_include(Temp_Module, Temp_Smodule)
                
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
        
        # data_key.json is created at here.
        data_key_templete = dict()
        data_key_templete["MODULEDATA"]={"BASICMODULE": bmodule_data, "SERVICEMODULE": smodule_data, "MODULELIST": []}        
        sort.moduledatashow(DATA_PATH['MCAL_PATH'], sort_data, data_key_templete)

        if QFile.exists(DATA_PATH['SORTKEYRESULT_PATH']):
            data_key_created = True
        else:
            data_key_created = False
        return data_key_created

    def right_tree_init(self, elements):
        righttree = dict()
        for module in elements:            
            righttree[module] = []
        return righttree

    def BuildTree(self, data_key_created, DATA_PATH):
        if data_key_created is True:
            modulelist = sort.import_data(DATA_PATH, "MODULEDATA")
            modulelist['MODULELIST'] = set(modulelist['MODULELIST'])-(set(modulelist['BASICMODULE'])|set(modulelist['SERVICEMODULE']))
            modulelist['MODULELIST'] = sorted(modulelist['MODULELIST'])            
            basemodule = ['BASICMODULE', 'SERVICEMODULE']
            
            self.lefttreeinform = self.left_tree_build(self.leftsideModel, modulelist, basemodule)           
            self.left_tree.setModel(self.leftsideModel)            
            self.left_tree.setHeaderHidden(True)            
            self.left_tree.expandAll()
    
            self.righttreeinform = self.right_tree_build(self.rightsideModel, self.right_tree_init(modulelist))       
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
