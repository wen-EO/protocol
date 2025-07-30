/********************************************************************************
** Form generated from reading UI file 'hprojectwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.12
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HPROJECTWINDOW_H
#define UI_HPROJECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HProjectWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QWidget *titleWidget;
    QWidget *stackedWidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *HProjectWindow)
    {
        if (HProjectWindow->objectName().isEmpty())
            HProjectWindow->setObjectName(QString::fromUtf8("HProjectWindow"));
        HProjectWindow->resize(800, 600);
        centralwidget = new QWidget(HProjectWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleWidget = new QWidget(centralwidget);
        titleWidget->setObjectName(QString::fromUtf8("titleWidget"));

        verticalLayout->addWidget(titleWidget);

        stackedWidget = new QWidget(centralwidget);
        stackedWidget->setObjectName(QString::fromUtf8("stackedWidget"));

        verticalLayout->addWidget(stackedWidget);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 3);
        HProjectWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(HProjectWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        HProjectWindow->setStatusBar(statusbar);

        retranslateUi(HProjectWindow);

        QMetaObject::connectSlotsByName(HProjectWindow);
    } // setupUi

    void retranslateUi(QMainWindow *HProjectWindow)
    {
        HProjectWindow->setWindowTitle(QApplication::translate("HProjectWindow", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HProjectWindow: public Ui_HProjectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HPROJECTWINDOW_H
