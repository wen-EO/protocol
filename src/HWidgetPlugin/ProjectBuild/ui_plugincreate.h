/********************************************************************************
** Form generated from reading UI file 'plugincreate.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PLUGINCREATE_H
#define UI_PLUGINCREATE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PluginCreate
{
public:
    QHBoxLayout *horizontalLayout;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_9;
    QLabel *label_2;
    QLabel *label_4;
    QLabel *label;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_7;
    QLabel *label_5;
    QLabel *label_7;
    QLineEdit *lineEdit_5;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_8;
    QLineEdit *lineEdit_4;
    QLabel *label_9;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_6;
    QLabel *label_8;

    void setupUi(QWidget *PluginCreate)
    {
        if (PluginCreate->objectName().isEmpty())
            PluginCreate->setObjectName(QString::fromUtf8("PluginCreate"));
        PluginCreate->resize(556, 414);
        horizontalLayout = new QHBoxLayout(PluginCreate);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(-1, 20, -1, -1);
        lineEdit_9 = new QLineEdit(PluginCreate);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        gridLayout->addWidget(lineEdit_9, 5, 1, 1, 2);

        label_2 = new QLabel(PluginCreate);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        label_4 = new QLabel(PluginCreate);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout->addWidget(label_4, 4, 0, 1, 1);

        label = new QLabel(PluginCreate);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lineEdit = new QLineEdit(PluginCreate);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 1, 1, 1);

        lineEdit_7 = new QLineEdit(PluginCreate);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        gridLayout->addWidget(lineEdit_7, 2, 3, 1, 1);

        label_5 = new QLabel(PluginCreate);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout->addWidget(label_5, 2, 2, 1, 1);

        label_7 = new QLabel(PluginCreate);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout->addWidget(label_7, 0, 2, 1, 1);

        lineEdit_5 = new QLineEdit(PluginCreate);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 0, 3, 1, 1);

        label_3 = new QLabel(PluginCreate);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEdit_3 = new QLineEdit(PluginCreate);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 2, 1, 1, 1);

        label_6 = new QLabel(PluginCreate);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 1, 2, 1, 1);

        lineEdit_8 = new QLineEdit(PluginCreate);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        gridLayout->addWidget(lineEdit_8, 1, 3, 1, 1);

        lineEdit_4 = new QLineEdit(PluginCreate);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 4, 1, 1, 1);

        label_9 = new QLabel(PluginCreate);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        pushButton = new QPushButton(PluginCreate);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 5, 3, 1, 1);

        pushButton_2 = new QPushButton(PluginCreate);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 6, 1, 1, 1);

        pushButton_3 = new QPushButton(PluginCreate);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 6, 2, 1, 1);

        lineEdit_2 = new QLineEdit(PluginCreate);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 1, 1, 1);

        lineEdit_6 = new QLineEdit(PluginCreate);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout->addWidget(lineEdit_6, 4, 3, 1, 1);

        label_8 = new QLabel(PluginCreate);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 4, 2, 1, 1);


        horizontalLayout->addLayout(gridLayout);


        retranslateUi(PluginCreate);

        QMetaObject::connectSlotsByName(PluginCreate);
    } // setupUi

    void retranslateUi(QWidget *PluginCreate)
    {
        PluginCreate->setWindowTitle(QApplication::translate("PluginCreate", "Form", nullptr));
        label_2->setText(QApplication::translate("PluginCreate", "\345\244\264\346\226\207\344\273\266\357\274\232", nullptr));
        label_4->setText(QApplication::translate("PluginCreate", "\346\217\222\344\273\266\346\272\220\346\226\207\344\273\266\357\274\232", nullptr));
        label->setText(QApplication::translate("PluginCreate", "\347\261\273\345\220\215\357\274\232", nullptr));
        label_5->setText(QApplication::translate("PluginCreate", "\346\217\222\344\273\266\345\244\264\346\226\207\344\273\266\357\274\232", nullptr));
        label_7->setText(QApplication::translate("PluginCreate", "\351\241\271\347\233\256\346\226\207\344\273\266\357\274\232", nullptr));
        label_3->setText(QApplication::translate("PluginCreate", "\346\217\222\344\273\266\345\220\215\347\247\260\357\274\232", nullptr));
        label_6->setText(QApplication::translate("PluginCreate", "\346\272\220\346\226\207\344\273\266\357\274\232", nullptr));
        label_9->setText(QApplication::translate("PluginCreate", "\345\237\272\344\272\216\345\267\262\346\234\211\347\273\204\344\273\266\345\210\233\345\273\272\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("PluginCreate", "\351\200\211\346\213\251\350\267\257\345\276\204", nullptr));
        pushButton_2->setText(QApplication::translate("PluginCreate", "\345\210\233\345\273\272", nullptr));
        pushButton_3->setText(QApplication::translate("PluginCreate", "\345\217\226\346\266\210", nullptr));
        label_8->setText(QApplication::translate("PluginCreate", "\346\217\222\344\273\266\347\225\214\351\235\242\346\226\207\344\273\266\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PluginCreate: public Ui_PluginCreate {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PLUGINCREATE_H
