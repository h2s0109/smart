# -*- coding: utf-8 -*-

# Form implementation generated from reading ui file 'c:\Workspace\newsmart\SCopy\scopy_gui.ui'
#
# Created by: PyQt5 UI code generator 5.13.1
#
# WARNING! All changes made in this file will be lost!


from PyQt5 import QtCore, QtGui, QtWidgets


class Ui_Dialog(object):
    def setupUi(self, Dialog):
        Dialog.setObjectName("Dialog")
        Dialog.setEnabled(True)
        Dialog.resize(714, 496)
        icon = QtGui.QIcon()
        icon.addPixmap(QtGui.QPixmap("Ico/smart.ico"), QtGui.QIcon.Normal, QtGui.QIcon.Off)
        Dialog.setWindowIcon(icon)
        self.gridLayout_11 = QtWidgets.QGridLayout(Dialog)
        self.gridLayout_11.setObjectName("gridLayout_11")
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
        self.gridLayout.setObjectName("gridLayout")
        spacerItem = QtWidgets.QSpacerItem(20, 10, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem, 0, 2, 1, 1)
        self.left_tree = QtWidgets.QTreeView(self.tabSource)
        self.left_tree.setEnabled(True)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.left_tree.sizePolicy().hasHeightForWidth())
        self.left_tree.setSizePolicy(sizePolicy)
        self.left_tree.setMinimumSize(QtCore.QSize(0, 250))
        self.left_tree.setObjectName("left_tree")
        self.gridLayout.addWidget(self.left_tree, 2, 1, 1, 1)
        self.right_tree = QtWidgets.QTreeView(self.tabSource)
        self.right_tree.setMinimumSize(QtCore.QSize(0, 250))
        self.right_tree.setObjectName("right_tree")
        self.gridLayout.addWidget(self.right_tree, 2, 3, 1, 1)
        self.gridLayout_12 = QtWidgets.QGridLayout()
        self.gridLayout_12.setObjectName("gridLayout_12")
        spacerItem1 = QtWidgets.QSpacerItem(20, 30, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout_12.addItem(spacerItem1, 0, 0, 1, 1)
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
        self.gridLayout_12.addWidget(self.leftright_button, 1, 0, 1, 1)
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
        self.gridLayout_12.addWidget(self.rightleft_button, 2, 0, 1, 1)
        spacerItem2 = QtWidgets.QSpacerItem(20, 40, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Expanding)
        self.gridLayout_12.addItem(spacerItem2, 3, 0, 1, 1)
        self.gridLayout.addLayout(self.gridLayout_12, 2, 2, 1, 1)
        self.progresstxt_source = QtWidgets.QPlainTextEdit(self.tabSource)
        self.progresstxt_source.setObjectName("progresstxt_source")
        self.gridLayout.addWidget(self.progresstxt_source, 3, 1, 1, 3)
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
        self.McalDirButton = QtWidgets.QPushButton(self.McalgroupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.McalDirButton.sizePolicy().hasHeightForWidth())
        self.McalDirButton.setSizePolicy(sizePolicy)
        self.McalDirButton.setObjectName("McalDirButton")
        self.gridLayout_8.addWidget(self.McalDirButton, 0, 1, 1, 1)
        self.McalComboBox = QtWidgets.QComboBox(self.McalgroupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.McalComboBox.sizePolicy().hasHeightForWidth())
        self.McalComboBox.setSizePolicy(sizePolicy)
        self.McalComboBox.setEditable(True)
        self.McalComboBox.setObjectName("McalComboBox")
        self.gridLayout_8.addWidget(self.McalComboBox, 0, 0, 1, 1)
        self.gridLayout.addWidget(self.McalgroupBox, 1, 1, 1, 3)
        spacerItem3 = QtWidgets.QSpacerItem(10, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem3, 1, 4, 3, 1)
        spacerItem4 = QtWidgets.QSpacerItem(10, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout.addItem(spacerItem4, 1, 0, 3, 1)
        self.tabWidget.addTab(self.tabSource, "")
        self.tabDestination = QtWidgets.QWidget()
        self.tabDestination.setObjectName("tabDestination")
        self.gridLayout_3 = QtWidgets.QGridLayout(self.tabDestination)
        self.gridLayout_3.setObjectName("gridLayout_3")
        self.horizontalLayout = QtWidgets.QHBoxLayout()
        self.horizontalLayout.setSpacing(6)
        self.horizontalLayout.setObjectName("horizontalLayout")
        spacerItem5 = QtWidgets.QSpacerItem(200, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem5)
        self.CopyButton = QtWidgets.QPushButton(self.tabDestination)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.CopyButton.sizePolicy().hasHeightForWidth())
        self.CopyButton.setSizePolicy(sizePolicy)
        self.CopyButton.setObjectName("CopyButton")
        self.horizontalLayout.addWidget(self.CopyButton)
        spacerItem6 = QtWidgets.QSpacerItem(200, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout.addItem(spacerItem6)
        self.gridLayout_3.addLayout(self.horizontalLayout, 2, 1, 1, 2)
        self.progresstxt_dest = QtWidgets.QPlainTextEdit(self.tabDestination)
        self.progresstxt_dest.setObjectName("progresstxt_dest")
        self.gridLayout_3.addWidget(self.progresstxt_dest, 3, 1, 1, 2)
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
        self.gridLayout_4.addWidget(self.ProjectComboBox, 0, 1, 1, 1)
        self.ProjectDirButton = QtWidgets.QPushButton(self.groupBox)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ProjectDirButton.sizePolicy().hasHeightForWidth())
        self.ProjectDirButton.setSizePolicy(sizePolicy)
        self.ProjectDirButton.setObjectName("ProjectDirButton")
        self.gridLayout_4.addWidget(self.ProjectDirButton, 0, 2, 1, 1)
        self.PorjectCheckBox = QtWidgets.QCheckBox(self.groupBox)
        self.PorjectCheckBox.setStatusTip("")
        self.PorjectCheckBox.setChecked(True)
        self.PorjectCheckBox.setObjectName("PorjectCheckBox")
        self.gridLayout_4.addWidget(self.PorjectCheckBox, 0, 0, 1, 1)
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
        self.SrvComboBox = QtWidgets.QComboBox(self.SmodulegroupBox_3)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(250)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SrvComboBox.sizePolicy().hasHeightForWidth())
        self.SrvComboBox.setSizePolicy(sizePolicy)
        self.SrvComboBox.setEditable(True)
        self.SrvComboBox.setObjectName("SrvComboBox")
        self.gridLayout_7.addWidget(self.SrvComboBox, 0, 0, 1, 1)
        self.SmoduleDirButton = QtWidgets.QPushButton(self.SmodulegroupBox_3)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SmoduleDirButton.sizePolicy().hasHeightForWidth())
        self.SmoduleDirButton.setSizePolicy(sizePolicy)
        self.SmoduleDirButton.setObjectName("SmoduleDirButton")
        self.gridLayout_7.addWidget(self.SmoduleDirButton, 0, 1, 1, 1)
        self.verticalLayout_5.addWidget(self.SmodulegroupBox_3)
        self.gridLayout_3.addWidget(self.DestgroupBox, 1, 1, 1, 1)
        spacerItem7 = QtWidgets.QSpacerItem(20, 10, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_3.addItem(spacerItem7, 0, 1, 1, 1)
        spacerItem8 = QtWidgets.QSpacerItem(10, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_3.addItem(spacerItem8, 0, 3, 4, 1)
        spacerItem9 = QtWidgets.QSpacerItem(10, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_3.addItem(spacerItem9, 1, 0, 3, 1)
        self.tabWidget.addTab(self.tabDestination, "")
        self.tabClock = QtWidgets.QWidget()
        self.tabClock.setObjectName("tabClock")
        self.gridLayout_2 = QtWidgets.QGridLayout(self.tabClock)
        self.gridLayout_2.setObjectName("gridLayout_2")
        self.label_pic = QtWidgets.QLabel(self.tabClock)
        self.label_pic.setEnabled(True)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.label_pic.sizePolicy().hasHeightForWidth())
        self.label_pic.setSizePolicy(sizePolicy)
        self.label_pic.setMaximumSize(QtCore.QSize(100, 100))
        self.label_pic.setText("")
        self.label_pic.setPixmap(QtGui.QPixmap("Ico/clock.jpg"))
        self.label_pic.setScaledContents(True)
        self.label_pic.setObjectName("label_pic")
        self.gridLayout_2.addWidget(self.label_pic, 1, 1, 1, 1)
        self.DestgroupBox_2 = QtWidgets.QGroupBox(self.tabClock)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Maximum)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.DestgroupBox_2.sizePolicy().hasHeightForWidth())
        self.DestgroupBox_2.setSizePolicy(sizePolicy)
        self.DestgroupBox_2.setObjectName("DestgroupBox_2")
        self.gridLayout_5 = QtWidgets.QGridLayout(self.DestgroupBox_2)
        self.gridLayout_5.setObjectName("gridLayout_5")
        self.SmodulegroupBox_4 = QtWidgets.QGroupBox(self.DestgroupBox_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.SmodulegroupBox_4.sizePolicy().hasHeightForWidth())
        self.SmodulegroupBox_4.setSizePolicy(sizePolicy)
        self.SmodulegroupBox_4.setObjectName("SmodulegroupBox_4")
        self.gridLayout_10 = QtWidgets.QGridLayout(self.SmodulegroupBox_4)
        self.gridLayout_10.setObjectName("gridLayout_10")
        self.McuXdm_DirButton = QtWidgets.QPushButton(self.SmodulegroupBox_4)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.McuXdm_DirButton.sizePolicy().hasHeightForWidth())
        self.McuXdm_DirButton.setSizePolicy(sizePolicy)
        self.McuXdm_DirButton.setObjectName("McuXdm_DirButton")
        self.gridLayout_10.addWidget(self.McuXdm_DirButton, 0, 1, 1, 1)
        self.McuXdmComboBox = QtWidgets.QComboBox(self.SmodulegroupBox_4)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(250)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.McuXdmComboBox.sizePolicy().hasHeightForWidth())
        self.McuXdmComboBox.setSizePolicy(sizePolicy)
        self.McuXdmComboBox.setEditable(True)
        self.McuXdmComboBox.setObjectName("McuXdmComboBox")
        self.gridLayout_10.addWidget(self.McuXdmComboBox, 0, 0, 1, 1)
        self.gridLayout_5.addWidget(self.SmodulegroupBox_4, 1, 0, 1, 1)
        self.ModulegroupBox_2 = QtWidgets.QGroupBox(self.DestgroupBox_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ModulegroupBox_2.sizePolicy().hasHeightForWidth())
        self.ModulegroupBox_2.setSizePolicy(sizePolicy)
        self.ModulegroupBox_2.setObjectName("ModulegroupBox_2")
        self.gridLayout_9 = QtWidgets.QGridLayout(self.ModulegroupBox_2)
        self.gridLayout_9.setObjectName("gridLayout_9")
        self.ClockXL_DirButton = QtWidgets.QPushButton(self.ModulegroupBox_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Maximum, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ClockXL_DirButton.sizePolicy().hasHeightForWidth())
        self.ClockXL_DirButton.setSizePolicy(sizePolicy)
        self.ClockXL_DirButton.setObjectName("ClockXL_DirButton")
        self.gridLayout_9.addWidget(self.ClockXL_DirButton, 0, 1, 1, 1)
        self.ClockXLComboBox = QtWidgets.QComboBox(self.ModulegroupBox_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Expanding, QtWidgets.QSizePolicy.Expanding)
        sizePolicy.setHorizontalStretch(250)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ClockXLComboBox.sizePolicy().hasHeightForWidth())
        self.ClockXLComboBox.setSizePolicy(sizePolicy)
        self.ClockXLComboBox.setEditable(True)
        self.ClockXLComboBox.setObjectName("ClockXLComboBox")
        self.gridLayout_9.addWidget(self.ClockXLComboBox, 0, 0, 1, 1)
        self.gridLayout_5.addWidget(self.ModulegroupBox_2, 0, 0, 1, 1)
        self.gridLayout_2.addWidget(self.DestgroupBox_2, 1, 2, 1, 1)
        self.horizontalLayout_2 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_2.setSpacing(6)
        self.horizontalLayout_2.setObjectName("horizontalLayout_2")
        spacerItem10 = QtWidgets.QSpacerItem(200, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem10)
        self.ParsingButton = QtWidgets.QPushButton(self.tabClock)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.ParsingButton.sizePolicy().hasHeightForWidth())
        self.ParsingButton.setSizePolicy(sizePolicy)
        self.ParsingButton.setObjectName("ParsingButton")
        self.horizontalLayout_2.addWidget(self.ParsingButton)
        spacerItem11 = QtWidgets.QSpacerItem(200, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_2.addItem(spacerItem11)
        self.gridLayout_2.addLayout(self.horizontalLayout_2, 2, 1, 1, 2)
        self.Clkprogresstxt = QtWidgets.QPlainTextEdit(self.tabClock)
        self.Clkprogresstxt.setObjectName("Clkprogresstxt")
        self.gridLayout_2.addWidget(self.Clkprogresstxt, 3, 1, 1, 2)
        spacerItem12 = QtWidgets.QSpacerItem(5, 10, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Maximum)
        self.gridLayout_2.addItem(spacerItem12, 0, 1, 1, 2)
        spacerItem13 = QtWidgets.QSpacerItem(10, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_2.addItem(spacerItem13, 0, 3, 4, 1)
        spacerItem14 = QtWidgets.QSpacerItem(10, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_2.addItem(spacerItem14, 0, 0, 4, 1)
        self.tabWidget.addTab(self.tabClock, "")
        self.tabCfgcopy = QtWidgets.QWidget()
        self.tabCfgcopy.setObjectName("tabCfgcopy")
        self.gridLayout_18 = QtWidgets.QGridLayout(self.tabCfgcopy)
        self.gridLayout_18.setObjectName("gridLayout_18")
        spacerItem15 = QtWidgets.QSpacerItem(20, 10, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_18.addItem(spacerItem15, 0, 1, 1, 1)
        spacerItem16 = QtWidgets.QSpacerItem(10, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_18.addItem(spacerItem16, 1, 0, 1, 1)
        self.gridLayout_17 = QtWidgets.QGridLayout()
        self.gridLayout_17.setObjectName("gridLayout_17")
        self.groupBox_2 = QtWidgets.QGroupBox(self.tabCfgcopy)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.groupBox_2.sizePolicy().hasHeightForWidth())
        self.groupBox_2.setSizePolicy(sizePolicy)
        self.groupBox_2.setObjectName("groupBox_2")
        self.gridLayout_13 = QtWidgets.QGridLayout(self.groupBox_2)
        self.gridLayout_13.setObjectName("gridLayout_13")
        self.gridLayout_14 = QtWidgets.QGridLayout()
        self.gridLayout_14.setObjectName("gridLayout_14")
        self.CfgSourceCBox = QtWidgets.QComboBox(self.groupBox_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.CfgSourceCBox.sizePolicy().hasHeightForWidth())
        self.CfgSourceCBox.setSizePolicy(sizePolicy)
        self.CfgSourceCBox.setMinimumSize(QtCore.QSize(550, 23))
        self.CfgSourceCBox.setEditable(True)
        self.CfgSourceCBox.setObjectName("CfgSourceCBox")
        self.gridLayout_14.addWidget(self.CfgSourceCBox, 0, 0, 1, 1)
        self.CfgSourceButton = QtWidgets.QPushButton(self.groupBox_2)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.CfgSourceButton.sizePolicy().hasHeightForWidth())
        self.CfgSourceButton.setSizePolicy(sizePolicy)
        self.CfgSourceButton.setMinimumSize(QtCore.QSize(75, 23))
        self.CfgSourceButton.setObjectName("CfgSourceButton")
        self.gridLayout_14.addWidget(self.CfgSourceButton, 0, 1, 1, 1)
        self.gridLayout_13.addLayout(self.gridLayout_14, 0, 0, 1, 1)
        self.gridLayout_17.addWidget(self.groupBox_2, 0, 0, 1, 1)
        self.groupBox_3 = QtWidgets.QGroupBox(self.tabCfgcopy)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Preferred, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.groupBox_3.sizePolicy().hasHeightForWidth())
        self.groupBox_3.setSizePolicy(sizePolicy)
        self.groupBox_3.setObjectName("groupBox_3")
        self.gridLayout_15 = QtWidgets.QGridLayout(self.groupBox_3)
        self.gridLayout_15.setObjectName("gridLayout_15")
        self.gridLayout_16 = QtWidgets.QGridLayout()
        self.gridLayout_16.setObjectName("gridLayout_16")
        self.CfgDestButton = QtWidgets.QPushButton(self.groupBox_3)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.CfgDestButton.sizePolicy().hasHeightForWidth())
        self.CfgDestButton.setSizePolicy(sizePolicy)
        self.CfgDestButton.setMinimumSize(QtCore.QSize(75, 23))
        self.CfgDestButton.setObjectName("CfgDestButton")
        self.gridLayout_16.addWidget(self.CfgDestButton, 0, 1, 1, 1)
        self.CfgDestCBox = QtWidgets.QComboBox(self.groupBox_3)
        self.CfgDestCBox.setMinimumSize(QtCore.QSize(550, 23))
        self.CfgDestCBox.setEditable(True)
        self.CfgDestCBox.setObjectName("CfgDestCBox")
        self.gridLayout_16.addWidget(self.CfgDestCBox, 0, 0, 1, 1)
        self.gridLayout_15.addLayout(self.gridLayout_16, 0, 0, 1, 1)
        self.gridLayout_17.addWidget(self.groupBox_3, 1, 0, 1, 1)
        self.horizontalLayout_3 = QtWidgets.QHBoxLayout()
        self.horizontalLayout_3.setSpacing(6)
        self.horizontalLayout_3.setObjectName("horizontalLayout_3")
        spacerItem17 = QtWidgets.QSpacerItem(200, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem17)
        self.CfgCopyButton = QtWidgets.QPushButton(self.tabCfgcopy)
        sizePolicy = QtWidgets.QSizePolicy(QtWidgets.QSizePolicy.Fixed, QtWidgets.QSizePolicy.Fixed)
        sizePolicy.setHorizontalStretch(75)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.CfgCopyButton.sizePolicy().hasHeightForWidth())
        self.CfgCopyButton.setSizePolicy(sizePolicy)
        self.CfgCopyButton.setObjectName("CfgCopyButton")
        self.horizontalLayout_3.addWidget(self.CfgCopyButton)
        spacerItem18 = QtWidgets.QSpacerItem(200, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.horizontalLayout_3.addItem(spacerItem18)
        self.gridLayout_17.addLayout(self.horizontalLayout_3, 2, 0, 1, 1)
        self.Cfgprogresstxt = QtWidgets.QPlainTextEdit(self.tabCfgcopy)
        self.Cfgprogresstxt.setObjectName("Cfgprogresstxt")
        self.gridLayout_17.addWidget(self.Cfgprogresstxt, 3, 0, 1, 1)
        self.gridLayout_18.addLayout(self.gridLayout_17, 1, 1, 1, 1)
        spacerItem19 = QtWidgets.QSpacerItem(10, 20, QtWidgets.QSizePolicy.Minimum, QtWidgets.QSizePolicy.Minimum)
        self.gridLayout_18.addItem(spacerItem19, 1, 2, 1, 1)
        self.tabWidget.addTab(self.tabCfgcopy, "")
        self.gridLayout_11.addWidget(self.tabWidget, 0, 1, 1, 1)

        self.retranslateUi(Dialog)
        self.tabWidget.setCurrentIndex(3)
        QtCore.QMetaObject.connectSlotsByName(Dialog)

    def retranslateUi(self, Dialog):
        _translate = QtCore.QCoreApplication.translate
        Dialog.setWindowTitle(_translate("Dialog", "SmartCopy V3.0.0"))
        self.McalgroupBox.setTitle(_translate("Dialog", "MCAL Installed"))
        self.McalDirButton.setText(_translate("Dialog", "Directory"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabSource), _translate("Dialog", "Source"))
        self.CopyButton.setText(_translate("Dialog", "Copy"))
        self.DestgroupBox.setTitle(_translate("Dialog", "Destination"))
        self.groupBox.setTitle(_translate("Dialog", "Compiler \"Include path\" configuration"))
        self.ProjectComboBox.setToolTip(_translate("Dialog", "<html><head/><body><p>The project top folder path</p></body></html>"))
        self.ProjectComboBox.setWhatsThis(_translate("Dialog", "The project top folder path"))
        self.ProjectDirButton.setText(_translate("Dialog", "Directory"))
        self.PorjectCheckBox.setToolTip(_translate("Dialog", "<html><head/><body><p>Include path which is a property of compiler will be configured by smartcopy</p></body></html>"))
        self.PorjectCheckBox.setWhatsThis(_translate("Dialog", "<html><head/><body><p>Include path which is a property of compiler will be configured by smartcopy</p></body></html>"))
        self.PorjectCheckBox.setText(_translate("Dialog", "Enable"))
        self.ModulegroupBox.setTitle(_translate("Dialog", "Module"))
        self.ModuleComboBox.setToolTip(_translate("Dialog", "<html><head/><body><p>The Basic and User module path</p></body></html>"))
        self.ModuleComboBox.setWhatsThis(_translate("Dialog", "The Basic and User module path"))
        self.ModuleDirButton.setToolTip(_translate("Dialog", "<html><head/><body><p>Selected BASIC MODULE, MODULELIST copy path</p></body></html>"))
        self.ModuleDirButton.setText(_translate("Dialog", "Directory"))
        self.SmodulegroupBox_3.setTitle(_translate("Dialog", "Integration && Irq"))
        self.SmoduleDirButton.setToolTip(_translate("Dialog", "<html><head/><body><p>Selected SERVICE MODULE copy path</p></body></html>"))
        self.SmoduleDirButton.setText(_translate("Dialog", "Directory"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabDestination), _translate("Dialog", "Destination"))
        self.DestgroupBox_2.setTitle(_translate("Dialog", "MCU Frequency configuration"))
        self.SmodulegroupBox_4.setTitle(_translate("Dialog", "Mcu.xdm"))
        self.McuXdm_DirButton.setToolTip(_translate("Dialog", "<html><head/><body><p>Selected SERVICE MODULE copy path</p></body></html>"))
        self.McuXdm_DirButton.setText(_translate("Dialog", "Directory"))
        self.ModulegroupBox_2.setTitle(_translate("Dialog", "Clock_Calculator.xls"))
        self.ClockXL_DirButton.setToolTip(_translate("Dialog", "<html><head/><body><p>Selected BASIC MODULE, MODULELIST copy path</p></body></html>"))
        self.ClockXL_DirButton.setText(_translate("Dialog", "Directory"))
        self.ParsingButton.setText(_translate("Dialog", "Parsing"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabClock), _translate("Dialog", "Clock"))
        self.groupBox_2.setTitle(_translate("Dialog", "Generated code location"))
        self.CfgSourceButton.setText(_translate("Dialog", "Location"))
        self.groupBox_3.setTitle(_translate("Dialog", "Destination"))
        self.CfgDestButton.setText(_translate("Dialog", "Location"))
        self.CfgCopyButton.setText(_translate("Dialog", "Copy"))
        self.tabWidget.setTabText(self.tabWidget.indexOf(self.tabCfgcopy), _translate("Dialog", "Cfgcopy"))