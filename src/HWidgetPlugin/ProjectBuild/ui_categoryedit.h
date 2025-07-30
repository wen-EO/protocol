/********************************************************************************
** Form generated from reading UI file 'categoryedit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CATEGORYEDIT_H
#define UI_CATEGORYEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_CategoryEdit
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLineEdit *edt_name;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_OK;
    QPushButton *btn_Cancel;
    QTextEdit *edt_description;

    void setupUi(QDialog *CategoryEdit)
    {
        if (CategoryEdit->objectName().isEmpty())
            CategoryEdit->setObjectName(QString::fromUtf8("CategoryEdit"));
        CategoryEdit->resize(468, 350);
        gridLayout_2 = new QGridLayout(CategoryEdit);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        label_4 = new QLabel(CategoryEdit);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        edt_name = new QLineEdit(CategoryEdit);
        edt_name->setObjectName(QString::fromUtf8("edt_name"));

        gridLayout->addWidget(edt_name, 1, 0, 1, 1);

        label_5 = new QLabel(CategoryEdit);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 20, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_OK = new QPushButton(CategoryEdit);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));

        horizontalLayout_2->addWidget(btn_OK);

        btn_Cancel = new QPushButton(CategoryEdit);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));

        horizontalLayout_2->addWidget(btn_Cancel);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout_2, 7, 0, 1, 1);

        edt_description = new QTextEdit(CategoryEdit);
        edt_description->setObjectName(QString::fromUtf8("edt_description"));

        gridLayout->addWidget(edt_description, 3, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(CategoryEdit);

        QMetaObject::connectSlotsByName(CategoryEdit);
    } // setupUi

    void retranslateUi(QDialog *CategoryEdit)
    {
        CategoryEdit->setWindowTitle(QApplication::translate("CategoryEdit", "\346\226\260\345\273\272\345\215\217\350\256\256\347\261\273\345\236\213", nullptr));
        label_4->setText(QApplication::translate("CategoryEdit", "\345\215\217\350\256\256\347\261\273\345\236\213\357\274\232", nullptr));
        label_5->setText(QApplication::translate("CategoryEdit", "\345\215\217\350\256\256\347\261\273\345\236\213\346\217\217\350\277\260\357\274\232", nullptr));
        btn_OK->setText(QApplication::translate("CategoryEdit", "\347\241\256\345\256\232", nullptr));
        btn_Cancel->setText(QApplication::translate("CategoryEdit", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CategoryEdit: public Ui_CategoryEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CATEGORYEDIT_H
