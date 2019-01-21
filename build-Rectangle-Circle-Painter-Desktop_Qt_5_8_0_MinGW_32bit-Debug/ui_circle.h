/********************************************************************************
** Form generated from reading UI file 'circle.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CIRCLE_H
#define UI_CIRCLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Circle
{
public:

    void setupUi(QDialog *Circle)
    {
        if (Circle->objectName().isEmpty())
            Circle->setObjectName(QStringLiteral("Circle"));
        Circle->resize(400, 300);

        retranslateUi(Circle);

        QMetaObject::connectSlotsByName(Circle);
    } // setupUi

    void retranslateUi(QDialog *Circle)
    {
        Circle->setWindowTitle(QApplication::translate("Circle", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Circle: public Ui_Circle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CIRCLE_H
