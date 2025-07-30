#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#include "BaseTitleBar.h"
#include <QWidget>
#include <QMainWindow>
#include <QVBoxLayout>
#include <QDialog>

class BaseWindow : public QWidget
{
    Q_OBJECT

public:
    BaseWindow(QWidget *parent = 0);
    ~BaseWindow();

private:
    void initTitleBar();
    void paintEvent(QPaintEvent *event);
    void loadStyleSheet(const QString &sheetName);

private slots:
    void onButtonMinClicked();
    void onButtonRestoreClicked();
    void onButtonMaxClicked();
    void onButtonCloseClicked();

protected:
    BaseTitleBar* m_titleBar;
    QWidget* m_contentWidget;
    QVBoxLayout* m_layout;
};


#endif // BASEWINDOW_H
