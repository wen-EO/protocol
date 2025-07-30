#include "treemodel.h"

TreeModel::TreeModel()
{

}

TreeModel::~TreeModel()
{

}

void TreeModel ::addItem(const QString& parentName, QStandardItem *item)
{
    //item->setData(parentName+"_"+item->text(),Qt::UserRole+1);
    QList<QStandardItem *> parentItems = this->findItems(parentName);
    if (parentItems.size() > 0)
    {
        parentItems.at(0)->appendRow(item);
    }
    else
    {
        QStandardItem *parentNode = new QStandardItem(parentName);
        parentNode->setEditable(false);
        this->appendRow(parentNode);
        parentNode->appendRow(item);
    }
}
