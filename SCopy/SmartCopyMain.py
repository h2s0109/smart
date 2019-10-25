from Mcalcopytab import Ui_Dialog
from PyQt5.QtGui import QStandardItemModel, QStandardItem 
from PyQt5.QtWidgets import QDialog, QApplication, QMessageBox
from PyQt5.QtCore import Qt, QFile
from PyQt5 import QtGui 

import os
from license import licensetime_check
import pathcheck
from UpdateCombo import Class_UpdateCombo
from compiler import Class_comiler_path
from clock import Class_Clock_config

import sort
import re

from pathlib import Path
import sys

class ImageDialog(QDialog, Ui_Dialog, Class_UpdateCombo, Class_comiler_path, Class_Clock_config):
    def __init__(self):
        super().__init__()

        # Set up the user interface from Designer
        self.setupUi(self)

        self.leftsideModel = QStandardItemModel()
        self.rightsideModel = QStandardItemModel()
        self.righttreeinform = dict()
        self.lefttreeinform = dict()
        self.ModelDict = {'LT':self.left_tree,'RT':self.right_tree}
        self.ModelDict.update({'LI':self.leftsideModel,'RI':self.rightsideModel})
        self.ModelDict.update({"LTinform":self.lefttreeinform,"RTinform":self.righttreeinform})           
        
        self.before_checkstate = dict()
        # Module name will be changed at official release.
        # current_dir = os.path.dirname(__file__)        
        self.INSTALLED = True
        # Block the unintended McalComboBox_Hndl execution
        self.McalDirbutton_active = False
        self.path_data_dict = dict()
        self.path_data_dict.update(mcal_install_path = '')
        self.path_data_dict.update(sortkey_path = os.path.join(os.getcwd(),"Database","sort_key.json" ))

        if self.INSTALLED is False:
            self.path_data_dict.update(appdata_path = os.getcwd())
        else:
            self.path_data_dict.update(appdata_path = pathcheck.windowinstallpathini('Smartcopy'))

        self.path_data_dict.update(sortkey_result_path = os.path.join(self.path_data_dict['appdata_path'],"Database","data_key.json"))

        self.copylist = dict()
        self.CopyProcessValid = False
        self.CopyProcessValid_NoSelect = True

        # Call the folder list which were opened recently
        ini_path = os.path.join(self.path_data_dict['appdata_path'],'Mcal.ini')
        handler = self.create_recent_handler(ini_path, 5)
        self.UpdateRecentOpenFile(self.McalComboBox, 'Mcal')
        self.UpdateRecentOpenFile(self.ModuleComboBox, 'Module')
        self.UpdateRecentOpenFile(self.SmoduleComboBox, 'Smodule')
        self.UpdateRecentOpenFile(self.ProjectComboBox, 'PROJECT')
        self.UpdateRecentOpenFile(self.ClockXLComboBox, 'ClockXl')
        self.UpdateRecentOpenFile(self.McuXdmComboBox, 'McuXdm')
        
        license_check = licensetime_check(handler, ini_path)

        if license_check is True:
            #data_key_creation is called at here
            self.McalDirButton.clicked.connect(lambda: self.McalDirbutton_Hndl())
            self.ModuleDirButton.clicked.connect(lambda: self.ModuleDirButton_Hndl())
            self.SmoduleDirButton.clicked.connect(lambda: self.SmoduleDirButton_Hndl())
            self.ProjectDirButton.clicked.connect(lambda: self.ProjectDirButton_Hndl())
            self.ClockXL_DirButton.clicked.connect(lambda: self.ClockXL_DirButton_Hndl())
            self.McuXdm_DirButton.clicked.connect(lambda: self.McuXdm_DirButton_Hndl())
            #data_key_creation is called at here.
            # self.McalComboBox.currentIndexChanged.connect(lambda: self.combobox_change(self.McalComboBox))
            self.McalComboBox.currentIndexChanged.connect(lambda: self.McalComboBox_Hndl())
            self.leftright_button.clicked.connect(lambda:self.LtoR_button_Hndl(self.leftsideModel, self.rightsideModel, self.path_data_dict['sortkey_path'], self.copylist))
            self.rightleft_button.clicked.connect(lambda:self.RtoL_button_Hndl(self.rightsideModel, self.progresstxt_source))
            self.CopyButton.clicked.connect(self.CopyProcess)
            self.ParsingButton.clicked.connect(self.ParsingProcess)
            
            self.rightsideModel.itemChanged.connect(lambda: self.right_checkbox_click(self.rightsideModel, self.righttreeinform))
            self.leftsideModel.itemChanged.connect(lambda: self.left_checkbox_click(self.leftsideModel, self.lefttreeinform))
        else:
            self.progresstxt_source.setPlainText("license is expired")

    def McalDirbutton_Hndl(self):
        self.McalDirbutton_active = True
        self.setExistingDirectory(self.McalComboBox, 'Mcal')
        self.BuildProc()
        self.McalDirbutton_active = False
        return

    def McalComboBox_Hndl(self):
        
        if self.McalDirbutton_active is False:
        # McalDirbutton path is connected with McalComboBox index.
        # This procedure only can progress when user sets McalComboBox
           self.BuildProc()
        return

    def ModuleDirButton_Hndl(self):
        self.setExistingDirectory(self.ModuleComboBox, 'Module')
        self.progresstxt_dest.setPlainText(self.ModuleComboBox.currentText())
        return
    def SmoduleDirButton_Hndl(self):
        self.setExistingDirectory(self.SmoduleComboBox, 'Smodule')
        self.progresstxt_dest.setPlainText(self.SmoduleComboBox.currentText())
        return
    def ProjectDirButton_Hndl(self):
        self.setExistingDirectory(self.ProjectComboBox, 'PROJECT')
        self.progresstxt_dest.setPlainText(self.ProjectComboBox.currentText())
        return
    def ClockXL_DirButton_Hndl(self):
        self.setExistingfile(self.ClockXLComboBox, 'ClockXl')                
        return
    def McuXdm_DirButton_Hndl(self):
        self.setExistingfile(self.McuXdmComboBox, 'McuXdm')       
        return
    def BuildProc(self):
        self.rightsideModel.clear()
        self.leftsideModel.clear()
        self.path_data_dict['mcal_install_path'] = self.McalComboBox.currentText().replace('/', '\\')
        ResultTmp = self.data_key_creation(self.path_data_dict)
        if ResultTmp is True:

            user_module_refined = sort.import_data(self.path_data_dict['sortkey_result_path'], "MODULEDATA")
            #Remove the duplicate data between USER MODULE and BASIC MODULE, SRV MODULE
            user_module_refined['USER_MODULE'] = set(user_module_refined['USER_MODULE'])-(set(user_module_refined['BASIC_MODULE'])|set(user_module_refined['SRV_MODULE']))
            user_module_refined['USER_MODULE'] = sorted(user_module_refined['USER_MODULE'])

            ResultTmp = self.BuildTree(user_module_refined, self.ModelDict)

            if ResultTmp is True:
                self.CopyProcessValid = True
                self.progresstxt_source.setPlainText("Installed MCAL model is loaded successfully.")
                self.progresstxt_source.appendPlainText(self.McalComboBox.currentText())
            else:
                self.CopyProcessValid = False
        else:
            self.progresstxt_source.setPlainText("No installed MCAL model.")
            self.CopyProcessValid = False
        return

    def RtoL_button_Hndl(self,right_parent, progress_msg):
        if self.CopyProcessValid is True:
            progress_msg.clear()
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
            progress_msg.setPlainText("Module is not yet loaded")
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
    def collect_uncheck_item(self, item, cnt, removelist, database):
        for database_item in database:
            if item['data'] in database[database_item]:
                database[database_item].pop(item['data'])
                removelist.append(cnt)
                removelist.sort(reverse=True)
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

    def LtoR_button_Hndl(self, pLeft_P, pRight_P, sortkey_path, pCopylist):
        if self.CopyProcessValid is True:
            self.CopyProcessValid_NoSelect = False
            mod_sel = dict()
            for cnt1 in range(0, pLeft_P.rowCount()):                
                level1 = self.tree_inform_setup(pLeft_P, cnt1)
                level_2_selected = list()
                for cnt2 in range(0, level1['childcnts']):
                    level2 = self.tree_inform_setup(pLeft_P, cnt2, level1['idx'])      
                    if level1['item'].checkState() | level2['item'].checkState() == Qt.Checked:                        
                        level_2_selected.append(level2['data'])
                    print('level_1_data:',level1['data'],'level_2_data:',level2['data'])                 
                mod_sel[level1['data']] = level_2_selected
        
            general_sorting_key = sort.import_data(sortkey_path, "GENERAL_SORTING_KEY")
            module_sorting_key = sort.import_data(sortkey_path, "MODULE_SORTING_KEY")
            
            smodule_checked  = mod_sel["SRV_MODULE"]
            module_checked = mod_sel["USER_MODULE"] + mod_sel["BASIC_MODULE"]

            smodule_sort_result = sort.gen_c_h_dic(self.McalComboBox.currentText(), general_sorting_key, smodule_checked, True)
            module_sort_result = sort.gen_c_h_dic(self.McalComboBox.currentText(), general_sorting_key, module_checked)
            smodule_sort_result2 = sort.gen_sort(module_sort_result, smodule_sort_result, module_sorting_key)

            pCopylist['modulebaic'] = module_sort_result
            pCopylist['service'] =  smodule_sort_result2
            
            pRight_P.clear()
            self.right_tree_build(pRight_P, mod_sel)
            self.right_tree.expandAll()
        else:
            self.CopyProcessValid_NoSelect = True
            self.progresstxt_source.setPlainText("Modules are not yet loaded")
        return

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

    def child_tree_build(self, item_perent, child_elements, checkstate, flag):
        childcount = 0
        for childTmp in child_elements:
            item_child = QStandardItem(childTmp)
            item_child.setCheckState(checkstate)
            item_child.setFlags(flag)
            item_perent.setChild(childcount, item_child)
            childcount += 1
        return

    def right_tree_build(self, parent, elements):
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
                self.child_tree_build(item_module, elements[module], checkvalue, option)
            parent.appendRow(item_module)
            module_inform[module]['indexnum'] = parent.rowCount() - 1            
            self.before_checkstate[module] =  item_module.checkState()        
        return module_inform

    def left_tree_build(self, parent, elements):
        basemodule = ['BASIC_MODULE', 'SRV_MODULE']
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
            self.child_tree_build(item_module, elements[module], checkvalue, option)
            parent.appendRow(item_module)
            module_inform[module]['indexnum'] = parent.rowCount() - 1
        return module_inform

    def projecthierarchy(self, copypath2):        
        splitresult = list()     
        projectpath = copypath2.pop('PROJECT')
        projectpath+= '/'
        for tempkey in copypath2:
            tempsplit = re.split(projectpath, copypath2[tempkey])
            tempfullmatch = re.fullmatch('',tempsplit[0])
            splitresult.append(tempfullmatch)
        if None in splitresult:
            #project doesn`t include the paths. or same
            return False
        else:
            #project includes the paths
            return True

    def ParsingProcess(self):
        parsingpath = dict()
        parsingpath['ClockXl'] = self.ClockXLComboBox.currentText()             
        parsingpath['McuXdm'] = self.McuXdmComboBox.currentText()             
        parsingpath['ClockXl'] = parsingpath['ClockXl'].replace('\\', '/')
        parsingpath['McuXdm'] = parsingpath['McuXdm'].replace('\\', '/')
        
        Pathchek_result = [pathcheck.is_pathname_valid(parsingpath[x]) for x in parsingpath]
        for temp_path in parsingpath:
            my_file = Path(parsingpath[temp_path])
            if my_file.is_file():
                Pathchek_result = True
            else:
                Pathchek_result = False
                break

        if Pathchek_result is True:
            clockxl_result = self.clockxl_load(parsingpath['ClockXl'])
            self.parsing_pll(parsingpath['McuXdm'], clockxl_result)
            self.Clkprogresstxt.setPlainText("complete")
            self.show_message_parsing()
        return

    def CopyProcess(self):        
        """File copy process"""
        self.progresstxt_dest.clear()
        if self.CopyProcessValid is True and self.CopyProcessValid_NoSelect is False:
            copypath = dict()            
            if self.PorjectCheckBox.checkState() == Qt.Checked:
                copypath['module'] = self.ModuleComboBox.currentText()
                copypath['smodule'] = self.SmoduleComboBox.currentText()            
                copypath['PROJECT'] = self.ProjectComboBox.currentText()                
                copypath['module'] = copypath['module'].replace('\\', '/')
                copypath['smodule'] = copypath['smodule'].replace('\\', '/')
                copypath['PROJECT'] = copypath['PROJECT'].replace('\\', '/')
                Pathchek_result = [pathcheck.is_pathname_valid(copypath[x]) for x in copypath]
                if not False in Pathchek_result:
                    import copy
                    deepcopypath = copy.deepcopy(copypath)
                    # copypath['PROJECT'] is removed from here.
                    temphierarchy = self.projecthierarchy(deepcopypath)
                    if temphierarchy is True:
                        xmlpath = os.path.join(copypath['PROJECT'],'.cproject')
                        xmlpath = xmlpath.replace('\\', '/')
                        xmlexist = os.path.exists(xmlpath)
                        if xmlexist is True:
                            pathcheck.Copypath_creation(deepcopypath)
                            sort.copy_mcalmodule(self.copylist['service'], copypath['smodule'], True)
                            sort.copy_mcalmodule(self.copylist['modulebaic'], copypath['module'])
                            includelist = self.Compiler_include2(self.ProjectComboBox.currentText())                
                            import XMLCompiler
                            XMLCompiler.parsing_includeTasking(copypath['PROJECT'], includelist)
                            for k_list in includelist:
                                self.progresstxt_dest.appendPlainText(k_list)
                            self.show_message()
                        else:
                            self.progresstxt_dest.setPlainText(
                            "Warning:It can`t find .cproject.")
                    else:
                        self.progresstxt_dest.setPlainText(
                        "Warning: The project path does not contain a path or it contains exactly the same path.")
                        pass                                  
                else:
                    self.progresstxt_dest.setPlainText(
                        "Warning: The directory path has a problem.")                
            elif self.PorjectCheckBox.checkState() == Qt.Unchecked:
                copypath['module'] = self.ModuleComboBox.currentText()
                copypath['smodule'] = self.SmoduleComboBox.currentText()                            
                copypath['module'] = copypath['module'].replace('\\', '/')
                copypath['smodule'] = copypath['smodule'].replace('\\', '/')
                Pathchek_result = [pathcheck.is_pathname_valid(copypath[x]) for x in copypath]
                if not False in Pathchek_result:
                    pathcheck.Copypath_creation(copypath)
                    sort.copy_mcalmodule(self.copylist['service'], copypath['smodule'], True)
                    sort.copy_mcalmodule(self.copylist['modulebaic'], copypath['module'])
                    includelist = self.Compiler_include(copypath['module'], copypath['smodule'])                
                    for k_list in includelist:
                        self.progresstxt_dest.appendPlainText(k_list)
                    self.show_message()
                else:
                    self.progresstxt_dest.setPlainText(
                        "Warning: The directory path has a problem.")
        else:
            self.progresstxt_dest.setPlainText(
                "Warning: The modules are not configured.")
        return
    
    def data_key_creation(self, DATA_PATH):        
        try:
            #Privious file remove.
            QFile.remove(DATA_PATH['sortkey_result_path'])
            sort_data = sort.import_data(DATA_PATH['sortkey_path'], "GENERAL_SORTING_KEY")            
            bmodule_data = sort.import_data(DATA_PATH['sortkey_path'], "BASIC_MODULE")
            smodule_data = sort.import_data(DATA_PATH['sortkey_path'], "SRV_MODULE")
            
            # data_key.json is created at here.
            data_key_templete = dict()
            data_key_templete["MODULEDATA"]={"BASIC_MODULE": bmodule_data, "SRV_MODULE": smodule_data, "USER_MODULE": []}
            if self.INSTALLED is False:
                sort.moduledatashow(DATA_PATH['mcal_install_path'], sort_data, data_key_templete)
            else:
                sort.moduledatashow(DATA_PATH['mcal_install_path'], sort_data, data_key_templete,'Smartcopy')        
            if QFile.exists(DATA_PATH['sortkey_result_path']):
                DataKeyCreated = True
            else:
                DataKeyCreated = False
        except:
            DataKeyCreated = False
        return DataKeyCreated

    def right_tree_init(self, elements):
        righttree = dict()
        for module in elements:            
            righttree[module] = []
        return righttree

    def BuildTree(self, user_moduletmp, model_P):        
        try:           
            model_P['LTinform'] = self.left_tree_build(model_P['LI'], user_moduletmp)
            model_P['LT'].setModel(model_P['LI'])            
            model_P['LT'].setHeaderHidden(True)            
            model_P['LT'].expandAll()
            model_P['RTinform'] = self.right_tree_build(model_P['RI'], self.right_tree_init(user_moduletmp))
            model_P['RT'].setModel(model_P['RI'])
            model_P['RT'].setHeaderHidden(True)
            BuildProcResult = True
        except:
            BuildProcResult = False
        return BuildProcResult

    def closeEvent(self, exits):
        """Close the application"""
        exits.accept()
    
    def show_message(self):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Information)
        msg.setText("Copy Success")
        # msg.setInformativeText("This is additional information")
        msg.setWindowTitle("Result")
        msg.setWindowIcon(QtGui.QIcon("Ico/smart.ico"))
        msg.setStandardButtons(QMessageBox.Ok)     
        retval = msg.exec_()
        return

    def show_message_parsing(self):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Information)
        msg.setText("Clock Configuration Success")
        # msg.setInformativeText("This is additional information")
        msg.setWindowTitle("Result")
        msg.setWindowIcon(QtGui.QIcon("Ico/smart.ico"))
        msg.setStandardButtons(QMessageBox.Ok)     
        retval = msg.exec_()
        return

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    Scopy_Dialog = ImageDialog()
    Scopy_Dialog.show()
    sys.exit(app.exec_())
