/********************************************************************************
** Form generated from reading UI file 'export.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPORT_H
#define UI_EXPORT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Export
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QComboBox *cbx_category;
    QPushButton *pushButton;
    QTextEdit *filePosition;
    QPushButton *pushButton_2;

    void setupUi(QDialog *Export)
    {
        if (Export->objectName().isEmpty())
            Export->setObjectName(QString::fromUtf8("Export"));
        Export->resize(316, 300);
        verticalLayout = new QVBoxLayout(Export);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(Export);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(12);
        label->setFont(font);

        verticalLayout->addWidget(label);

        cbx_category = new QComboBox(Export);
        cbx_category->setObjectName(QString::fromUtf8("cbx_category"));

        verticalLayout->addWidget(cbx_category);

        pushButton = new QPushButton(Export);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setFont(font);

        verticalLayout->addWidget(pushButton);

        filePosition = new QTextEdit(Export);
        filePosition->setObjectName(QString::fromUtf8("filePosition"));

        verticalLayout->addWidget(filePosition);

        pushButton_2 = new QPushButton(Export);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setFont(font);

        verticalLayout->addWidget(pushButton_2);


        retranslateUi(Export);

        QMetaObject::connectSlotsByName(Export);
    } // setupUi

    void retranslateUi(QDialog *Export)
    {
        Export->setWindowTitle(QApplication::translate("Export", "Dialog", nullptr));
        label->setText(QApplication::translate("Export", "\351\200\211\346\213\251\345\215\217\350\256\256\347\261\273\345\236\213:", nullptr));
        pushButton->setText(QApplication::translate("Export", "\351\200\211\346\213\251\345\257\274\345\207\272\344\275\215\347\275\256:", nullptr));
        pushButton_2->setText(QApplication::translate("Export", "\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Export: public Ui_Export {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPORT_H
