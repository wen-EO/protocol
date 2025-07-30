#include "tooltreeview.h"
#include <QDir>
#include <QString>
#include <QPainter>
#include <QScrollBar>
#include <QMouseEvent>
#include <QStandardItem>
#include <QDebug>

ToolTreeView::ToolTreeView(QWidget *parent) :
    QTreeView(parent)
{
    //去掉工具树状表头.
    this->setHeaderHidden(true);
    //设置全部展开.
    this->expandAll();
}

ToolTreeView::~ToolTreeView()
{
//    if (treeViewToolModel != NULL)
//    {
//        delete treeViewToolModel;
//        treeViewToolModel = NULL;
//    }
}

void ToolTreeView::mousePressEvent(QMouseEvent *event)
{
   m_pos = event->pos();
   QPersistentModelIndex index = indexAt(m_pos);
   if(event->buttons()==Qt::LeftButton)
        emit clicked(index);
   QTreeView::mousePressEvent(event);
}

void ToolTreeView::mouseMoveEvent(QMouseEvent *event)
{
   QWidget::mouseMoveEvent(event);
}

void ToolTreeView::mouseReleaseEvent(QMouseEvent *event)
{
    QWidget::mouseReleaseEvent(event);
}

void ToolTreeView::mouseDoubleClickEvent(QMouseEvent *event)
{
    QTreeView::mouseDoubleClickEvent(event);
}



