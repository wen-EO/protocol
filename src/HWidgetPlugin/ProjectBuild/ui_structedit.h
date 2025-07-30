/********************************************************************************
** Form generated from reading UI file 'structedit.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STRUCTEDIT_H
#define UI_STRUCTEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StructEdit
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *edt_description;
    QLineEdit *edt_defaultValue;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_8;
    QLineEdit *edt_bit;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btn_OK;
    QPushButton *btn_Cancel;
    QLineEdit *edt_name;
    QLabel *label_6;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label_7;
    QLineEdit *edt_quantization;
    QLineEdit *edt_range;
    QComboBox *cbx_systemDataType;

    void setupUi(QDialog *StructEdit)
    {
        if (StructEdit->objectName().isEmpty())
            StructEdit->setObjectName(QString::fromUtf8("StructEdit"));
        StructEdit->resize(443, 366);
        layoutWidget = new QWidget(StructEdit);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 441, 361));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(9, 9, 9, 9);
        edt_description = new QLineEdit(layoutWidget);
        edt_description->setObjectName(QString::fromUtf8("edt_description"));

        gridLayout->addWidget(edt_description, 7, 0, 1, 1);

        edt_defaultValue = new QLineEdit(layoutWidget);
        edt_defaultValue->setObjectName(QString::fromUtf8("edt_defaultValue"));

        gridLayout->addWidget(edt_defaultValue, 11, 0, 1, 1);

        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 6, 0, 1, 1);

        label_8 = new QLabel(layoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 12, 0, 1, 1);

        edt_bit = new QLineEdit(layoutWidget);
        edt_bit->setObjectName(QString::fromUtf8("edt_bit"));

        gridLayout->addWidget(edt_bit, 3, 0, 1, 1);

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

        gridLayout->addLayout(horizontalLayout_2, 17, 0, 1, 1);

        edt_name = new QLineEdit(layoutWidget);
        edt_name->setObjectName(QString::fromUtf8("edt_name"));

        gridLayout->addWidget(edt_name, 5, 0, 1, 1);

        label_6 = new QLabel(layoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 8, 0, 1, 1);

        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 0, 0, 1, 1);

        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        label_7 = new QLabel(layoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 10, 0, 1, 1);

        edt_quantization = new QLineEdit(layoutWidget);
        edt_quantization->setObjectName(QString::fromUtf8("edt_quantization"));

        gridLayout->addWidget(edt_quantization, 13, 0, 1, 1);

        edt_range = new QLineEdit(layoutWidget);
        edt_range->setObjectName(QString::fromUtf8("edt_range"));

        gridLayout->addWidget(edt_range, 9, 0, 1, 1);

        cbx_systemDataType = new QComboBox(layoutWidget);
        cbx_systemDataType->setObjectName(QString::fromUtf8("cbx_systemDataType"));

        gridLayout->addWidget(cbx_systemDataType, 1, 0, 1, 1);


        retranslateUi(StructEdit);

        QMetaObject::connectSlotsByName(StructEdit);
    } // setupUi

    void retranslateUi(QDialog *StructEdit)
    {
        StructEdit->setWindowTitle(QApplication::translate("StructEdit", "\346\226\260\345\273\272\347\273\223\346\236\204\344\275\223\350\257\246\346\203\205", nullptr));
        label_4->setText(QApplication::translate("StructEdit", "\345\255\227\346\256\265\345\256\232\344\271\211\357\274\232", nullptr));
        label_5->setText(QApplication::translate("StructEdit", "\345\255\227\346\256\265\346\217\217\350\277\260\357\274\232", nullptr));
        label_8->setText(QApplication::translate("StructEdit", "\351\207\217\345\214\226\357\274\232", nullptr));
        btn_OK->setText(QApplication::translate("StructEdit", "\347\241\256\345\256\232", nullptr));
        btn_Cancel->setText(QApplication::translate("StructEdit", "\345\217\226\346\266\210", nullptr));
        label_6->setText(QApplication::translate("StructEdit", "\345\217\226\345\200\274\350\214\203\345\233\264\357\274\232", nullptr));
        label_3->setText(QApplication::translate("StructEdit", "\347\273\223\346\236\204\344\275\223\346\225\260\346\215\256\347\261\273\345\236\213\357\274\232", nullptr));
        label_2->setText(QApplication::translate("StructEdit", "\344\275\215\345\256\232\344\271\211\357\274\232", nullptr));
        label_7->setText(QApplication::translate("StructEdit", "\351\273\230\350\256\244\345\200\274\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StructEdit: public Ui_StructEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STRUCTEDIT_H
