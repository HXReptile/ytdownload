/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *lineEdit_url;
    QPushButton *pushButton_getdetailinfo;
    QPlainTextEdit *plainTextEdit_detail;
    QHBoxLayout *horizontalLayout;
    QComboBox *comboBox_type;
    QPushButton *pushButton_cancel;
    QPushButton *pushButton_download;
    QPushButton *pushButton_selectpath;
    QPlainTextEdit *plainTextEdit_download;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(608, 636);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        lineEdit_url = new QLineEdit(centralwidget);
        lineEdit_url->setObjectName("lineEdit_url");

        horizontalLayout_2->addWidget(lineEdit_url);

        pushButton_getdetailinfo = new QPushButton(centralwidget);
        pushButton_getdetailinfo->setObjectName("pushButton_getdetailinfo");

        horizontalLayout_2->addWidget(pushButton_getdetailinfo);

        horizontalLayout_2->setStretch(0, 9);
        horizontalLayout_2->setStretch(1, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        plainTextEdit_detail = new QPlainTextEdit(centralwidget);
        plainTextEdit_detail->setObjectName("plainTextEdit_detail");

        verticalLayout->addWidget(plainTextEdit_detail);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        comboBox_type = new QComboBox(centralwidget);
        comboBox_type->addItem(QString());
        comboBox_type->addItem(QString());
        comboBox_type->setObjectName("comboBox_type");

        horizontalLayout->addWidget(comboBox_type);

        pushButton_cancel = new QPushButton(centralwidget);
        pushButton_cancel->setObjectName("pushButton_cancel");

        horizontalLayout->addWidget(pushButton_cancel);

        pushButton_download = new QPushButton(centralwidget);
        pushButton_download->setObjectName("pushButton_download");

        horizontalLayout->addWidget(pushButton_download);

        pushButton_selectpath = new QPushButton(centralwidget);
        pushButton_selectpath->setObjectName("pushButton_selectpath");

        horizontalLayout->addWidget(pushButton_selectpath);

        horizontalLayout->setStretch(0, 3);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(3, 3);

        verticalLayout->addLayout(horizontalLayout);

        plainTextEdit_download = new QPlainTextEdit(centralwidget);
        plainTextEdit_download->setObjectName("plainTextEdit_download");

        verticalLayout->addWidget(plainTextEdit_download);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 608, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
#if QT_CONFIG(statustip)
        lineEdit_url->setStatusTip(QString());
#endif // QT_CONFIG(statustip)
        lineEdit_url->setPlaceholderText(QCoreApplication::translate("MainWindow", "\350\257\267\350\276\223\345\205\245\350\247\206\351\242\221\347\275\221\345\235\200", nullptr));
        pushButton_getdetailinfo->setText(QCoreApplication::translate("MainWindow", "\350\216\267\345\217\226", nullptr));
        comboBox_type->setItemText(0, QCoreApplication::translate("MainWindow", "\350\247\206\351\242\221", nullptr));
        comboBox_type->setItemText(1, QCoreApplication::translate("MainWindow", "\351\237\263\351\242\221", nullptr));

        pushButton_cancel->setText(QCoreApplication::translate("MainWindow", "\345\217\226\346\266\210", nullptr));
        pushButton_download->setText(QCoreApplication::translate("MainWindow", "\344\270\213\350\275\275", nullptr));
        pushButton_selectpath->setText(QCoreApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
