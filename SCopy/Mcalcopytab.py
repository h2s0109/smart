# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'Mcalcopytab.ui'
#
# Created by: PyQt5 UI code generator 5.6
#
# WARNING! All changes made in this file will be lost!

from PyQt5 import QtCore, QtGui, QtWidgets

class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.resize(714, 496)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap("Ico/smart.ico"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        Dialog.setWindowIcon(icon)
        self.gridLayout_2 = QtWidgets.QGridLayout(Dialog)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.tabWidget = QtWidgets.QTabWidget(Dialog)
        self.tabWidget.setEnabled(True)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.tabWidget.sizePolicy().hasHeightForWidth())
        self.tabWidget.setSizePolicy(sizePolicy)
        self.tabWidget.setTabShape(QtWidgets.QTabWidget.Triangular)
        self.tabWidget.setUsesScrollButtons(True)
        self.tabWidget.setTabsClosable(False)
        self.tabWidget.setObjectName("tabWidget")
        self.tabSource = QtWidgets.QWidget()
        self.tabSource.setObjectName("tabSource")
        self.gridLayout = QtWidgets.QGridLayout(self.tabSource)
        self.gridLayout.setContentsMargins(0, 0, 0, 0)
        self.gridLayout.setObjectName("gridLayout")
        self.McalgroupBox = QtWidgets.QGroupBox(self.tabSource)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.McalgroupBox.sizePolicy().hasHeightForWidth())
        self.McalgroupBox.setSizePolicy(sizePolicy)
        self.McalgroupBox.setMinimumSize(QtCore.QSize(600, 0))
        self.McalgroupBox.setObjectName("McalgroupBox")
        self.gridLayout_8 = QtWidgets.QGridLayout(self.McalgroupBox)
        self.gridLayout_8.setObjectName("gridLayout_8")
        self.McalComboBox = QtWidgets.QComboBox(self.McalgroupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.McalComboBox.sizePolicy().hasHeightForWidth())
        self.McalComboBox.setSizePolicy(sizePolicy)
        self.McalComboBox.setEditable(True)
        self.McalComboBox.setObjectName("McalComboBox")
        self.gridLayout_8.addWidget(self.McalComboBox, 0, 0, 1, 1)
        self.McalDirButton = QtWidgets.QPushButton(self.McalgroupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.McalDirButton.sizePolicy().hasHeightForWidth())
        self.McalDirButton.setSizePolicy(sizePolicy)
        self.McalDirButton.setObjectName("McalDirButton")
        self.gridLayout_8.addWidget(self.McalDirButton, 0, 1, 1, 1)
        self.gridLayout.addWidget(self.McalgroupBox, 0, 0, 1, 6)
        self.left_tree = QtWidgets.QTreeView(self.tabSource)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Minimum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.left_tree.sizePolicy().hasHeightForWidth())
        self.left_tree.setSizePolicy(sizePolicy)
        self.left_tree.setMinimumSize(QtCore.QSize(0, 300))
        self.left_tree.setObjectName("left_tree")
        self.gridLayout.addWidget(self.left_tree, 1, 1, 1, 1)
        self.right_tree = QtWidgets.QTreeView(self.tabSource)
        self.right_tree.setObjectName("right_tree")
        self.gridLayout.addWidget(self.right_tree, 1, 4, 1, 1)
        self.verticalLayout_3 = QtWidgets.QVBoxLayout()
        self.verticalLayout_3.setObjectName("verticalLayout_3")
        spacerItem = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.verticalLayout_3.addItem(spacerItem)
        self.leftright_button = QtWidgets.QPushButton(self.tabSource)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.leftright_button.sizePolicy().hasHeightForWidth())
        self.leftright_button.setSizePolicy(sizePolicy)
        self.leftright_button.setMinimumSize(QtCore.QSize(70, 0))
        self.leftright_button.setMaximumSize(QtCore.QSize(70, 16777215))
        self.leftright_button.setText("")
        icon1 = QtGui.QIcon()
        icon1.addPixmap(QtGui.QPixmap("Ico/config_add.gif"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.leftright_button.setIcon(icon1)
        self.leftright_button.setObjectName("leftright_button")
        self.verticalLayout_3.addWidget(self.leftright_button)
        self.rightleft_button = QtWidgets.QPushButton(self.tabSource)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.rightleft_button.sizePolicy().hasHeightForWidth())
        self.rightleft_button.setSizePolicy(sizePolicy)
        self.rightleft_button.setMinimumSize(QtCore.QSize(70, 0))
        self.rightleft_button.setMaximumSize(QtCore.QSize(70, 16777215))
        self.rightleft_button.setText("")
        icon2 = QtGui.QIcon()
        icon2.addPixmap(QtGui.QPixmap("Ico/config_delete.gif"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        self.rightleft_button.setIcon(icon2)
        self.rightleft_button.setObjectName("rightleft_button")
        self.verticalLayout_3.addWidget(self.rightleft_button)
        spacerItem1 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.verticalLayout_3.addItem(spacerItem1)
        self.gridLayout.addLayout(self.verticalLayout_3, 1, 2, 1, 2)
        self.progresstxt_source = QtWidgets.QPlainTextEdit(self.tabSource)
        self.progresstxt_source.setObjectName("progresstxt_source")
        self.gridLayout.addWidget(self.progresstxt_source, 2, 1, 1, 4)
        self.tabWidget.addTab(self.tabSource, "")
        self.tabDestination = QtWidgets.QWidget()
        self.tabDestination.setObjectName("tabDestination")
        self.gridLayout_3 = QtWidgets.QGridLayout(self.tabDestination)
        self.gridLayout_3.setContentsMargins(0, 0, 0, 0)
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.DestgroupBox = QtWidgets.QGroupBox(self.tabDestination)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.DestgroupBox.sizePolicy().hasHeightForWidth())
        self.DestgroupBox.setSizePolicy(sizePolicy)
        self.DestgroupBox.setObjectName("DestgroupBox")
        self.verticalLayout_5 = QtWidgets.QVBoxLayout(self.DestgroupBox)
        self.verticalLayout_5.setObjectName("verticalLayout_5")
        self.groupBox = QtWidgets.QGroupBox(self.DestgroupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.groupBox.sizePolicy().hasHeightForWidth())
        self.groupBox.setSizePolicy(sizePolicy)
        self.groupBox.setObjectName("groupBox")
        self.gridLayout_4 = QtWidgets.QGridLayout(self.groupBox)
        self.gridLayout_4.setObjectName("gridLayout_4")
        self.ProjectComboBox = QtWidgets.QComboBox(self.groupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(250)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ProjectComboBox.sizePolicy().hasHeightForWidth())
        self.ProjectComboBox.setSizePolicy(sizePolicy)
        self.ProjectComboBox.setEditable(True)
        self.ProjectComboBox.setObjectName("ProjectComboBox")
        self.gridLayout_4.addWidget(self.ProjectComboBox, 0, 0, 1, 1)
        self.ProjectDirButton = QtWidgets.QPushButton(self.groupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ProjectDirButton.sizePolicy().hasHeightForWidth())
        self.ProjectDirButton.setSizePolicy(sizePolicy)
        self.ProjectDirButton.setObjectName("ProjectDirButton")
        self.gridLayout_4.addWidget(self.ProjectDirButton, 0, 1, 1, 1)
        self.verticalLayout_5.addWidget(self.groupBox)
        self.ModulegroupBox = QtWidgets.QGroupBox(self.DestgroupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ModulegroupBox.sizePolicy().hasHeightForWidth())
        self.ModulegroupBox.setSizePolicy(sizePolicy)
        self.ModulegroupBox.setObjectName("ModulegroupBox")
        self.gridLayout_6 = QtWidgets.QGridLayout(self.ModulegroupBox)
        self.gridLayout_6.setObjectName("gridLayout_6")
        self.ModuleComboBox = QtWidgets.QComboBox(self.ModulegroupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(250)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ModuleComboBox.sizePolicy().hasHeightForWidth())
        self.ModuleComboBox.setSizePolicy(sizePolicy)
        self.ModuleComboBox.setEditable(True)
        self.ModuleComboBox.setObjectName("ModuleComboBox")
        self.gridLayout_6.addWidget(self.ModuleComboBox, 0, 0, 1, 1)
        self.ModuleDirButton = QtWidgets.QPushButton(self.ModulegroupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ModuleDirButton.sizePolicy().hasHeightForWidth())
        self.ModuleDirButton.setSizePolicy(sizePolicy)
        self.ModuleDirButton.setObjectName("ModuleDirButton")
        self.gridLayout_6.addWidget(self.ModuleDirButton, 0, 1, 1, 1)
        self.verticalLayout_5.addWidget(self.ModulegroupBox)
        self.SmodulegroupBox_3 = QtWidgets.QGroupBox(self.DestgroupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SmodulegroupBox_3.sizePolicy().hasHeightForWidth())
        self.SmodulegroupBox_3.setSizePolicy(sizePolicy)
        self.SmodulegroupBox_3.setObjectName("SmodulegroupBox_3")
        self.gridLayout_7 = QtWidgets.QGridLayout(self.SmodulegroupBox_3)
        self.gridLayout_7.setObjectName("gridLayout_7")
        self.SmoduleComboBox = QtWidgets.QComboBox(self.SmodulegroupBox_3)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(250)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SmoduleComboBox.sizePolicy().hasHeightForWidth())
        self.SmoduleComboBox.setSizePolicy(sizePolicy)
        self.SmoduleComboBox.setEditable(True)
        self.SmoduleComboBox.setObjectName("SmoduleComboBox")
        self.gridLayout_7.addWidget(self.SmoduleComboBox, 0, 0, 1, 1)
        self.SmoduleDirButton = QtWidgets.QPushButton(self.SmodulegroupBox_3)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SmoduleDirButton.sizePolicy().hasHeightForWidth())
        self.SmoduleDirButton.setSizePolicy(sizePolicy)
        self.SmoduleDirButton.setObjectName("SmoduleDirButton")
        self.gridLayout_7.addWidget(self.SmoduleDirButton, 0, 1, 1, 1)
        self.verticalLayout_5.addWidget(self.SmodulegroupBox_3)
        self.gridLayout_3.addWidget(self.DestgroupBox, 1, 0, 1, 2)
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setSpacing(6)
        self.horizontalLayout.setObjectName("horizontalLayout")
        spacerItem2 = QtWidgets.QSpacerItem(200, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem2)
        self.CopyButton = QtWidgets.QPushButton(self.tabDestination)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.CopyButton.sizePolicy().hasHeightForWidth())
        self.CopyButton.setSizePolicy(sizePolicy)
        self.CopyButton.setObjectName("CopyButton")
        self.horizontalLayout.addWidget(self.CopyButton)
        spacerItem3 = QtWidgets.QSpacerItem(200, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem3)
        self.gridLayout_3.addLayout(self.horizontalLayout, 3, 0, 1, 2)
        self.progresstxt_dest = QtWidgets.QPlainTextEdit(self.tabDestination)
        self.progresstxt_dest.setObjectName("progresstxt_dest")
        self.gridLayout_3.addWidget(self.progresstxt_dest, 4, 0, 1, 1)
        self.tabWidget.addTab(self.tabDestination, "")
        self.gridLayout_2.addWidget(self.tabWidget, 0, 0, 1, 1)

        self.retranslateUi(Dialog)
        self.tabWidget.setCurrentIndex(1)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "SmartCopy V1.0.0"))
        self.McalgroupBox.setTitle(_translate("Dialog", "MCAL Installed"))
        self.McalDirButton.setText(_translate("Dialog", "Directory"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabSource), _translate("Dialog", "Source"))
        self.DestgroupBox.setTitle(_translate("Dialog", "Destination"))
        self.groupBox.setTitle(_translate("Dialog", "Project"))
        self.ProjectDirButton.setText(_translate("Dialog", "Directory"))
        self.ModulegroupBox.setTitle(_translate("Dialog", "Module"))
        self.ModuleDirButton.setText(_translate("Dialog", "Directory"))
        self.SmodulegroupBox_3.setTitle(_translate("Dialog", "Integration && Irq"))
        self.SmoduleDirButton.setText(_translate("Dialog", "Directory"))
        self.CopyButton.setText(_translate("Dialog", "Copy"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabDestination), _translate("Dialog", "Destination"))


if __name__ == "__main__":
    import sys
    app = QtWidgets.QApplication(sys.argv)
    Dialog = QtWidgets.QDialog()
    ui = Ui_Dialog()
    ui.setupUi(Dialog)
    Dialog.show()
    sys.exit(app.exec_())

