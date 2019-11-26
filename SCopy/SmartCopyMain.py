from scopy_gui import Ui_Dialog
from PyQt5.QtGui import QStandardItemModel, QStandardItem 
from PyQt5.QtWidgets import QDialog, QApplication, QMessageBox
from PyQt5.QtCore import Qt, QFile
from PyQt5 import QtGui

from PyQt5.QtWidgets import QTreeWidget, QTreeWidgetItem, QTreeView

import os
from license import licensetime_check
import pathcheck
from UpdateCombo import Class_UpdateCombo
from compiler import Class_comiler_path
from clock import Class_Clock_config
from Treebuild import Class_Treebuild
import sort
import re

from pathlib import Path
import sys

# from PyQt5 import QtCore, QtGui, QtWidgets
# from UpdateCombo import Class_UpdateCombo
# setExistingDirectory,UpdateRecentOpenFile
from Mcopy import mcal_fastcopy
# configcopystart
# from license import licensetime_check
# import pathcheck
# import os


class ImageDialog(QDialog, Ui_Dialog, Class_UpdateCombo, Class_comiler_path, Class_Clock_config, Class_Treebuild,mcal_fastcopy):
    def __init__(self):
        super().__init__()

        # Set up the user interface from Designer
        self.setupUi(self)

        self.left_item_model = QStandardItemModel()       
        self.right_item_model = QStandardItemModel()

        # Module name will be changed at official release.
        # current_dir = os.path.dirname(__file__)        
        self.INSTALLED = False
        # Block the unintended McalComboBox_Hndl execution
        self.path_data_dict = dict()
        self.path_data_dict.update(mcal_install_path = '')
        self.path_data_dict.update(sortkey_path = os.path.join(os.getcwd(),"Database","sort_key.json" ))

        if self.INSTALLED is False:
            self.path_data_dict.update(appdata_path = os.getcwd())
            self.path_data_dict.update(cfg_path = os.getcwd())
        else:
            self.path_data_dict.update(appdata_path = pathcheck.windowinstallpathini('Smartcopy'))
            # self.path_data_dict.update(cfg_path = pathcheck.windowinstallpathini('Autocopy'))

        self.path_data_dict.update(sortkey_result_path = os.path.join(self.path_data_dict['appdata_path'],"Database","data_key.json"))
   
        self.icoPath = "Ico/smart.ico"
        self.copylist = dict()
        self.McalLoadValid = False
        self.allEmpty = True
        self.datapackage = dict()

        # Call the folder list which were opened recently
        ini_path = os.path.join(self.path_data_dict['appdata_path'],'Mcal.ini')
        cfgini_path = os.path.join(self.path_data_dict['appdata_path'],'cfgMcal.ini')
        handler = self.create_recent_handler(ini_path, 5)
        self.create_recent_handler(cfgini_path, 5)
        self.UpdateRecentOpenFile(self.McalComboBox, 'Mcal')
        self.UpdateRecentOpenFile(self.ModuleComboBox, 'Module')
        self.UpdateRecentOpenFile(self.SrvComboBox, 'Smodule')
        self.UpdateRecentOpenFile(self.ProjectComboBox, 'PROJECT')
        self.UpdateRecentOpenFile(self.ClockXLComboBox, 'ClockXl')
        self.UpdateRecentOpenFile(self.McuXdmComboBox, 'McuXdm')
        
        license_check = licensetime_check(handler, ini_path)

        if license_check is True:
            self.McalDirButton.clicked.connect(self.McalDirbutton_Hndl)
            self.ModuleDirButton.clicked.connect(self.ModuleDirButton_Hndl)
            self.SmoduleDirButton.clicked.connect(self.SmoduleDirButton_Hndl)
            self.ProjectDirButton.clicked.connect(self.ProjectDirButton_Hndl)
            self.ClockXL_DirButton.clicked.connect(self.ClockXL_DirButton_Hndl)
            self.McuXdm_DirButton.clicked.connect(self.McuXdm_DirButton_Hndl)
            self.McalComboBox.currentIndexChanged.connect(self.McalComboBox_Hndl)
            self.ModuleComboBox.currentIndexChanged.connect(self.ModuleComboBox_Hndl)
            self.SrvComboBox.currentIndexChanged.connect(self.SrvComboBox_Hndl)
            self.ProjectComboBox.currentIndexChanged.connect(self.ProjectComboBox_Hndl)
            self.leftright_button.clicked.connect(self.LtoR_button_Hndl)
            self.rightleft_button.clicked.connect(self.RtoL_button_Hndl)
            self.right_item_model.itemChanged.connect(self.right_checkbox_Hndl)            
            self.left_item_model.itemChanged.connect(self.left_checkbox_Hndl)
            self.CopyButton.clicked.connect(self.CopyProcess)
            self.ParsingButton.clicked.connect(self.ParsingProcess)

            self.CfgSourceButton.clicked.connect(self.CfgSourceButton_Hndl)
            self.CfgDestButton.clicked.connect(self.CfgDestButton_Hndl)
            self.CfgCopyButton.clicked.connect(self.CfgCopyButton_Hndl)
            self.UpdateRecentOpenFile(self.CfgSourceCBox, 'Source')
            self.UpdateRecentOpenFile(self.CfgDestCBox, 'Destination')
            self.tabWidget.tabBarClicked.connect(self.hello_Hndl)
        else:
            self.progresstxt_source.setPlainText("license is expired")
        # self.Test_McalDirbutton_Hndl()
        return

    def __del__(self):
        return
    def hello_Hndl(self):
        a = self.tabWidget.currentIndex()
        print("current value is", a)
        return
    def CfgSourceButton_Hndl(self):
        self.setExistingDirectory(self.CfgSourceCBox, 'Source')
        return
    def CfgDestButton_Hndl(self):
        self.setExistingDirectory(self.CfgDestCBox, 'Destination')
        return
    def CfgCopyButton_Hndl(self):
        self.auto_copy(self.CfgSourceCBox.currentText(), self.CfgDestCBox.currentText())        
        return

    def Test_McalDirbutton_Hndl(self):
        self.tabWidget.setCurrentIndex(0)
        
        self.McalComboBox.setItemText(0,"C:/D/Git/smart/Test/Mcal_file")
        self.BuildProc()        
        return

    def McalDirbutton_Hndl(self):
        self.McalComboBox.currentIndexChanged.disconnect()
        self.setExistingDirectory(self.McalComboBox, 'Mcal')
        self.BuildProc()
        self.McalComboBox.currentIndexChanged.connect(self.McalComboBox_Hndl)
        return

    def McalComboBox_Hndl(self):
        self.McalComboBox.currentIndexChanged.disconnect()
        self.BuildProc()
        self.setDirectory(self.McalComboBox, 'Mcal')
        self.McalComboBox.currentIndexChanged.connect(self.McalComboBox_Hndl)
        return
    def ModuleComboBox_Hndl(self):
        self.ModuleComboBox.currentIndexChanged.disconnect()
        self.setDirectory(self.ModuleComboBox, 'Module')
        self.ModuleComboBox.currentIndexChanged.connect(self.ModuleComboBox_Hndl)
        return    
    def SrvComboBox_Hndl(self):
        self.SrvComboBox.currentIndexChanged.disconnect()
        self.setDirectory(self.SrvComboBox, 'Smodule')
        self.SrvComboBox.currentIndexChanged.connect(self.SrvComboBox_Hndl)
        return    
    def ProjectComboBox_Hndl(self):
        self.ProjectComboBox.currentIndexChanged.disconnect()
        self.setDirectory(self.ProjectComboBox, 'PROJECT')
        self.ProjectComboBox.currentIndexChanged.connect(self.ProjectComboBox_Hndl)
        return

    def ModuleDirButton_Hndl(self):
        self.ModuleComboBox.currentIndexChanged.disconnect()
        self.setExistingDirectory(self.ModuleComboBox, 'Module')
        self.progresstxt_dest.setPlainText(self.ModuleComboBox.currentText())
        self.ModuleComboBox.currentIndexChanged.connect(self.ModuleComboBox_Hndl)
        return
    def SmoduleDirButton_Hndl(self):
        self.SrvComboBox.currentIndexChanged.disconnect()
        self.setExistingDirectory(self.SrvComboBox, 'Smodule')
        self.progresstxt_dest.setPlainText(self.SrvComboBox.currentText())
        self.SrvComboBox.currentIndexChanged.connect(self.SrvComboBox_Hndl)
        return
    def ProjectDirButton_Hndl(self):
        self.ProjectComboBox.currentIndexChanged.disconnect()
        self.setExistingDirectory(self.ProjectComboBox, 'PROJECT')
        self.progresstxt_dest.setPlainText(self.ProjectComboBox.currentText())
        self.ProjectComboBox.currentIndexChanged.connect(self.ProjectComboBox_Hndl)
        return
    def ClockXL_DirButton_Hndl(self):
        self.setExistingfile(self.ClockXLComboBox, 'ClockXl')                
        return
    def McuXdm_DirButton_Hndl(self):
        self.setExistingfile(self.McuXdmComboBox, 'McuXdm')       
        return
    def BuildProc(self):
        self.right_item_model.clear()
        self.left_item_model.clear()
        self.path_data_dict['mcal_install_path'] = self.McalComboBox.currentText().replace('\\', '/')
        # self.path_data_dict['mcal_install_path'] = "C:/Workspace/Smartcopy/Test/Mcal_file"
        ResultTmp = self.data_key_creation(self.path_data_dict)
        if ResultTmp is True:

            user_module_refined = sort.import_data(self.path_data_dict['sortkey_result_path'], "MODULEDATA")
            #Remove the duplicate data between USER MODULE and BASIC MODULE, SRV MODULE
            user_module_refined['USER_MODULE'] = set(user_module_refined['USER_MODULE'])-(set(user_module_refined['BASIC_MODULE'])|set(user_module_refined['SRV_MODULE']))
            user_module_refined['USER_MODULE'] = sorted(user_module_refined['USER_MODULE'])

            ResultTmp = self.BuildTree(user_module_refined)

            if ResultTmp is True:
                self.McalLoadValid = True
                self.progresstxt_source.setPlainText("Installed MCAL model is loaded successfully.")
                self.progresstxt_source.appendPlainText(self.McalComboBox.currentText())
            else:
                self.McalLoadValid = False
        else:
            self.progresstxt_source.setPlainText("No installed MCAL model.")
            self.McalLoadValid = False
        return

    def data_key_creation(self, DATA_PATH):        
        try:
            #Privious file remove.
            QFile.remove(DATA_PATH['sortkey_result_path'])
            sort_data = sort.import_data(DATA_PATH['sortkey_path'], "GENERAL_SORTING_KEY")            
            bmodule_data = sort.import_data(DATA_PATH['sortkey_path'], "BASIC_MODULE")
            smodule_data = sort.import_data(DATA_PATH['sortkey_path'], "SRV_MODULE")
            smodule_data2 = sort.import_data(DATA_PATH['sortkey_path'], "SRV2_MODULE")
            # smodule_data.update(smodule_data2)
            # data_key.json is created at here.
            data_key_templete = dict()
            data_key_templete["MODULEDATA"]={"BASIC_MODULE": bmodule_data, "SRV_MODULE": smodule_data, "SRV2_MODULE": smodule_data2,"USER_MODULE": []}
            self.datapackage =  data_key_templete["MODULEDATA"]
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

    def BuildTree(self, user_moduletmp):        
        try:
            # self.left_item_model_construct(self.left_item_model, user_moduletmp)
            # self.left_item_construct(user_moduletmp)
            basic_item = self.left_item_construct_special(user_moduletmp,'BASIC_MODULE')
            self.left_item_model.appendRow(basic_item)
            srv_item = self.left_item_construct_special(user_moduletmp,'SRV_MODULE')
            self.left_item_model.appendRow(srv_item)
            srv_item2 = self.left_item_construct_special(user_moduletmp,'SRV2_MODULE')
            self.left_item_model.appendRow(srv_item2)
            user_item = self.left_item_construct(user_moduletmp,'USER_MODULE')
            self.left_item_model.appendRow(user_item)
            self.model_status_eval(self.left_item_model)
            self.left_tree.setModel(self.left_item_model)
            self.left_tree.setHeaderHidden(True)
            self.left_tree.expandAll()

            # self.right_item_model = self.model_Analyzation(self.left_item_model)
            # self.model_status_eval(self.right_item_model)
            # self.right_item_model.itemChanged.connect(self.right_checkbox_Hndl())
            # self.right_tree.setModel(self.right_item_model)
            self.right_tree.setHeaderHidden(True)
            self.right_tree.expandAll()
            BuildProcResult = True
        except:
            BuildProcResult = False
        return BuildProcResult

    def RtoL_button_Hndl(self):
        if self.McalLoadValid is True:
            self.right_item_model = self.model_Analyzation(self.right_item_model, self.copylist)
            self.right_item_model.itemChanged.connect(self.right_checkbox_Hndl())
            checkItemNull = self.model_status_eval(self.right_item_model)
            self.right_tree.setModel(self.right_item_model)
            self.right_tree.expandAll()
            if checkItemNull == True:
                self.allEmpty = True
                self.progresstxt_source.setPlainText("All modules are unselected")
            else:
                self.allEmpty = False                
        else:
            self.progresstxt_source.setPlainText("Module is not yet loaded")      
        return

    def LtoR_button_Hndl(self):
        if self.McalLoadValid is True:
            self.right_item_model = self.model_Analyzation(self.left_item_model)
            self.right_item_model.itemChanged.connect(self.right_checkbox_Hndl())
            self.copylist = self.copylist_Gen(self.right_item_model, self.path_data_dict)
            checkItemNull = self.model_status_eval(self.right_item_model)
            self.right_tree.setModel(self.right_item_model)
            self.right_tree.expandAll()
            if checkItemNull == True:
                self.allEmpty = True
                self.progresstxt_source.setPlainText("All modules are unselected")
            else:
                self.allEmpty = False
                
        else:
            self.progresstxt_source.setPlainText("Modules are not yet loaded")
        return

    def copylist_Gen(self, Sel_Item, path_data):
        mcalpath = path_data['mcal_install_path']
        sortkey_path = path_data['sortkey_path']
        # Seperate the selected module
        Srv_Checked = self.FindChildrenItem(Sel_Item,"SRV_MODULE")
        Srv2_Checked = self.FindChildrenItem(Sel_Item,"SRV2_MODULE")
        Basic_Checked = self.FindChildrenItem(Sel_Item,"BASIC_MODULE")
        Module_Checked = self.FindChildrenItem(Sel_Item,"USER_MODULE")

        general_sorting_key = sort.import_data(sortkey_path, "GENERAL_SORTING_KEY")
        module_sorting_key = sort.import_data(sortkey_path, "MODULE_SORTING_KEY")
        SrvModule_SortKey = sort.Srv_SortKye_Gen(Srv_Checked, module_sorting_key)
        SrvModule_SortKey += sort.Srv_SortKye_Gen(Module_Checked, module_sorting_key)
        SrvModule_SortKey += sort.Srv_SortKye_Gen(Basic_Checked, module_sorting_key)

        Basic_Sort_Res = sort.gen_c_h_dic(mcalpath, general_sorting_key, Basic_Checked)
        Module_Sort_Res = sort.gen_c_h_dic(mcalpath, general_sorting_key, Module_Checked)
        SrvModule_Sort_ResMid = sort.gen_c_h_dic(mcalpath, general_sorting_key, Srv_Checked, True)
        # Remove the unrelated module from SrvModule_Sort_ResMid
        SrvModule_Sort_Res = sort.gen_sort(SrvModule_Sort_ResMid, SrvModule_SortKey)
        
        Copylist = dict()
        Copylist['BASIC_MODULE'] = Basic_Sort_Res
        Copylist['USER_MODULE'] = Module_Sort_Res
        Copylist['SRV_MODULE'] =  SrvModule_Sort_Res

        Srv2Module_Sort_Res = dict()
        for checked in Srv2_Checked:
            moduleanme =  self.datapackage["SRV2_MODULE"][checked]['module_name']
            Srv2Module_SortKey = sort.Srv_SortKye_Gen(Srv2_Checked, module_sorting_key)
            Srv2Module_Sort_Res = sort.gen_c_h_dic_files(mcalpath, general_sorting_key, moduleanme, Srv2Module_SortKey)
            Srv2Module_Sort_Res[checked] = Srv2Module_Sort_Res.pop(moduleanme)
        Copylist['SRV2_MODULE'] =  Srv2Module_Sort_Res
        return Copylist

    def left_checkbox_Hndl(self):
        self.left_item_model.itemChanged.disconnect()
        self.model_status_eval(self.left_item_model)
        self.left_item_model.itemChanged.connect(self.left_checkbox_Hndl())
        return

    def right_checkbox_Hndl(self):
        self.right_item_model.itemChanged.disconnect() 
        self.model_status_eval(self.right_item_model)
        self.right_item_model.itemChanged.connect(self.right_checkbox_Hndl())
        return

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
        parsingpath['ClockXl'] = self.ClockXLComboBox.currentText().replace('\\', '/')             
        parsingpath['McuXdm'] = self.McuXdmComboBox.currentText().replace('\\', '/')
        
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
            self.show_message_new("Clock Configuration Success","Result",self.icoPath)
        return

    def CopyProcess(self):        
        """File copy process"""
        self.progresstxt_dest.clear()
        if self.allEmpty is False:
            copypath = dict()            
            if self.PorjectCheckBox.checkState() == Qt.Checked:
                copypath['MODULE'] = self.ModuleComboBox.currentText().replace('\\', '/')
                copypath['SRV_MODULE'] = self.SrvComboBox.currentText().replace('\\', '/')           
                copypath['PROJECT'] = self.ProjectComboBox.currentText().replace('\\', '/')
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
                            sort.copy_mcalmodule(self.copylist['SRV_MODULE'], copypath['SRV_MODULE'], True)
                            sort.copy_mcalmodule(self.copylist['SRV2_MODULE'], copypath['SRV_MODULE'], True)
                            sort.copy_mcalmodule(self.copylist['BASIC_MODULE'], copypath['MODULE'])
                            sort.copy_mcalmodule(self.copylist['USER_MODULE'], copypath['MODULE'])
                            includelist = self.Compiler_include2(self.ProjectComboBox.currentText())                
                            import XMLCompiler
                            XMLCompiler.parsing_includeTasking(copypath['PROJECT'], includelist)
                            for k_list in includelist:
                                self.progresstxt_dest.appendPlainText(k_list)
                            self.show_message_new("Copy Success","Result",self.icoPath)
                            self.ProjectComboBox_Hndl()
                            self.SrvComboBox_Hndl()
                            self.ModuleComboBox_Hndl()
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
                copypath['MODULE'] = self.ModuleComboBox.currentText().replace('\\', '/')
                copypath['SRV_MODULE'] = self.SrvComboBox.currentText().replace('\\', '/')                            
                Pathchek_result = [pathcheck.is_pathname_valid(copypath[x]) for x in copypath]
                if not False in Pathchek_result:
                    pathcheck.Copypath_creation(copypath)
                    sort.copy_mcalmodule(self.copylist['SRV_MODULE'], copypath['SRV_MODULE'], True)
                    sort.copy_mcalmodule(self.copylist['SRV2_MODULE'], copypath['SRV_MODULE'], True)
                    sort.copy_mcalmodule(self.copylist['BASIC_MODULE'], copypath['MODULE'])
                    sort.copy_mcalmodule(self.copylist['USER_MODULE'], copypath['MODULE'])
                    includelist = self.Compiler_include(copypath['MODULE'], copypath['SRV_MODULE'])                
                    for k_list in includelist:
                        self.progresstxt_dest.appendPlainText(k_list)
                    self.show_message_new("Copy Success","Result",self.icoPath)
                    self.ProjectComboBox_Hndl()
                    self.SrvComboBox_Hndl()
                    self.ModuleComboBox_Hndl()                    
                else:
                    self.progresstxt_dest.setPlainText(
                        "Warning: The directory path has a problem.")
        else:
            self.progresstxt_dest.setPlainText(
                "Warning: The modules are not configured.")
        return

    def closeEvent(self, exits):
        """Close the application"""
        exits.accept()

    def show_message_new(self,Text, Title, icoPath):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Information)
        msg.setText(Text)
        msg.setWindowTitle(Title)
        msg.setWindowIcon(QtGui.QIcon(icoPath))
        msg.setStandardButtons(QMessageBox.Ok)
        msg.exec_()
        return 

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    Scopy_Dialog = ImageDialog()
    Scopy_Dialog.show()
    sys.exit(app.exec_())