#ifndef HTITLEBAR_H
#define HTITLEBAR_H

#include <QWidget>
#include"qmap.h"
#include<QAction>
class QToolButton;
namespace Ui {
class HTitleBar;
}

class HTitleBar : public QWidget
{
    Q_OBJECT
typedef struct titleItem{
        QString name;
        QString displayName;
        QString icon;
        QString iconColor;
        int index;
        titleItem()
        {
            name = "";
            displayName = "";
            icon = "";
            iconColor = "";
            index = -1;
        }

}titleItem;

public:
    explicit HTitleBar(QWidget *parent = 0);
    ~HTitleBar();

    void paintEvent(QPaintEvent *);
private:
    void initStyle();

    bool getTitleItems();

    void fillTitle();

    void addQToolBtn(const titleItem & item);

    void init();

    void showColorMenu(bool show = false);

    void setTitle(const QString &title);

    static bool compareByIndex(const titleItem &r1,const titleItem &r2);

    void bindSigSlots();

    bool eventFilter(QObject *obj, QEvent *event);
private slots:
    void on_btnMenu_Min_clicked();
    void on_btnMenu_Max_clicked();
    void on_btnMenu_Close_clicked();

    void itemClicked();

    void changeStyle();

    void getItemClicked(const QString& name);
private:
    Ui::HTitleBar *ui;
    bool max;
    QRect location;
    QWidget *m_parent;

    QList<titleItem> barInfo;
    QList<QToolButton *>btnList;

    QString titleName;
    QString nameSize;
    QString titleIcon;
    QString titleIconSize;
};

#endif // HTITLEBAR_H
