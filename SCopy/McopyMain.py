from McopyQT import Ui_MainWindow
from PyQt5 import QtCore, QtGui, QtWidgets
from UpdateCombo import Class_UpdateCombo
# setExistingDirectory,UpdateRecentOpenFile
from Mcopy import mcal_fastcopy
# configcopystart
from license import licensetime_check
import pathcheck
import os


class ImageDialog(Ui_MainWindow, QtWidgets.QMainWindow, Class_UpdateCombo, mcal_fastcopy):
    def __init__(self):
        super().__init__()
        self.setupUi(self)
        APPMODE = True
        if APPMODE is False:
            userpath = os.getcwd()
        else:
            userpath = pathcheck.windowinstallpathini('Autocopy')
        userpath = os.path.join(userpath, 'Mcal.ini')
        handler = self.create_recent_handler(userpath, 5)
        license = licensetime_check(handler, userpath)
        if license is True:
            self.actionAbout_Mcopy.triggered.connect(self.about)
            self.SourceButton.clicked.connect(
                lambda: self.setExistingDirectory(self.SourceCBox, 'Source'))
            self.DestButton.clicked.connect(lambda: self.setExistingDirectory(
                self.DestCBox, 'Destination'))
            self.CopyButton.clicked.connect(lambda: self.auto_copy(
                self.SourceCBox.currentText(), self.DestCBox.currentText()))
            self.UpdateRecentOpenFile(self.SourceCBox, 'Source')
            self.UpdateRecentOpenFile(self.DestCBox, 'Destination')
        else:
            self.statusBar().showMessage("License is not valid")

    def about(self):
        QtWidgets.QMessageBox.about(self, "mcal_fastcopy",
                                    "<p>This program is created by Sungsu Han<br/>"
                                    "please report a bug or send your opinion:</p>"
                                    "<p><a title='steve.han@infineon.com' href='mailto:steve.han@infineon.com'>steve.han@infineon.com</a></p>")


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    MCopyWindow = ImageDialog()
    MCopyWindow.show()
    sys.exit(app.exec_())
