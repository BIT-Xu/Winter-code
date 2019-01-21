/********************************************************************************
** Form generated from reading UI file 'rectangle.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTANGLE_H
#define UI_RECTANGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_Rectangle
{
public:

    void setupUi(QDialog *Rectangle)
    {
        if (Rectangle->objectName().isEmpty())
            Rectangle->setObjectName(QStringLiteral("Rectangle"));
        Rectangle->resize(400, 300);

        retranslateUi(Rectangle);

        QMetaObject::connectSlotsByName(Rectangle);
    } // setupUi

    void retranslateUi(QDialog *Rectangle)
    {
        Rectangle->setWindowTitle(QApplication::translate("Rectangle", "Dialog", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Rectangle: public Ui_Rectangle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTANGLE_H
