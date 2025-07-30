#ifndef TOOLTREEVIEW_H
#define TOOLTREEVIEW_H

#include <QTreeView>

class Q_DECL_EXPORT ToolTreeView : public QTreeView
{
    Q_OBJECT
public:
    explicit ToolTreeView(QWidget *parent = 0);
    ~ToolTreeView();

private:
    //点击后的位置记录.
    QPoint m_pos;
    //工具栏数据模型.
   // toolManageModel *treeViewToolModel;
protected:
    void mousePressEvent(QMouseEvent *);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void mouseDoubleClickEvent(QMouseEvent *);
};

#endif //
