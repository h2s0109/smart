from Mcalcopytab import Ui_Dialog
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

class ImageDialog(QDialog, Ui_Dialog, Class_UpdateCombo, Class_comiler_path, Class_Clock_config, Class_Treebuild):
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
        else:
            self.path_data_dict.update(appdata_path = pathcheck.windowinstallpathini('Smartcopy'))

        self.path_data_dict.update(sortkey_result_path = os.path.join(self.path_data_dict['appdata_path'],"Database","data_key.json"))

        self.copylist = dict()
        self.McalLoadValid = False
        self.NoCopyitem = False

        # Call the folder list which were opened recently
        ini_path = os.path.join(self.path_data_dict['appdata_path'],'Mcal.ini')
        handler = self.create_recent_handler(ini_path, 5)
        self.UpdateRecentOpenFile(self.McalComboBox, 'Mcal')
        self.UpdateRecentOpenFile(self.ModuleComboBox, 'Module')
        self.UpdateRecentOpenFile(self.SrvComboBox, 'Smodule')
        self.UpdateRecentOpenFile(self.ProjectComboBox, 'PROJECT')
        self.UpdateRecentOpenFile(self.ClockXLComboBox, 'ClockXl')
        self.UpdateRecentOpenFile(self.McuXdmComboBox, 'McuXdm')
        
        license_check = licensetime_check(handler, ini_path)

        if license_check is True:
            self.McalDirButton.clicked.connect(lambda: self.McalDirbutton_Hndl())
            self.ModuleDirButton.clicked.connect(lambda: self.ModuleDirButton_Hndl())
            self.SmoduleDirButton.clicked.connect(lambda: self.SmoduleDirButton_Hndl())
            self.ProjectDirButton.clicked.connect(lambda: self.ProjectDirButton_Hndl())
            self.ClockXL_DirButton.clicked.connect(lambda: self.ClockXL_DirButton_Hndl())
            self.McuXdm_DirButton.clicked.connect(lambda: self.McuXdm_DirButton_Hndl())
            self.McalComboBox.currentIndexChanged.connect(lambda: self.McalComboBox_Hndl())
            self.leftright_button.clicked.connect(lambda: self.LtoR_button_Hndl())
            self.rightleft_button.clicked.connect(lambda: self.RtoL_button_Hndl())
            self.right_item_model.itemChanged.connect(lambda: self.right_checkbox_Hndl())            
            self.left_item_model.itemChanged.connect(lambda: self.left_checkbox_Hndl())
            self.CopyButton.clicked.connect(self.CopyProcess)
            self.ParsingButton.clicked.connect(self.ParsingProcess)
        else:
            self.progresstxt_source.setPlainText("license is expired")

        self.Test_McalDirbutton_Hndl()
        
        
    def Test_McalDirbutton_Hndl(self):
        self.tabWidget.setCurrentIndex(0)
        self.McalComboBox.setItemText(0,"C:/Workspace/Smartcopy/Test/Mcal_file")
        self.BuildProc()
        return

    def McalDirbutton_Hndl(self):
        self.McalComboBox.currentIndexChanged.disconnect()
        self.setExistingDirectory(self.McalComboBox, 'Mcal')
        self.BuildProc()
        self.McalComboBox.currentIndexChanged.connect(lambda: self.McalComboBox_Hndl())
        return

    def McalComboBox_Hndl(self):
        self.BuildProc()
        return

    def ModuleDirButton_Hndl(self):
        self.setExistingDirectory(self.ModuleComboBox, 'Module')
        self.progresstxt_dest.setPlainText(self.ModuleComboBox.currentText())
        return
    def SmoduleDirButton_Hndl(self):
        self.setExistingDirectory(self.SrvComboBox, 'Smodule')
        self.progresstxt_dest.setPlainText(self.SrvComboBox.currentText())
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

    def BuildTree(self, user_moduletmp):        
        try:
            self.left_item_model_construct(self.left_item_model, user_moduletmp)
            self.model_status_eval(self.left_item_model)
            self.left_tree.setModel(self.left_item_model)
            self.left_tree.setHeaderHidden(True)
            self.left_tree.expandAll()

            self.right_item_model = self.model_Analyzation(self.left_item_model)
            self.model_status_eval(self.right_item_model)
            self.right_item_model.itemChanged.connect(lambda: self.right_checkbox_Hndl())
            self.right_tree.setModel(self.right_item_model)
            self.right_tree.setHeaderHidden(True)
            self.right_tree.expandAll()
            BuildProcResult = True
        except:
            BuildProcResult = False
        return BuildProcResult

    def RtoL_button_Hndl(self):
        if self.McalLoadValid is True:
            self.right_item_model = self.model_Analyzation(self.right_item_model, self.copylist)
            self.right_item_model.itemChanged.connect(lambda: self.right_checkbox_Hndl())
            checkItemNull = self.tristate_view(self.right_item_model)
            self.right_tree.setModel(self.right_item_model)
            self.right_tree.expandAll()
            checkItemNull = False
            if checkItemNull == True:
                self.NoCopyitem = True
                self.progresstxt_source.setPlainText("All modules are unselected")
        else:
            self.progresstxt_source.setPlainText("Module is not yet loaded")      
        return

    def LtoR_button_Hndl(self):
        if self.McalLoadValid is True:
            self.NoCopyitem = False
            LeftItemSel = self.LeftTreeAnalyze(self.left_item_model)
            self.GenCopylistLeft(LeftItemSel, self.path_data_dict['mcal_install_path'], self.path_data_dict['sortkey_path'], self.copylist)
            
            self.right_item_model = self.model_Analyzation(self.left_item_model)
            self.model_status_eval(self.right_item_model)
            self.right_item_model.itemChanged.connect(lambda: self.right_checkbox_Hndl())
            self.right_tree.setModel(self.right_item_model)
            self.right_tree.expandAll()
        else:
            self.progresstxt_source.setPlainText("Modules are not yet loaded")
        return

    def GenCopylistLeft(self, Sel_Item, mcalpath, sortkey_path, pCopylist):
        # Seperate the selected module
        Srv_Checked  = Sel_Item["SRV_MODULE"]
        Basic_Checked = Sel_Item["BASIC_MODULE"]
        Module_Checked = Sel_Item["USER_MODULE"]

        general_sorting_key = sort.import_data(sortkey_path, "GENERAL_SORTING_KEY")
        module_sorting_key = sort.import_data(sortkey_path, "MODULE_SORTING_KEY")

        Basic_Sort_Res = sort.gen_c_h_dic(mcalpath, general_sorting_key, Basic_Checked)
        Module_Sort_Res = sort.gen_c_h_dic(mcalpath, general_sorting_key, Module_Checked)
        SrvModule_Sort_ResMid = sort.gen_c_h_dic(mcalpath, general_sorting_key, Srv_Checked, True)
        SrvModule_SortKey = sort.Srv_SortKye_Gen(Module_Checked, module_sorting_key)
        SrvModule_SortKey += sort.Srv_SortKye_Gen(Basic_Checked, module_sorting_key)
        # Remove the unrelated module from SrvModule_Sort_ResMid
        SrvModule_Sort_Res = sort.gen_sort(SrvModule_Sort_ResMid, SrvModule_SortKey)

        pCopylist['BASIC_MODULE'] = Basic_Sort_Res
        pCopylist['USER_MODULE'] = Module_Sort_Res
        pCopylist['SRV_MODULE'] =  SrvModule_Sort_Res      
        return

    def left_checkbox_Hndl(self):
        self.left_item_model.itemChanged.disconnect()
        self.model_status_eval(self.left_item_model)
        self.left_item_model.itemChanged.connect(lambda: self.left_checkbox_Hndl())
        return

    def right_checkbox_Hndl(self):
        self.right_item_model.itemChanged.disconnect() 
        self.model_status_eval(self.right_item_model)
        self.tristate_view(self.right_item_model)
        self.right_item_model.itemChanged.connect(lambda: self.right_checkbox_Hndl())
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
            self.show_message_parsing()
        return

    def CopyProcess(self):        
        """File copy process"""
        self.progresstxt_dest.clear()
        if self.NoCopyitem is False:
            copypath = dict()            
            if self.PorjectCheckBox.checkState() == Qt.Checked:
                copypath['module'] = self.ModuleComboBox.currentText().replace('\\', '/')
                copypath['smodule'] = self.SrvComboBox.currentText().replace('\\', '/')           
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
                            sort.copy_mcalmodule(self.copylist['SRV_MODULE'], copypath['smodule'], True)
                            sort.copy_mcalmodule(self.copylist['BASIC_MODULE'], copypath['module'])
                            sort.copy_mcalmodule(self.copylist['USER_MODULE'], copypath['module'])
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
                copypath['module'] = self.ModuleComboBox.currentText().replace('\\', '/')
                copypath['smodule'] = self.SrvComboBox.currentText().replace('\\', '/')                            
                Pathchek_result = [pathcheck.is_pathname_valid(copypath[x]) for x in copypath]
                if not False in Pathchek_result:
                    pathcheck.Copypath_creation(copypath)
                    sort.copy_mcalmodule(self.copylist['SRV_MODULE'], copypath['smodule'], True)
                    sort.copy_mcalmodule(self.copylist['BASIC_MODULE'], copypath['module'])
                    sort.copy_mcalmodule(self.copylist['USER_MODULE'], copypath['module'])
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

    def closeEvent(self, exits):
        """Close the application"""
        exits.accept()
    
    def show_message(self):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Information)
        msg.setText("Copy Success")
        msg.setWindowTitle("Result")
        msg.setWindowIcon(QtGui.QIcon("Ico/smart.ico"))
        msg.setStandardButtons(QMessageBox.Ok)     
        msg.exec_()
        return

    def show_message_parsing(self):
        msg = QMessageBox()
        msg.setIcon(QMessageBox.Information)
        msg.setText("Clock Configuration Success")
        msg.setWindowTitle("Result")
        msg.setWindowIcon(QtGui.QIcon("Ico/smart.ico"))
        msg.setStandardButtons(QMessageBox.Ok)
        msg.exec_()
        return

if __name__ == "__main__":
    import sys
    app = QApplication(sys.argv)
    Scopy_Dialog = ImageDialog()
    Scopy_Dialog.show()
    sys.exit(app.exec_())