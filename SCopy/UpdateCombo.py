from PyQt5 import QtCore, QtGui, QtWidgets
import pathcheck
__all__ = ["Class_UpdateCombo"]


class Class_UpdateCombo:

    def __init__(self):
        super().__init__()
        self.MaxRecentFiles = 5
        return

    def create_recent_handler(self, hd_name, numrecent):
        self.MaxRecentFiles = numrecent
        self.settings = QtCore.QSettings(
            hd_name, QtCore.QSettings.IniFormat)
        return self.settings

    def setExistingDirectory(self, comboboxname, targetcombox):
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
        pathcheck_result = pathcheck.is_pathname_valid(directory)
        self.UpdateComboBox(comboboxname, directory, tempfolder, targetcombox)
        return

    def setDirectory(self, comboboxname, targetcombox):
        tempfolder = self.settings.value(
            targetcombox + '/RECENTFOLDERLIST', [])
        directory = comboboxname.currentText()
        self.UpdateComboBox(comboboxname, directory, tempfolder, targetcombox)
        return

    def setExistingfile(self, comboboxname, targetcombox):
        """Select the file and update the combobox"""
        tempfolder = self.settings.value(
            targetcombox + '/RECENTFOLDERLIST', [])
        options = QtWidgets.QFileDialog.DontResolveSymlinks
        if len(tempfolder) and not "":
            open_folder = tempfolder[0]
        else:
            open_folder = QtCore.QDir.currentPath()
        if targetcombox == 'ClockXl':
            directory = QtWidgets.QFileDialog.getOpenFileName(self, targetcombox,
                                                               open_folder, "xlsm files (*.xlsm)", options=options)
        elif targetcombox == 'McuXdm':
            directory = QtWidgets.QFileDialog.getOpenFileName(self, targetcombox,
                                                               open_folder, "xdm files (*.xdm)", options=options)
        self.UpdateComboBox(
            comboboxname, directory[0], tempfolder, targetcombox)
        return

    def UpdateComboBox(self, comboboxname, directory, tempfolder, targetcombox):
        """Update the combobox and save Mcal.ini file"""
        # If user not type ESC
        if comboboxname.findText(directory) != 0:
        # If there is no same folder name add the folder name        
            if comboboxname.findText(directory) == -1:
                comboboxname.addItem(directory)
                tempfolder.insert(0, directory)
            else:
                if directory in tempfolder:
                    tempfolder.remove(directory)
                tempfolder.insert(0, directory)                
            comboboxname.setCurrentIndex(comboboxname.findText(directory))
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
        # textlist =list()
        for i in range(numrecentfiles):
            text = "{}".format(files[i])
            comboboxname.addItem(text)
            # textlist.append(text)
        # comboboxname.setCurrentIndex(1)
        return
