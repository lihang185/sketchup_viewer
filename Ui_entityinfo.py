# -*- coding: utf-8 -*-

################################################################################
## Form generated from reading UI file 'entityinfo.ui'
##
## Created by: Qt User Interface Compiler version 5.15.2
##
## WARNING! All changes made in this file will be lost when recompiling UI file!
################################################################################

from PySide2.QtCore import *
from PySide2.QtGui import *
from PySide2.QtWidgets import *

import resource_rc

class Ui_EntityInfo(object):
    def setupUi(self, EntityInfo):
        if not EntityInfo.objectName():
            EntityInfo.setObjectName(u"EntityInfo")
        EntityInfo.resize(260, 518)
        self.verticalLayout = QVBoxLayout(EntityInfo)
        self.verticalLayout.setObjectName(u"verticalLayout")
        self.label_8 = QLabel(EntityInfo)
        self.label_8.setObjectName(u"label_8")

        self.verticalLayout.addWidget(self.label_8)

        self.line = QFrame(EntityInfo)
        self.line.setObjectName(u"line")
        self.line.setFrameShape(QFrame.HLine)
        self.line.setFrameShadow(QFrame.Sunken)

        self.verticalLayout.addWidget(self.line)

        self.horizontalLayout_3 = QHBoxLayout()
        self.horizontalLayout_3.setObjectName(u"horizontalLayout_3")
        self.widget = QWidget(EntityInfo)
        self.widget.setObjectName(u"widget")
        sizePolicy = QSizePolicy(QSizePolicy.Preferred, QSizePolicy.Preferred)
        sizePolicy.setHorizontalStretch(0)
        sizePolicy.setVerticalStretch(0)
        sizePolicy.setHeightForWidth(self.widget.sizePolicy().hasHeightForWidth())
        self.widget.setSizePolicy(sizePolicy)
        self.widget.setMinimumSize(QSize(48, 0))
        self.label = QLabel(self.widget)
        self.label.setObjectName(u"label")
        self.label.setGeometry(QRect(0, 0, 48, 48))
        self.label.setFrameShape(QFrame.Box)
        self.label.setFrameShadow(QFrame.Plain)
        self.label.setMidLineWidth(1)
        self.label.setPixmap(QPixmap(u":/toolbar/\u5256\u5207\u9762.svg"))
        self.label.setScaledContents(True)
        self.label.setAlignment(Qt.AlignCenter)
        self.label.setWordWrap(False)
        self.label.setMargin(1)
        self.label.setIndent(-1)
        self.label.setOpenExternalLinks(False)
        self.label.setTextInteractionFlags(Qt.NoTextInteraction)
        self.label_5 = QLabel(self.widget)
        self.label_5.setObjectName(u"label_5")
        self.label_5.setGeometry(QRect(0, 50, 48, 48))
        self.label_5.setFrameShape(QFrame.Box)
        self.label_5.setFrameShadow(QFrame.Plain)
        self.label_5.setMidLineWidth(1)
        self.label_5.setPixmap(QPixmap(u":/toolbar/\u521b\u5efa\u7ec4\u4ef6.svg"))
        self.label_5.setScaledContents(True)
        self.label_5.setAlignment(Qt.AlignCenter)
        self.label_5.setWordWrap(False)
        self.label_5.setMargin(1)
        self.label_5.setIndent(-1)
        self.label_5.setOpenExternalLinks(False)
        self.label_5.setTextInteractionFlags(Qt.NoTextInteraction)

        self.horizontalLayout_3.addWidget(self.widget)

        self.widget_2 = QWidget(EntityInfo)
        self.widget_2.setObjectName(u"widget_2")
        sizePolicy1 = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Preferred)
        sizePolicy1.setHorizontalStretch(0)
        sizePolicy1.setVerticalStretch(0)
        sizePolicy1.setHeightForWidth(self.widget_2.sizePolicy().hasHeightForWidth())
        self.widget_2.setSizePolicy(sizePolicy1)
        self.gridLayout_5 = QGridLayout(self.widget_2)
        self.gridLayout_5.setSpacing(3)
        self.gridLayout_5.setObjectName(u"gridLayout_5")
        self.gridLayout_5.setContentsMargins(0, 0, 0, -1)
        self.verticalSpacer_2 = QSpacerItem(20, 40, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.gridLayout_5.addItem(self.verticalSpacer_2, 4, 0, 1, 1)

        self.horizontalLayout_4 = QHBoxLayout()
        self.horizontalLayout_4.setSpacing(0)
        self.horizontalLayout_4.setObjectName(u"horizontalLayout_4")
        self.label_2 = QLabel(self.widget_2)
        self.label_2.setObjectName(u"label_2")
        self.label_2.setMinimumSize(QSize(0, 0))

        self.horizontalLayout_4.addWidget(self.label_2)

        self.comboBox = QComboBox(self.widget_2)
        self.comboBox.setObjectName(u"comboBox")
        sizePolicy2 = QSizePolicy(QSizePolicy.Expanding, QSizePolicy.Preferred)
        sizePolicy2.setHorizontalStretch(255)
        sizePolicy2.setVerticalStretch(0)
        sizePolicy2.setHeightForWidth(self.comboBox.sizePolicy().hasHeightForWidth())
        self.comboBox.setSizePolicy(sizePolicy2)
        self.comboBox.setMaximumSize(QSize(16777215, 22))

        self.horizontalLayout_4.addWidget(self.comboBox)


        self.gridLayout_5.addLayout(self.horizontalLayout_4, 0, 0, 1, 1)

        self.horizontalLayout_5 = QHBoxLayout()
        self.horizontalLayout_5.setSpacing(0)
        self.horizontalLayout_5.setObjectName(u"horizontalLayout_5")
        self.label_3 = QLabel(self.widget_2)
        self.label_3.setObjectName(u"label_3")
        self.label_3.setMinimumSize(QSize(0, 0))

        self.horizontalLayout_5.addWidget(self.label_3)

        self.lineEdit = QLineEdit(self.widget_2)
        self.lineEdit.setObjectName(u"lineEdit")
        sizePolicy1.setHeightForWidth(self.lineEdit.sizePolicy().hasHeightForWidth())
        self.lineEdit.setSizePolicy(sizePolicy1)

        self.horizontalLayout_5.addWidget(self.lineEdit)


        self.gridLayout_5.addLayout(self.horizontalLayout_5, 1, 0, 1, 1)

        self.horizontalLayout_6 = QHBoxLayout()
        self.horizontalLayout_6.setObjectName(u"horizontalLayout_6")
        self.label_4 = QLabel(self.widget_2)
        self.label_4.setObjectName(u"label_4")
        self.label_4.setMinimumSize(QSize(0, 22))

        self.horizontalLayout_6.addWidget(self.label_4)

        self.widget_4 = QWidget(self.widget_2)
        self.widget_4.setObjectName(u"widget_4")
        sizePolicy1.setHeightForWidth(self.widget_4.sizePolicy().hasHeightForWidth())
        self.widget_4.setSizePolicy(sizePolicy1)
        self.e_pushButton_4 = QPushButton(self.widget_4)
        self.e_pushButton_4.setObjectName(u"e_pushButton_4")
        self.e_pushButton_4.setGeometry(QRect(60, 0, 21, 21))
        self.e_pushButton_4.setMaximumSize(QSize(21, 21))
        icon = QIcon(QIcon.fromTheme(u"QIcon::ThemeIcon::GoHome"))
        self.e_pushButton_4.setIcon(icon)
        self.e_pushButton_2 = QPushButton(self.widget_4)
        self.e_pushButton_2.setObjectName(u"e_pushButton_2")
        self.e_pushButton_2.setGeometry(QRect(20, 0, 21, 21))
        self.e_pushButton_2.setMaximumSize(QSize(21, 21))
        icon1 = QIcon(QIcon.fromTheme(u"QIcon::ThemeIcon::DocumentPrint"))
        self.e_pushButton_2.setIcon(icon1)
        self.e_pushButton_1 = QPushButton(self.widget_4)
        self.e_pushButton_1.setObjectName(u"e_pushButton_1")
        self.e_pushButton_1.setGeometry(QRect(0, 0, 21, 21))
        self.e_pushButton_1.setMaximumSize(QSize(21, 21))
        icon2 = QIcon(QIcon.fromTheme(u"QIcon::ThemeIcon::AddressBookNew"))
        self.e_pushButton_1.setIcon(icon2)
        self.e_pushButton_3 = QPushButton(self.widget_4)
        self.e_pushButton_3.setObjectName(u"e_pushButton_3")
        self.e_pushButton_3.setGeometry(QRect(40, 0, 21, 21))
        self.e_pushButton_3.setMaximumSize(QSize(21, 21))
        icon3 = QIcon(QIcon.fromTheme(u"QIcon::ThemeIcon::DocumentOpenRecent"))
        self.e_pushButton_3.setIcon(icon3)
        self.toolButton = QToolButton(self.widget_4)
        self.toolButton.setObjectName(u"toolButton")
        self.toolButton.setGeometry(QRect(80, 0, 21, 21))
        self.toolButton.setStyleSheet(u"/*QToolButton:checked {\n"
"    background-image: url(:/Images/u_notvisible.svg)\n"
"}*/")
        icon4 = QIcon()
        icon4.addFile(u":/Images/u_notvisible.svg", QSize(), QIcon.Normal, QIcon.Off)
        self.toolButton.setIcon(icon4)
        self.toolButton.setCheckable(True)

        self.horizontalLayout_6.addWidget(self.widget_4)


        self.gridLayout_5.addLayout(self.horizontalLayout_6, 3, 0, 1, 1)

        self.horizontalLayout_7 = QHBoxLayout()
        self.horizontalLayout_7.setSpacing(0)
        self.horizontalLayout_7.setObjectName(u"horizontalLayout_7")
        self.label_9 = QLabel(self.widget_2)
        self.label_9.setObjectName(u"label_9")
        self.label_9.setMinimumSize(QSize(0, 0))

        self.horizontalLayout_7.addWidget(self.label_9)

        self.lineEdit_2 = QLineEdit(self.widget_2)
        self.lineEdit_2.setObjectName(u"lineEdit_2")
        sizePolicy1.setHeightForWidth(self.lineEdit_2.sizePolicy().hasHeightForWidth())
        self.lineEdit_2.setSizePolicy(sizePolicy1)

        self.horizontalLayout_7.addWidget(self.lineEdit_2)


        self.gridLayout_5.addLayout(self.horizontalLayout_7, 2, 0, 1, 1)


        self.horizontalLayout_3.addWidget(self.widget_2)


        self.verticalLayout.addLayout(self.horizontalLayout_3)

        self.verticalSpacer_3 = QSpacerItem(20, 111, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.verticalLayout.addItem(self.verticalSpacer_3)

        self.verticalLayout_2 = QVBoxLayout()
        self.verticalLayout_2.setSpacing(3)
        self.verticalLayout_2.setObjectName(u"verticalLayout_2")
        self.horizontalLayout_8 = QHBoxLayout()
        self.horizontalLayout_8.setObjectName(u"horizontalLayout_8")
        self.label_10 = QLabel(EntityInfo)
        self.label_10.setObjectName(u"label_10")

        self.horizontalLayout_8.addWidget(self.label_10)

        self.horizontalSpacer = QSpacerItem(40, 20, QSizePolicy.Minimum, QSizePolicy.Expanding)

        self.horizontalLayout_8.addItem(self.horizontalSpacer)

        self.e_checkBox_1 = QCheckBox(EntityInfo)
        self.e_checkBox_1.setObjectName(u"e_checkBox_1")
        self.e_checkBox_1.setMinimumSize(QSize(22, 22))
        self.e_checkBox_1.setMaximumSize(QSize(21, 21))
        self.e_checkBox_1.setStyleSheet(u"QCheckBox {\n"
"    /* \u9690\u85cf\u6587\u672c */\n"
"    color: transparent;\n"
"\n"
"    /* \u8bbe\u7f6e\u80cc\u666f\u56fe\u7247 */\n"
"    background-color: white;\n"
"    background-repeat: no-repeat;\n"
"    background-position: center; /* \u56fe\u6807\u5c45\u4e2d\u663e\u793a */\n"
"    background-color: transparent; /* \u80cc\u666f\u900f\u660e */\n"
"\n"
"    /* \u6839\u636e\u9700\u8981\u8c03\u6574\u5927\u5c0f */\n"
"    min-width: 22px;\n"
"    min-height: 22px;\n"
"}\n"
"\n"
"QCheckBox::indicator {\n"
"    /* \u9690\u85cf\u9ed8\u8ba4\u7684\u5706\u5f62\u6307\u793a\u5668 */\n"
"    width: 0px;\n"
"    height: 0px;\n"
"}\n"
"\n"
"QCheckBox:checked {\n"
"    /* \u5f53\u9009\u4e2d\u65f6\u66f4\u6539\u80cc\u666f\u56fe\u7247\u6216\u989c\u8272\uff08\u53ef\u9009\uff09 */\n"
"    background-color: lightblue;\n"
"}")
        self.e_checkBox_1.setIcon(icon2)

        self.horizontalLayout_8.addWidget(self.e_checkBox_1)


        self.verticalLayout_2.addLayout(self.horizontalLayout_8)

        self.line_2 = QFrame(EntityInfo)
        self.line_2.setObjectName(u"line_2")
        self.line_2.setFrameShape(QFrame.VLine)
        self.line_2.setFrameShadow(QFrame.Sunken)

        self.verticalLayout_2.addWidget(self.line_2)

        self.horizontalLayout_14 = QHBoxLayout()
        self.horizontalLayout_14.setSpacing(0)
        self.horizontalLayout_14.setObjectName(u"horizontalLayout_14")
        self.label_16 = QLabel(EntityInfo)
        self.label_16.setObjectName(u"label_16")
        self.label_16.setMinimumSize(QSize(48, 0))

        self.horizontalLayout_14.addWidget(self.label_16)

        self.lineEdit_7 = QLineEdit(EntityInfo)
        self.lineEdit_7.setObjectName(u"lineEdit_7")
        sizePolicy1.setHeightForWidth(self.lineEdit_7.sizePolicy().hasHeightForWidth())
        self.lineEdit_7.setSizePolicy(sizePolicy1)

        self.horizontalLayout_14.addWidget(self.lineEdit_7)


        self.verticalLayout_2.addLayout(self.horizontalLayout_14)

        self.horizontalLayout_13 = QHBoxLayout()
        self.horizontalLayout_13.setSpacing(0)
        self.horizontalLayout_13.setObjectName(u"horizontalLayout_13")
        self.label_15 = QLabel(EntityInfo)
        self.label_15.setObjectName(u"label_15")
        self.label_15.setMinimumSize(QSize(48, 0))

        self.horizontalLayout_13.addWidget(self.label_15)

        self.lineEdit_6 = QLineEdit(EntityInfo)
        self.lineEdit_6.setObjectName(u"lineEdit_6")
        sizePolicy1.setHeightForWidth(self.lineEdit_6.sizePolicy().hasHeightForWidth())
        self.lineEdit_6.setSizePolicy(sizePolicy1)

        self.horizontalLayout_13.addWidget(self.lineEdit_6)


        self.verticalLayout_2.addLayout(self.horizontalLayout_13)

        self.horizontalLayout_12 = QHBoxLayout()
        self.horizontalLayout_12.setSpacing(0)
        self.horizontalLayout_12.setObjectName(u"horizontalLayout_12")
        self.label_14 = QLabel(EntityInfo)
        self.label_14.setObjectName(u"label_14")
        self.label_14.setMinimumSize(QSize(48, 0))

        self.horizontalLayout_12.addWidget(self.label_14)

        self.lineEdit_5 = QLineEdit(EntityInfo)
        self.lineEdit_5.setObjectName(u"lineEdit_5")
        sizePolicy1.setHeightForWidth(self.lineEdit_5.sizePolicy().hasHeightForWidth())
        self.lineEdit_5.setSizePolicy(sizePolicy1)

        self.horizontalLayout_12.addWidget(self.lineEdit_5)


        self.verticalLayout_2.addLayout(self.horizontalLayout_12)

        self.horizontalLayout_11 = QHBoxLayout()
        self.horizontalLayout_11.setSpacing(0)
        self.horizontalLayout_11.setObjectName(u"horizontalLayout_11")
        self.label_13 = QLabel(EntityInfo)
        self.label_13.setObjectName(u"label_13")
        self.label_13.setMinimumSize(QSize(48, 0))

        self.horizontalLayout_11.addWidget(self.label_13)

        self.lineEdit_4 = QLineEdit(EntityInfo)
        self.lineEdit_4.setObjectName(u"lineEdit_4")
        sizePolicy1.setHeightForWidth(self.lineEdit_4.sizePolicy().hasHeightForWidth())
        self.lineEdit_4.setSizePolicy(sizePolicy1)

        self.horizontalLayout_11.addWidget(self.lineEdit_4)


        self.verticalLayout_2.addLayout(self.horizontalLayout_11)

        self.horizontalLayout_9 = QHBoxLayout()
        self.horizontalLayout_9.setSpacing(0)
        self.horizontalLayout_9.setObjectName(u"horizontalLayout_9")
        self.label_12 = QLabel(EntityInfo)
        self.label_12.setObjectName(u"label_12")
        self.label_12.setMinimumSize(QSize(0, 0))

        self.horizontalLayout_9.addWidget(self.label_12)

        self.lineEdit_3 = QLineEdit(EntityInfo)
        self.lineEdit_3.setObjectName(u"lineEdit_3")
        sizePolicy1.setHeightForWidth(self.lineEdit_3.sizePolicy().hasHeightForWidth())
        self.lineEdit_3.setSizePolicy(sizePolicy1)

        self.horizontalLayout_9.addWidget(self.lineEdit_3)


        self.verticalLayout_2.addLayout(self.horizontalLayout_9)

        self.horizontalLayout_10 = QHBoxLayout()
        self.horizontalLayout_10.setSpacing(0)
        self.horizontalLayout_10.setObjectName(u"horizontalLayout_10")
        self.label_11 = QLabel(EntityInfo)
        self.label_11.setObjectName(u"label_11")
        self.label_11.setMinimumSize(QSize(48, 0))

        self.horizontalLayout_10.addWidget(self.label_11)

        self.comboBox_3 = QComboBox(EntityInfo)
        self.comboBox_3.setObjectName(u"comboBox_3")
        sizePolicy2.setHeightForWidth(self.comboBox_3.sizePolicy().hasHeightForWidth())
        self.comboBox_3.setSizePolicy(sizePolicy2)
        self.comboBox_3.setMaximumSize(QSize(16777215, 22))

        self.horizontalLayout_10.addWidget(self.comboBox_3)


        self.verticalLayout_2.addLayout(self.horizontalLayout_10)


        self.verticalLayout.addLayout(self.verticalLayout_2)


        self.retranslateUi(EntityInfo)

        QMetaObject.connectSlotsByName(EntityInfo)
    # setupUi

    def retranslateUi(self, EntityInfo):
        EntityInfo.setWindowTitle(QCoreApplication.translate("EntityInfo", u"Form", None))
        self.label_8.setText(QCoreApplication.translate("EntityInfo", u"\u6ca1\u6709\u9009\u62e9\u5185\u5bb9", None))
        self.label.setText("")
        self.label_5.setText("")
        self.label_2.setText(QCoreApplication.translate("EntityInfo", u"\u6807\u8bb0\uff1a", None))
        self.label_3.setText(QCoreApplication.translate("EntityInfo", u"\u5b9e\u4f8b\uff1a", None))
        self.label_4.setText(QCoreApplication.translate("EntityInfo", u"\u5207\u6362\uff1a", None))
        self.e_pushButton_4.setText("")
        self.e_pushButton_2.setText("")
        self.e_pushButton_1.setText("")
        self.e_pushButton_3.setText("")
        self.toolButton.setText(QCoreApplication.translate("EntityInfo", u"...", None))
        self.label_9.setText(QCoreApplication.translate("EntityInfo", u"\u5b9a\u4e49\uff1a", None))
        self.label_10.setText(QCoreApplication.translate("EntityInfo", u"\u9ad8\u7ea7\u5c5e\u6027\uff1a", None))
        self.e_checkBox_1.setText("")
        self.label_16.setText(QCoreApplication.translate("EntityInfo", u"\u4ef7\u683c\uff1a", None))
        self.label_15.setText(QCoreApplication.translate("EntityInfo", u"\u5927\u5c0f\uff1a", None))
        self.label_14.setText(QCoreApplication.translate("EntityInfo", u"URL\uff1a", None))
        self.label_13.setText(QCoreApplication.translate("EntityInfo", u"\u72b6\u6001\uff1a", None))
        self.label_12.setText(QCoreApplication.translate("EntityInfo", u"\u6240\u6709\u8005\uff1a", None))
        self.label_11.setText(QCoreApplication.translate("EntityInfo", u"\u7c7b\u578b\uff1a", None))
    # retranslateUi

