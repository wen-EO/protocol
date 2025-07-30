/********************************************************************************
** Form generated from reading UI file 'hstatuswidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HSTATUSWIDGET_H
#define UI_HSTATUSWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HStatusWidget
{
public:

    void setupUi(QWidget *HStatusWidget)
    {
        if (HStatusWidget->objectName().isEmpty())
            HStatusWidget->setObjectName(QString::fromUtf8("HStatusWidget"));
        HStatusWidget->resize(400, 300);

        retranslateUi(HStatusWidget);

        QMetaObject::connectSlotsByName(HStatusWidget);
    } // setupUi

    void retranslateUi(QWidget *HStatusWidget)
    {
        HStatusWidget->setWindowTitle(QApplication::translate("HStatusWidget", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HStatusWidget: public Ui_HStatusWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSTATUSWIDGET_H
