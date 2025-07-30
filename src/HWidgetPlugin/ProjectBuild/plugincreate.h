#ifndef DEMO1_H
#define DEMO1_H

#include <QWidget>
#include <BaseWindow.h>

namespace Ui {
class PluginCreate;
}

class PluginCreate : public QWidget
{
    Q_OBJECT

public:
    explicit PluginCreate(QWidget *parent = 0);
    ~PluginCreate();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    void initTitleBar();
    Ui::PluginCreate *ui;
};

#endif // PLUGINCREATE_H
