#ifndef MYWINDOW_H
#define MYWINDOW_H

#include "MyTitleBar.h"
#include <QFrame>
#include <QWidget>
#include <QVBoxLayout>

class MyWindow : public QFrame
{
    Q_OBJECT
public:
    MyWindow(QFrame *parent = nullptr);

    /**
        * @brief 设置标题
        * @param title，输入参数，标题内容
        */
       void setWindowTitle(const QString& title);
       /**
        * @brief 设置标题栏的图标
        * @param iconPath，输入参数，图标资源路径
        */
       void SetTitleBarIcon(const QString& iconPath);
       /**
        * @brief 获取内容组件对象指针
        * @return 返回QWidget*
        */
       QWidget* contentWidget();
       /**
        * @brief 设置标题栏高度
        * @param h，输入参数，标题栏高度;
        */
       void setWindowTitleHeight(int h);

private:
       QWidget* m_contentWidget;//内容组件
       MyTitleBar* m_titleBar;//标题栏
       QVBoxLayout* m_layout;//布局管理器
};

#endif // MYWINDOW_H
