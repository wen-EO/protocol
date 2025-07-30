#ifndef TREEMODEL_H
#define TREEMODEL_H
#include "qstandarditemmodel.h"

class TreeModel:public QStandardItemModel
{
    Q_OBJECT
public:
    TreeModel();
    ~TreeModel();

    void addItem(const QString& parentName, QStandardItem *item);
};

#endif // TREEMODEL_H
