/********************************************************************************
** Form generated from reading UI file 'hprojectmanage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPROJECTMANAGE_H
#define UI_HPROJECTMANAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HProjectManage
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *titleWidget;
    QWidget *stackedWidget;

    void setupUi(QWidget *HProjectManage)
    {
        if (HProjectManage->objectName().isEmpty())
            HProjectManage->setObjectName(QString::fromUtf8("HProjectManage"));
        HProjectManage->resize(400, 300);
        verticalLayout = new QVBoxLayout(HProjectManage);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(HProjectManage);
        titleWidget->setObjectName(QString::fromUtf8("titleWidget"));

        verticalLayout->addWidget(titleWidget);

        stackedWidget = new QWidget(HProjectManage);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        verticalLayout->addWidget(stackedWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 4);

        retranslateUi(HProjectManage);

        QMetaObject::connectSlotsByName(HProjectManage);
    } // setupUi

    void retranslateUi(QWidget *HProjectManage)
    {
        HProjectManage->setWindowTitle(QApplication::translate("HProjectManage", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HProjectManage: public Ui_HProjectManage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPROJECTMANAGE_H
