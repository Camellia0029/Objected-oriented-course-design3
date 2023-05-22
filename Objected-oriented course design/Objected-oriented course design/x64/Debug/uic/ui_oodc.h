/********************************************************************************
** Form generated from reading UI file 'oodc.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OODC_H
#define UI_OODC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_oodcClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *oodcClass)
    {
        if (oodcClass->objectName().isEmpty())
            oodcClass->setObjectName(QString::fromUtf8("oodcClass"));
        oodcClass->resize(600, 400);
        menuBar = new QMenuBar(oodcClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        oodcClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(oodcClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        oodcClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(oodcClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        oodcClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(oodcClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        oodcClass->setStatusBar(statusBar);

        retranslateUi(oodcClass);

        QMetaObject::connectSlotsByName(oodcClass);
    } // setupUi

    void retranslateUi(QMainWindow *oodcClass)
    {
        oodcClass->setWindowTitle(QCoreApplication::translate("oodcClass", "oodc", nullptr));
    } // retranslateUi

};

namespace Ui {
    class oodcClass: public Ui_oodcClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OODC_H
