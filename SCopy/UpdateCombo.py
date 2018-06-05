from PyQt5 import QtCore, QtGui, QtWidgets


class Class_UpdateCombo:

    def __init__(self):
        super().__init__()
        self.MaxRecentFiles = 5
    # UPDATE:Caption argument.

    def create_recent_handler(self, hd_name, numrecent):
        self.MaxRecentFiles = numrecent
        self.settings = QtCore.QSettings(
            hd_name, QtCore.QSettings.IniFormat)

    def setExistingDirectory(self, comboboxname, targetcombox, caption):
        """Select the directory and update the combobox"""
        tempfolder = self.settings.value(
            targetcombox + '/RECENTFOLDERLIST', [])
        options = QtWidgets.QFileDialog.DontResolveSymlinks | QtWidgets.QFileDialog.ShowDirsOnly
        if len(tempfolder) and not "":
            open_folder = tempfolder[0]
        else:
            open_folder = QtCore.QDir.currentPath()
        # UPDATE:Caption argument.
        directory = QtWidgets.QFileDialog.getExistingDirectory(self, caption,
                                                               open_folder, options=options)
        if directory is not "":
            self.UpdateComboBox(comboboxname, directory,
                                tempfolder, targetcombox)
            # UPDATE:Following code lines are should be removed.
            # if targetcombox == 'Mcal':
            #     processresult = self.McalFolderHandlingProcedure(directory)
            #     if processresult is True:
            #         self.UpdateComboBox(comboboxname, directory, tempfolder, targetcombox)
            # elif targetcombox == 'Module':
            #     self.UpdateComboBox(comboboxname, directory, tempfolder, targetcombox)
            #     self.plainTextEdit.setPlainText(self.ModuleComboBox.currentText())
            # elif targetcombox == 'Smodule':
            #     self.UpdateComboBox(comboboxname, directory, tempfolder, targetcombox)
            #     self.plainTextEdit.setPlainText(self.SmoduleComboBox.currentText())
        return

    def setExistingDirectory2(self, comboboxname, targetcombox, caption):
        """Select the directory and update the combobox"""
        tempfolder = self.settings.value(
            targetcombox + '/RECENTFOLDERLIST', [])
        options = QtWidgets.QFileDialog.DontResolveSymlinks | QtWidgets.QFileDialog.ShowDirsOnly
        if len(tempfolder) and not "":
            open_folder = tempfolder[0]
        else:
            open_folder = QtCore.QDir.currentPath()
        directory = QtWidgets.QFileDialog.getExistingDirectory(self, caption,
                                                               open_folder, options=options)
        if directory is not "":
            self.UpdateComboBox(comboboxname, directory,
                                tempfolder, targetcombox)
            if targetcombox == 'Mcal':
                processresult = self.McalFolderHandlingProcedure(directory)
                if processresult is True:
                    self.UpdateComboBox(
                        comboboxname, directory, tempfolder, targetcombox)
            elif targetcombox == 'Module':
                self.UpdateComboBox(comboboxname, directory,
                                    tempfolder, targetcombox)
                self.plainTextEdit.setPlainText(
                    self.ModuleComboBox.currentText())
            elif targetcombox == 'Smodule':
                self.UpdateComboBox(comboboxname, directory,
                                    tempfolder, targetcombox)
                self.plainTextEdit.setPlainText(
                    self.SmoduleComboBox.currentText())
        return

    def UpdateComboBox(self, comboboxname, directory, tempfolder, targetcombox):
        """Update the combobox and save Mcal.ini file"""
        # If there is no same folder name add the folder name
        if comboboxname.findText(directory) == -1:
            comboboxname.addItem(directory)
        comboboxname.setCurrentIndex(comboboxname.findText(directory))
        tempfolder.insert(0, directory)
        # Delete the oldest folder name
        # UPDATE:
        # del tempfolder[ImageDialog.MaxRecentFiles:]
        del tempfolder[self.MaxRecentFiles:]
        # Save Mcal.ini
        self.settings.setValue(targetcombox + '/RECENTFOLDERLIST', tempfolder)
        return

    def UpdateRecentOpenFile(self, comboboxname, targetcombox):
        """Show the folder list which has been opened recently
        File lists comes from Mcal.ini file"""
        files = self.settings.value(targetcombox + '/RECENTFOLDERLIST', [])
        # UPDATE:
        # numrecentfiles = min(len(files), ImageDialog.MaxRecentFiles)
        numrecentfiles = min(len(files), self.MaxRecentFiles)
        comboboxname.addItem("")
        for i in range(numrecentfiles):
            text = "{}".format(files[i])
            comboboxname.addItem(text)
        return
