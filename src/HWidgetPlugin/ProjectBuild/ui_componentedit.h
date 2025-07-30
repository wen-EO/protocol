/********************************************************************************
** Form generated from reading UI file 'componentedit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPONENTEDIT_H
#define UI_COMPONENTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ComponentEdit
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *edt_createUser;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_OK;
    QPushButton *btn_Cancel;
    QLabel *label_7;
    QDateEdit *date_createTime;
    QLabel *label_6;
    QLineEdit *edt_name;
    QLabel *label_3;
    QComboBox *cbx_category;
    QTextEdit *edt_description;

    void setupUi(QDialog *ComponentEdit)
    {
        if (ComponentEdit->objectName().isEmpty())
            ComponentEdit->setObjectName(QString::fromUtf8("ComponentEdit"));
        ComponentEdit->resize(468, 381);
        layoutWidget = new QWidget(ComponentEdit);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 441, 361));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        edt_createUser = new QLineEdit(layoutWidget);
        edt_createUser->setObjectName(QString::fromUtf8("edt_createUser"));

        gridLayout->addWidget(edt_createUser, 7, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 20, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_OK = new QPushButton(layoutWidget);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));

        horizontalLayout_2->addWidget(btn_OK);

        btn_Cancel = new QPushButton(layoutWidget);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));

        horizontalLayout_2->addWidget(btn_Cancel);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout_2, 13, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 8, 0, 1, 1);

        date_createTime = new QDateEdit(layoutWidget);
        date_createTime->setObjectName(QString::fromUtf8("date_createTime"));

        gridLayout->addWidget(date_createTime, 9, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 6, 0, 1, 1);

        edt_name = new QLineEdit(layoutWidget);
        edt_name->setObjectName(QString::fromUtf8("edt_name"));

        gridLayout->addWidget(edt_name, 3, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        cbx_category = new QComboBox(layoutWidget);
        cbx_category->setObjectName(QString::fromUtf8("cbx_category"));

        gridLayout->addWidget(cbx_category, 1, 0, 1, 1);

        edt_description = new QTextEdit(layoutWidget);
        edt_description->setObjectName(QString::fromUtf8("edt_description"));

        gridLayout->addWidget(edt_description, 5, 0, 1, 1);


        retranslateUi(ComponentEdit);

        QMetaObject::connectSlotsByName(ComponentEdit);
    } // setupUi

    void retranslateUi(QDialog *ComponentEdit)
    {
        ComponentEdit->setWindowTitle(QApplication::translate("ComponentEdit", "\346\226\260\345\273\272\345\215\217\350\256\256", nullptr));
        label_4->setText(QApplication::translate("ComponentEdit", "\345\215\217\350\256\256\345\220\215\347\247\260\357\274\232", nullptr));
        label_5->setText(QApplication::translate("ComponentEdit", "\345\215\217\350\256\256\346\217\217\350\277\260\357\274\232", nullptr));
        btn_OK->setText(QApplication::translate("ComponentEdit", "\347\241\256\345\256\232", nullptr));
        btn_Cancel->setText(QApplication::translate("ComponentEdit", "\345\217\226\346\266\210", nullptr));
        label_7->setText(QApplication::translate("ComponentEdit", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        label_6->setText(QApplication::translate("ComponentEdit", "\345\210\233\345\273\272\344\272\272\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ComponentEdit", "\345\215\217\350\256\256\347\261\273\345\236\213\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ComponentEdit: public Ui_ComponentEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPONENTEDIT_H
