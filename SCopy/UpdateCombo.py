from PyQt5 import QtCore, QtGui, QtWidgets

__all__ = ["Class_UpdateCombo"]
class Class_UpdateCombo:

    def __init__(self):
        super().__init__()
        self.MaxRecentFiles = 5

    def create_recent_handler(self, hd_name, numrecent):
        self.MaxRecentFiles = numrecent
        self.settings = QtCore.QSettings(
            hd_name, QtCore.QSettings.IniFormat)

    def setExistingDirectory(self, comboboxname, targetcombox, scopy=None):
        """Select the directory and update the combobox"""
        tempfolder = self.settings.value(
            targetcombox + '/RECENTFOLDERLIST', [])
        options = QtWidgets.QFileDialog.DontResolveSymlinks | QtWidgets.QFileDialog.ShowDirsOnly
        if len(tempfolder) and not "":
            open_folder = tempfolder[0]
        else:
            open_folder = QtCore.QDir.currentPath()

        directory = QtWidgets.QFileDialog.getExistingDirectory(self, targetcombox,
                                                               open_folder, options=options)
        if directory is not "":
            if (scopy is None):
                self.UpdateComboBox(comboboxname, directory,
                                    tempfolder, targetcombox)
            elif scopy is True:
                if targetcombox == 'Mcal':
                    if self.McalFolderHandlingProcedure(directory) is True:
                        self.UpdateComboBox(comboboxname, directory, tempfolder, targetcombox)
                elif targetcombox == 'Module' or 'Smodule':
                    self.UpdateComboBox(comboboxname, directory, tempfolder, targetcombox)
                    self.plainTextEdit.setPlainText(comboboxname.currentText())
        return
    
    def UpdateComboBox(self, comboboxname, directory, tempfolder, targetcombox):
        """Update the combobox and save Mcal.ini file"""
        # If there is no same folder name add the folder name
        if comboboxname.findText(directory) == -1:
            comboboxname.addItem(directory)
        comboboxname.setCurrentIndex(comboboxname.findText(directory))
        tempfolder.insert(0, directory)
        # Delete the oldest folder name
        del tempfolder[self.MaxRecentFiles:]
        # Save Mcal.ini
        self.settings.setValue(targetcombox + '/RECENTFOLDERLIST', tempfolder)
        return

    def UpdateRecentOpenFile(self, comboboxname, targetcombox):
        """Show the folder list which has been opened recently
        File lists comes from Mcal.ini file"""
        files = self.settings.value(targetcombox + '/RECENTFOLDERLIST', [])

        numrecentfiles = min(len(files), self.MaxRecentFiles)
        comboboxname.addItem("")
        for i in range(numrecentfiles):
            text = "{}".format(files[i])
            comboboxname.addItem(text)
        return
