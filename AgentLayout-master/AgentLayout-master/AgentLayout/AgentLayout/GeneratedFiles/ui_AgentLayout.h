/********************************************************************************
** Form generated from reading UI file 'AgentLayout.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AGENTLAYOUT_H
#define UI_AGENTLAYOUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AgentLayoutClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AgentLayoutClass)
    {
        if (AgentLayoutClass->objectName().isEmpty())
            AgentLayoutClass->setObjectName(QString::fromUtf8("AgentLayoutClass"));
        AgentLayoutClass->resize(600, 400);
        menuBar = new QMenuBar(AgentLayoutClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        AgentLayoutClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AgentLayoutClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        AgentLayoutClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(AgentLayoutClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        AgentLayoutClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(AgentLayoutClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        AgentLayoutClass->setStatusBar(statusBar);

        retranslateUi(AgentLayoutClass);

        QMetaObject::connectSlotsByName(AgentLayoutClass);
    } // setupUi

    void retranslateUi(QMainWindow *AgentLayoutClass)
    {
        AgentLayoutClass->setWindowTitle(QApplication::translate("AgentLayoutClass", "AgentLayout", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AgentLayoutClass: public Ui_AgentLayoutClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AGENTLAYOUT_H
