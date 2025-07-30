/********************************************************************************
** Form generated from reading UI file 'datatypeedit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATATYPEEDIT_H
#define UI_DATATYPEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DataTypeEdit
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_OK;
    QPushButton *btn_Cancel;
    QLabel *label_2;
    QRadioButton *rbtn_Unsigned;
    QComboBox *cbx_SystemDataType;
    QRadioButton *rbtn_Signed;
    QLineEdit *edt_Name;
    QLabel *label;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *DataTypeEdit)
    {
        if (DataTypeEdit->objectName().isEmpty())
            DataTypeEdit->setObjectName(QString::fromUtf8("DataTypeEdit"));
        DataTypeEdit->resize(474, 237);
        verticalLayout = new QVBoxLayout(DataTypeEdit);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_3 = new QLabel(DataTypeEdit);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 5, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(15);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, 20, -1, -1);
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btn_OK = new QPushButton(DataTypeEdit);
        btn_OK->setObjectName(QString::fromUtf8("btn_OK"));

        horizontalLayout_2->addWidget(btn_OK);

        btn_Cancel = new QPushButton(DataTypeEdit);
        btn_Cancel->setObjectName(QString::fromUtf8("btn_Cancel"));

        horizontalLayout_2->addWidget(btn_Cancel);

        horizontalLayout_2->setStretch(0, 6);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);

        gridLayout->addLayout(horizontalLayout_2, 7, 0, 1, 1);

        label_2 = new QLabel(DataTypeEdit);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        rbtn_Unsigned = new QRadioButton(DataTypeEdit);
        buttonGroup = new QButtonGroup(DataTypeEdit);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(rbtn_Unsigned);
        rbtn_Unsigned->setObjectName(QString::fromUtf8("rbtn_Unsigned"));

        gridLayout->addWidget(rbtn_Unsigned, 4, 0, 1, 1);

        cbx_SystemDataType = new QComboBox(DataTypeEdit);
        cbx_SystemDataType->setObjectName(QString::fromUtf8("cbx_SystemDataType"));

        gridLayout->addWidget(cbx_SystemDataType, 6, 0, 1, 1);

        rbtn_Signed = new QRadioButton(DataTypeEdit);
        buttonGroup->addButton(rbtn_Signed);
        rbtn_Signed->setObjectName(QString::fromUtf8("rbtn_Signed"));
        rbtn_Signed->setChecked(true);

        gridLayout->addWidget(rbtn_Signed, 3, 0, 1, 1);

        edt_Name = new QLineEdit(DataTypeEdit);
        edt_Name->setObjectName(QString::fromUtf8("edt_Name"));

        gridLayout->addWidget(edt_Name, 1, 0, 1, 1);

        label = new QLabel(DataTypeEdit);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(DataTypeEdit);

        QMetaObject::connectSlotsByName(DataTypeEdit);
    } // setupUi

    void retranslateUi(QDialog *DataTypeEdit)
    {
        DataTypeEdit->setWindowTitle(QApplication::translate("DataTypeEdit", "\346\225\260\346\215\256\347\261\273\345\236\213", nullptr));
        label_3->setText(QApplication::translate("DataTypeEdit", "\347\263\273\347\273\237\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        btn_OK->setText(QApplication::translate("DataTypeEdit", "\347\241\256\345\256\232", nullptr));
        btn_Cancel->setText(QApplication::translate("DataTypeEdit", "\345\217\226\346\266\210", nullptr));
        label_2->setText(QApplication::translate("DataTypeEdit", "\346\234\211/\346\227\240\347\254\246\345\217\267\357\274\232", nullptr));
        rbtn_Unsigned->setText(QApplication::translate("DataTypeEdit", "unsigned", nullptr));
        rbtn_Signed->setText(QApplication::translate("DataTypeEdit", "signed", nullptr));
        label->setText(QApplication::translate("DataTypeEdit", "\346\225\260\346\215\256\347\261\273\345\236\213\345\220\215\347\247\260\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DataTypeEdit: public Ui_DataTypeEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATATYPEEDIT_H
