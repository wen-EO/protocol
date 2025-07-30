/********************************************************************************
** Form generated from reading UI file 'projectbuild.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTBUILD_H
#define UI_PROJECTBUILD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <tooltreeview.h>

QT_BEGIN_NAMESPACE

class Ui_ProjectBuild
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLineEdit *edt_name;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QTextEdit *edt_description;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_3;
    QComboBox *cbx_category;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_4;
    QLineEdit *edt_createUser;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_5;
    QDateEdit *date_createTime;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *btn_AddDataType;
    QPushButton *btn_EditDataType;
    QPushButton *btn_DeleteDataType;
    QSpacerItem *horizontalSpacer;
    QTableView *tableView_dataType;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_11;
    QVBoxLayout *verticalLayout_6;
    QListView *listView;
    QLineEdit *edt_StructName;
    QLineEdit *edt_StructDescription;
    QLineEdit *edt_StructMark;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *btn_CreateStruct;
    QPushButton *btn_DeleteStruct;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_12;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_10;
    QPushButton *btn_AddDataType_2;
    QPushButton *btn_EditDataType_2;
    QPushButton *btn_DeleteDataType_2;
    QSpacerItem *horizontalSpacer_2;
    QTableView *tableView_struct;
    QWidget *leftWidget;
    QVBoxLayout *verticalLayout1;
    QLabel *lbl_Component;
    ToolTreeView *treeView;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnCreateType;
    QPushButton *btn_CreateProtocol;
    QPushButton *btn_ExportProtocol;

    void setupUi(QWidget *ProjectBuild)
    {
        if (ProjectBuild->objectName().isEmpty())
            ProjectBuild->setObjectName(QString::fromUtf8("ProjectBuild"));
        ProjectBuild->resize(955, 615);
        verticalLayout = new QVBoxLayout(ProjectBuild);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        tabWidget = new QTabWidget(ProjectBuild);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab1 = new QWidget();
        tab1->setObjectName(QString::fromUtf8("tab1"));
        verticalLayout_2 = new QVBoxLayout(tab1);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        groupBox = new QGroupBox(tab1);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(groupBox);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        edt_name = new QLineEdit(groupBox);
        edt_name->setObjectName(QString::fromUtf8("edt_name"));

        horizontalLayout_3->addWidget(edt_name);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 8);

        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        edt_description = new QTextEdit(groupBox);
        edt_description->setObjectName(QString::fromUtf8("edt_description"));

        horizontalLayout_4->addWidget(edt_description);

        horizontalLayout_4->setStretch(1, 8);

        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_5->addWidget(label_3);

        cbx_category = new QComboBox(groupBox);
        cbx_category->setObjectName(QString::fromUtf8("cbx_category"));

        horizontalLayout_5->addWidget(cbx_category);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 8);

        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_6->addWidget(label_4);

        edt_createUser = new QLineEdit(groupBox);
        edt_createUser->setObjectName(QString::fromUtf8("edt_createUser"));

        horizontalLayout_6->addWidget(edt_createUser);

        horizontalLayout_6->setStretch(0, 1);
        horizontalLayout_6->setStretch(1, 8);

        verticalLayout_3->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_7->addWidget(label_5);

        date_createTime = new QDateEdit(groupBox);
        date_createTime->setObjectName(QString::fromUtf8("date_createTime"));

        horizontalLayout_7->addWidget(date_createTime);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 8);

        verticalLayout_3->addLayout(horizontalLayout_7);


        horizontalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tab1);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        verticalLayout_4 = new QVBoxLayout(groupBox_2);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        btn_AddDataType = new QPushButton(groupBox_2);
        btn_AddDataType->setObjectName(QString::fromUtf8("btn_AddDataType"));

        horizontalLayout_8->addWidget(btn_AddDataType);

        btn_EditDataType = new QPushButton(groupBox_2);
        btn_EditDataType->setObjectName(QString::fromUtf8("btn_EditDataType"));

        horizontalLayout_8->addWidget(btn_EditDataType);

        btn_DeleteDataType = new QPushButton(groupBox_2);
        btn_DeleteDataType->setObjectName(QString::fromUtf8("btn_DeleteDataType"));

        horizontalLayout_8->addWidget(btn_DeleteDataType);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        horizontalLayout_8->setStretch(0, 1);
        horizontalLayout_8->setStretch(1, 1);
        horizontalLayout_8->setStretch(2, 1);
        horizontalLayout_8->setStretch(3, 6);

        verticalLayout_4->addLayout(horizontalLayout_8);

        tableView_dataType = new QTableView(groupBox_2);
        tableView_dataType->setObjectName(QString::fromUtf8("tableView_dataType"));

        verticalLayout_4->addWidget(tableView_dataType);


        horizontalLayout_2->addWidget(groupBox_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 3);

        verticalLayout_2->addLayout(horizontalLayout_2);

        groupBox_3 = new QGroupBox(tab1);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        listView = new QListView(groupBox_3);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout_6->addWidget(listView);

        edt_StructName = new QLineEdit(groupBox_3);
        edt_StructName->setObjectName(QString::fromUtf8("edt_StructName"));

        verticalLayout_6->addWidget(edt_StructName);

        edt_StructDescription = new QLineEdit(groupBox_3);
        edt_StructDescription->setObjectName(QString::fromUtf8("edt_StructDescription"));

        verticalLayout_6->addWidget(edt_StructDescription);

        edt_StructMark = new QLineEdit(groupBox_3);
        edt_StructMark->setObjectName(QString::fromUtf8("edt_StructMark"));

        verticalLayout_6->addWidget(edt_StructMark);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        btn_CreateStruct = new QPushButton(groupBox_3);
        btn_CreateStruct->setObjectName(QString::fromUtf8("btn_CreateStruct"));

        horizontalLayout_9->addWidget(btn_CreateStruct);

        btn_DeleteStruct = new QPushButton(groupBox_3);
        btn_DeleteStruct->setObjectName(QString::fromUtf8("btn_DeleteStruct"));

        horizontalLayout_9->addWidget(btn_DeleteStruct);


        verticalLayout_6->addLayout(horizontalLayout_9);


        horizontalLayout_11->addLayout(verticalLayout_6);

        groupBox_4 = new QGroupBox(groupBox_3);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        horizontalLayout_12 = new QHBoxLayout(groupBox_4);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        btn_AddDataType_2 = new QPushButton(groupBox_4);
        btn_AddDataType_2->setObjectName(QString::fromUtf8("btn_AddDataType_2"));

        horizontalLayout_10->addWidget(btn_AddDataType_2);

        btn_EditDataType_2 = new QPushButton(groupBox_4);
        btn_EditDataType_2->setObjectName(QString::fromUtf8("btn_EditDataType_2"));

        horizontalLayout_10->addWidget(btn_EditDataType_2);

        btn_DeleteDataType_2 = new QPushButton(groupBox_4);
        btn_DeleteDataType_2->setObjectName(QString::fromUtf8("btn_DeleteDataType_2"));

        horizontalLayout_10->addWidget(btn_DeleteDataType_2);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_2);

        horizontalLayout_10->setStretch(0, 1);
        horizontalLayout_10->setStretch(1, 1);
        horizontalLayout_10->setStretch(2, 1);
        horizontalLayout_10->setStretch(3, 6);

        verticalLayout_5->addLayout(horizontalLayout_10);

        tableView_struct = new QTableView(groupBox_4);
        tableView_struct->setObjectName(QString::fromUtf8("tableView_struct"));

        verticalLayout_5->addWidget(tableView_struct);


        horizontalLayout_12->addLayout(verticalLayout_5);


        horizontalLayout_11->addWidget(groupBox_4);

        horizontalLayout_11->setStretch(0, 1);
        horizontalLayout_11->setStretch(1, 4);

        verticalLayout_7->addLayout(horizontalLayout_11);


        verticalLayout_2->addWidget(groupBox_3);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 1);
        tabWidget->addTab(tab1, QString());

        gridLayout->addWidget(tabWidget, 0, 10, 1, 1);

        leftWidget = new QWidget(ProjectBuild);
        leftWidget->setObjectName(QString::fromUtf8("leftWidget"));
        verticalLayout1 = new QVBoxLayout(leftWidget);
        verticalLayout1->setSpacing(6);
        verticalLayout1->setObjectName(QString::fromUtf8("verticalLayout1"));
        verticalLayout1->setContentsMargins(1, 1, 1, 1);
        lbl_Component = new QLabel(leftWidget);
        lbl_Component->setObjectName(QString::fromUtf8("lbl_Component"));
        lbl_Component->setMinimumSize(QSize(0, 20));

        verticalLayout1->addWidget(lbl_Component);

        treeView = new ToolTreeView(leftWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));
        treeView->setMaximumSize(QSize(16777215, 16777215));
        treeView->setDragEnabled(false);

        verticalLayout1->addWidget(treeView);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnCreateType = new QPushButton(leftWidget);
        btnCreateType->setObjectName(QString::fromUtf8("btnCreateType"));
        btnCreateType->setMinimumSize(QSize(0, 0));

        horizontalLayout->addWidget(btnCreateType);

        btn_CreateProtocol = new QPushButton(leftWidget);
        btn_CreateProtocol->setObjectName(QString::fromUtf8("btn_CreateProtocol"));

        horizontalLayout->addWidget(btn_CreateProtocol);

        btn_ExportProtocol = new QPushButton(leftWidget);
        btn_ExportProtocol->setObjectName(QString::fromUtf8("btn_ExportProtocol"));

        horizontalLayout->addWidget(btn_ExportProtocol);


        verticalLayout1->addLayout(horizontalLayout);


        gridLayout->addWidget(leftWidget, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ProjectBuild);

        QMetaObject::connectSlotsByName(ProjectBuild);
    } // setupUi

    void retranslateUi(QWidget *ProjectBuild)
    {
        ProjectBuild->setWindowTitle(QApplication::translate("ProjectBuild", "Form", nullptr));
        groupBox->setTitle(QApplication::translate("ProjectBuild", "\345\237\272\346\234\254\344\277\241\346\201\257", nullptr));
        label->setText(QApplication::translate("ProjectBuild", "\345\215\217\350\256\256\345\220\215\347\247\260\357\274\232", nullptr));
        label_2->setText(QApplication::translate("ProjectBuild", "\345\215\217\350\256\256\346\217\217\350\277\260\357\274\232", nullptr));
        label_3->setText(QApplication::translate("ProjectBuild", "\345\215\217\350\256\256\345\210\206\347\261\273\357\274\232", nullptr));
        label_4->setText(QApplication::translate("ProjectBuild", "\345\210\233 \345\273\272 \344\272\272\357\274\232", nullptr));
        label_5->setText(QApplication::translate("ProjectBuild", "\345\210\233\345\273\272\346\227\266\351\227\264\357\274\232", nullptr));
        groupBox_2->setTitle(QApplication::translate("ProjectBuild", "\346\225\260\346\215\256\347\261\273\345\236\213", nullptr));
        btn_AddDataType->setText(QApplication::translate("ProjectBuild", "\346\267\273\345\212\240", nullptr));
        btn_EditDataType->setText(QApplication::translate("ProjectBuild", "\344\277\256\346\224\271", nullptr));
        btn_DeleteDataType->setText(QApplication::translate("ProjectBuild", "\345\210\240\351\231\244", nullptr));
        groupBox_3->setTitle(QApplication::translate("ProjectBuild", "\347\273\223\346\236\204\344\275\223", nullptr));
        edt_StructName->setPlaceholderText(QApplication::translate("ProjectBuild", "\347\273\223\346\236\204\344\275\223\345\220\215\347\247\260", nullptr));
        edt_StructDescription->setPlaceholderText(QApplication::translate("ProjectBuild", "\347\273\223\346\236\204\344\275\223\346\217\217\350\277\260", nullptr));
        edt_StructMark->setPlaceholderText(QApplication::translate("ProjectBuild", "\347\273\223\346\236\204\344\275\223\346\240\207\350\257\206", nullptr));
        btn_CreateStruct->setText(QApplication::translate("ProjectBuild", "\346\267\273\345\212\240\347\273\223\346\236\204\344\275\223", nullptr));
        btn_DeleteStruct->setText(QApplication::translate("ProjectBuild", "\345\210\240\351\231\244\347\273\223\346\236\204", nullptr));
        groupBox_4->setTitle(QApplication::translate("ProjectBuild", "\347\273\223\346\236\204\344\275\223\344\277\241\346\201\257", nullptr));
        btn_AddDataType_2->setText(QApplication::translate("ProjectBuild", "\346\267\273\345\212\240", nullptr));
        btn_EditDataType_2->setText(QApplication::translate("ProjectBuild", "\344\277\256\346\224\271", nullptr));
        btn_DeleteDataType_2->setText(QApplication::translate("ProjectBuild", "\345\210\240\351\231\244", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab1), QApplication::translate("ProjectBuild", "\345\215\217\350\256\256\350\257\246\346\203\205", nullptr));
        lbl_Component->setText(QApplication::translate("ProjectBuild", "\345\215\217\350\256\256\345\272\223", nullptr));
        btnCreateType->setText(QApplication::translate("ProjectBuild", "\346\267\273\345\212\240\345\215\217\350\256\256\347\261\273\345\236\213", nullptr));
        btn_CreateProtocol->setText(QApplication::translate("ProjectBuild", "\346\267\273\345\212\240\345\215\217\350\256\256", nullptr));
        btn_ExportProtocol->setText(QApplication::translate("ProjectBuild", "\345\257\274\345\207\272\345\215\217\350\256\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectBuild: public Ui_ProjectBuild {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTBUILD_H
