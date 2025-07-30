#ifndef HSTATUSWIDGET_H
#define HSTATUSWIDGET_H

#include <QWidget>
class StatusWidget;
namespace Ui {
class HStatusWidget;
}

class HStatusWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HStatusWidget(QWidget *parent = 0);
    ~HStatusWidget();

    void paintEvent(QPaintEvent *);
private:
    void init();

private:
    Ui::HStatusWidget *ui;

    StatusWidget *statusWidget;
};

#endif // HSTATUSWIDGET_H
