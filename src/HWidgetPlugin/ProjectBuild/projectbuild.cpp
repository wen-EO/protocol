#include "projectbuild.h"
#include "ui_projectbuild.h"
#include "treemodel.h"
#include "qstyleoption.h"
#include "qpainter.h"
#include "QtAwesome.h"
#include "mywizard.h"
#include "hwidgetdefine.h"
#include "hwidgetlibrary.h"
#include "hdefine.h"
#include "plugincreate.h"
#include "datatypeedit.h"
#include "mywindow.h"
#include "hconfigmanage.h"
#include "hwindowapi.h"
#include "structedit.h"
#include "componentedit.h"
#include "categoryedit.h"
#include "export.h"
#include <QDebug>
#include <QDockWidget>
#include <QSplitter>
#include <QMessageBox>
#include <QDir>
//添加头文件
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QUuid>
#include <QSettings>
#include <QScrollArea>
#include <QFileDialog>
#include <QProcess>
#include <QDomDocument>

ProjectBuild::ProjectBuild(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectBuild)
{
    ui->setupUi(this);
    init();
    //支持右键菜单
    ui->treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    this->setProperty("form","plugin");
}

ProjectBuild::~ProjectBuild()
{
    delete ui;
}

void ProjectBuild::paintEvent(QPaintEvent *)
{
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);

    style()->drawPrimitive(QStyle::PE_Widget,&opt,&p,this);
}

void ProjectBuild::init()
{
    //分割主窗体，可拖拉
    QSplitter *splitterMain = new QSplitter(Qt::Horizontal, 0); //新建主分割窗口，水平分割
    //splitterMain->setStyleSheet("QSplitter::handle { background-color: gray }"); //设置分界线的样式
    splitterMain->setHandleWidth(5);//设置分界线的宽度
    splitterMain->addWidget(ui->leftWidget);
    splitterMain->addWidget(ui->tabWidget);
    splitterMain->setStretchFactor(1,3);
    ui->gridLayout->addWidget(splitterMain);

    m_model = new TreeModel();
    m_listModel = new QStandardItemModel(this);
    m_model_struct =new TreeModel();
    m_model_dataType=new TreeModel();

    ui->edt_name->setReadOnly(true);
    ui->edt_createUser->setReadOnly(true);
    ui->date_createTime->setReadOnly(true);
    ui->cbx_category->setEnabled(false);
    ui->edt_description->setReadOnly(true);

    //设置树形结构
    set_treeView_model();
    set_dataType_model();
    //加载协议库列表
    init_PortocolList();
}
//设置协议列表树形
void ProjectBuild::set_treeView_model()
{
    m_model->clear();
    //m_model->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("插件名称")<<QStringLiteral("编号")<<QStringLiteral("版本")<<QStringLiteral("类型")<<QStringLiteral("分类"));
    ui->treeView->setModel(m_model);
    ui->cbx_category->clear();
    //添加根节点
    foreach(CATEGORY_INFO *categoryItem,HConfigManage::getInstance()->m_categoryList)
    {
        QStandardItem *item = new QStandardItem(categoryItem->categoryName);
        item->setEditable(false);
        item->setData(categoryItem->categoryId,ItemDataUserRoleCategory::CategoryId);
        item->setData(categoryItem->categoryName,ItemDataUserRoleCategory::CategoryName);
        item->setData(categoryItem->categoryDescription,ItemDataUserRoleCategory::CategoryDescription);
        m_model->appendRow(item);
        ui->cbx_category->addItem(categoryItem->categoryName);
    }
    //设置列
    //ui->treeView->setHeaderHidden(true);
    ui->treeView->setAnimated(true);
    ui->treeView->expandAll();
}
//设置数据类型表格
void ProjectBuild::set_dataType_model()
{
    m_model_dataType->clear();
    m_model_dataType->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("序号")<<QStringLiteral("数据类型")<<QStringLiteral("有/无符号")<<QStringLiteral("系统数据类型"));

    m_model_struct->clear();
    m_model_struct->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("序号")<<QStringLiteral("数据类型")<<QStringLiteral("位定义")<<QStringLiteral("字段定义")<<QStringLiteral("字段描述")<<QStringLiteral("取值范围")<<QStringLiteral("默认值")<<QStringLiteral("量化"));

    m_listModel->clear();
    ui->listView->setModel(m_listModel);
    ui->listView->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑

    ui->tableView_struct->setModel(m_model_struct);
    ui->tableView_struct->verticalHeader()->setVisible(false);
    ui->tableView_struct->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
    ui->tableView_struct->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    ui->tableView_struct->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应宽度

    ui->tableView_dataType->setModel(m_model_dataType);
    ui->tableView_dataType->verticalHeader()->setVisible(false);
    ui->tableView_dataType->setSelectionBehavior(QAbstractItemView::SelectRows);//整行选中
    ui->tableView_dataType->setEditTriggers(QAbstractItemView::NoEditTriggers);//不可编辑
    ui->tableView_dataType->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);//自适应宽度
    //ui->tableView_dataType->resizeColumnsToContents();
}
//初始化协议列表
void ProjectBuild::init_PortocolList()
{
    ui->edt_name->setText("");
    ui->edt_description->setText("");
    ui->edt_createUser->setText("");
    ui->date_createTime->setDate(QDate::currentDate());
    ui->cbx_category->setCurrentIndex(0);

    foreach(HWIDGET_PLU_INFO *pluItem,HConfigManage::getInstance()->m_wndList)
    {
        QStandardItem *item = new QStandardItem(pluItem->pluIcon,pluItem->pluName);
        item->setEditable(false);
        item->setData(pluItem->pluId,ItemDataUserRoleProtocol::ProtocolId);
        item->setData(pluItem->pluName,ItemDataUserRoleProtocol::ProtocolName);
        item->setData(pluItem->pluCategory,ItemDataUserRoleProtocol::ProtocolCategory);
        item->setData(pluItem->pluCreateUser,ItemDataUserRoleProtocol::ProtocolCreateUser);
        item->setData(pluItem->pluCreateTime,ItemDataUserRoleProtocol::ProtocolCreateTime);
        item->setData(pluItem->pluDescription,ItemDataUserRoleProtocol::ProtocolDescription);
        item->setData(pluItem->pluVersion,ItemDataUserRoleProtocol::ProtocolVersion);

        QList<QStandardItem *> itemRoot=m_model->findItems(pluItem->pluCategory);
        if(itemRoot.size()>0)
        {
            itemRoot[0]->appendRow(item);
        }
    }
}
//点击协议列表，查看协议详情
void ProjectBuild::on_treeView_clicked(const QModelIndex &index)
{
    if(index.parent().row()==-1)
        return;
    ui->edt_name->setText("");
    ui->edt_description->setText("");
    ui->edt_createUser->setText("");
    ui->date_createTime->setDate(QDate::currentDate());
    ui->cbx_category->setCurrentIndex(0);

    ui->edt_StructName->setText("");
    ui->edt_StructDescription->setText("");
    ui->edt_StructMark->setText("");

    m_protocol_id = index.data(ItemDataUserRoleProtocol::ProtocolId).toString();
    QSqlDatabase databaseSQLite;
    databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
    databaseSQLite.setDatabaseName("sysdata.db");
    if (!databaseSQLite.open())
    {
        qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
        return;
    }
    else
    {
        ui->edt_name->setText(index.data(ItemDataUserRoleProtocol::ProtocolName).toString());
        ui->edt_description->setText(index.data(ItemDataUserRoleProtocol::ProtocolDescription).toString());
        ui->edt_createUser->setText(index.data(ItemDataUserRoleProtocol::ProtocolCreateUser).toString());
        ui->date_createTime->setDate(QDate::fromString(index.data(ItemDataUserRoleProtocol::ProtocolCreateTime).toString(),"yyyy-MM-dd"));
        ui->cbx_category->setCurrentIndex(ui->cbx_category->findText(index.data(ItemDataUserRoleProtocol::ProtocolCategory).toString()));
    }
    m_listModel->clear();
//    m_model_struct->clear();
//    m_model_dataType->clear();
//    m_model_dataType->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("序号")<<QStringLiteral("数据类型")<<QStringLiteral("有/无符号")<<QStringLiteral("系统数据类型"));
//    m_model_struct->setHorizontalHeaderLabels(QStringList()<<QStringLiteral("序号")<<QStringLiteral("数据类型")<<QStringLiteral("位定义")<<QStringLiteral("字段定义")<<QStringLiteral("字段描述")<<QStringLiteral("取值范围")<<QStringLiteral("默认值")<<QStringLiteral("量化"));
    init_dataTypeList(m_protocol_id);
    init_structList(m_protocol_id);
}
//显示协议数据类型
void ProjectBuild::init_dataTypeList(QString prototcolId)
{
//    set_dataType_model();
    m_model_dataType->removeRows(0,m_model_dataType->rowCount());
    //连接SQLite，打开数据库，读取协议库信息
    QSqlDatabase databaseSQLite;
    databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
    databaseSQLite.setDatabaseName("sysdata.db");
    if (!databaseSQLite.open())
    {
        qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
        return;
    }
    else
    {
        //查询数据类型
        QSqlQuery sql_querySQLite;
        QString strSQLite=QString("select id,protocol_entity_id,name,signed,system_dataType from protocol_dataType_entity where protocol_entity_id='%1'").arg(prototcolId);
        if(!sql_querySQLite.exec(strSQLite))
        {
            qDebug() << sql_querySQLite.lastError();
            return;
        }
        else
        {
            index=1;
            while(sql_querySQLite.next())
            {
                QString strIndex= QString::number(index++);
                QString strId= sql_querySQLite.value(0).toString();
                QString strProtocolId= sql_querySQLite.value(1).toString();
                QString strName = sql_querySQLite.value(2).toString();
                QString strSigned= sql_querySQLite.value(3).toString();
                QString strSystemDataType = sql_querySQLite.value(4).toString();

                QStandardItem *itemIndex = new QStandardItem(strIndex);
                itemIndex->setData(strId,ItemDataUserRoleDataType::DataTypeId);
                itemIndex->setData(strProtocolId,ItemDataUserRoleDataType::DataTypeProtocolId);
                itemIndex->setData(strName,ItemDataUserRoleDataType::DataTypeName);
                itemIndex->setData(strSigned,ItemDataUserRoleDataType::DataTypeSigned);
                itemIndex->setData(strSystemDataType,ItemDataUserRoleDataType::DataTypeSystemDataType);

                //itemIndex->setEditable(false);

                QStandardItem *itemName = new QStandardItem(strName);
//                itemName->setData(strId,Qt::UserRole+1);
                //itemName->setEditable(false);

                QStandardItem *itemSigned = new QStandardItem(strSigned);
                //itemSigned->setEditable(false);

                QStandardItem *itemSystemDataType = new QStandardItem(strSystemDataType);
                //itemSystemDataType->setEditable(false);

                QList<QStandardItem *> rowItems;
                rowItems <<itemIndex<<itemName<<itemSigned<<itemSystemDataType;

                m_model_dataType->appendRow(rowItems);
            }
        }

//        //查询结构体名称
//        strSQLite=QString("select id,name,description from protocol_struct_entity where protocol_entity_id='%1'").arg(prototcolId);
//        if(!sql_querySQLite.exec(strSQLite))
//        {
//            qDebug() << sql_querySQLite.lastError();
//            return;
//        }
//        else
//        {
//            while(sql_querySQLite.next())
//            {
//                QString strId= sql_querySQLite.value(0).toString();
//                QString strName = sql_querySQLite.value(1).toString();
//                QString strDescription = sql_querySQLite.value(2).toString();

//                item = new QStandardItem(strName);
//                item->setData(strId,ItemDataUserRoleStruct::StructId);
//                item->setData(strName,ItemDataUserRoleStruct::StructName);
//                item->setData(strDescription,ItemDataUserRoleStruct::StructDescription);
//                m_listModel->appendRow(item);
//            }
//        }

//        ui->listView->setModel(m_listModel);
    }
    databaseSQLite.close();
}
//显示协议结构体
void ProjectBuild::init_structList(QString prototcolId)
{
    m_model_struct->removeRows(0,m_model_struct->rowCount());
    m_listModel->removeRows(0,m_listModel->rowCount());
    //连接SQLite，打开数据库，读取协议库信息
    QSqlDatabase databaseSQLite;
    databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
    databaseSQLite.setDatabaseName("sysdata.db");
    if (!databaseSQLite.open())
    {
        qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
        return;
    }
    else
    {
        //查询结构体名称
        QSqlQuery sql_querySQLite;
        QString strSQLite=QString("select id,name,description,mark from protocol_struct_entity where protocol_entity_id='%1'").arg(prototcolId);
        if(!sql_querySQLite.exec(strSQLite))
        {
            qDebug() << sql_querySQLite.lastError();
            return;
        }
        else
        {
            while(sql_querySQLite.next())
            {
                QString strId= sql_querySQLite.value(0).toString();
                QString strName = sql_querySQLite.value(1).toString();
                QString strDescription = sql_querySQLite.value(2).toString();
                QString strMark = sql_querySQLite.value(3).toString();

                item = new QStandardItem(strName);
                item->setData(strId,ItemDataUserRoleStruct::StructId);
                item->setData(strName,ItemDataUserRoleStruct::StructName);
                item->setData(strDescription,ItemDataUserRoleStruct::StructDescription);
                item->setData(strMark,ItemDataUserRoleStruct::StructMark);
                m_listModel->appendRow(item);
            }
        }

//        ui->listView->setModel(m_listModel);
    }
    databaseSQLite.close();
}

//左侧树-右键菜单
void ProjectBuild::on_treeView_customContextMenuRequested(const QPoint &pos)
{
    QMenu *menu = new QMenu(this);

    QModelIndex curIndex=ui->treeView->currentIndex();
    if(curIndex.parent().row()==-1)
    {
        menu->addAction(QString("修改协议类型"), this, SLOT(on_treeView_showEditTypeContextMenu()));
        menu->addAction(QString("删除协议类型"), this, SLOT(on_treeView_showDeleteTypeContextMenu()));
        menu->addAction(QString("导入XML"), this, SLOT(on_treeView_showImportXMLContextMenu()));
    }
    else
    {
        on_treeView_clicked(ui->treeView->currentIndex());
        menu->addAction(QString("修改协议"), this, SLOT(on_treeView_showEditProtocolContextMenu()));
        menu->addAction(QString("删除协议"), this, SLOT(on_treeView_showDeleteProtocolContextMenu()));
        menu->addAction(QString("导出协议"), this, SLOT(on_treeView_showExportProtocolContextMenu()));
        menu->addAction(QString("导出XML"), this, SLOT(on_treeView_showExportXMLContextMenu()));
    }
    menu->exec(QCursor::pos());
}
//修改协议类型(右键菜单)
void ProjectBuild::on_treeView_showEditTypeContextMenu()
{
    QModelIndex curIndex=ui->treeView->currentIndex();
    if(curIndex.row()==-1){
        return;
    }

    QStandardItem *item=m_model->item(curIndex.row());

    QString strId=curIndex.data(ItemDataUserRoleCategory::CategoryId).toString();
    QString strName=curIndex.data(ItemDataUserRoleCategory::CategoryName).toString();
    QString strDescription=curIndex.data(ItemDataUserRoleCategory::CategoryDescription).toString();

    CategoryEdit *categoryEdit=new CategoryEdit(this);
    categoryEdit->setAttribute(Qt::WA_DeleteOnClose, true);//窗口接受了关闭事件后，Qt会释放这个窗口所占用的资源。
    connect(categoryEdit,SIGNAL(setCategoryInfo(QString,QString,QString)),this,SLOT(getCategoryInfo(QString,QString,QString)));
    categoryEdit->setModal(true);
    QStringList ql;
    ql<<strName<<strDescription<<strId;
    categoryEdit->sendData(ql);
    if(categoryEdit->exec()==QDialog::Accepted)
    {
        foreach(CATEGORY_INFO *categoryItem,HConfigManage::getInstance()->m_categoryList)
        {
            if(categoryItem->categoryId==categoryId)
            {
                categoryItem->categoryName=categoryName;
                categoryItem->categoryDescription=categoryDescription;
                break;
            }
        }

        //HWindowApi::getInstance()->refreshProtocol();
//        set_treeView_model();
//        init_PortocolList();

//        m_model_dataType->removeRows(0,m_model_dataType->rowCount());
//        m_model_struct->removeRows(0,m_model_struct->rowCount());
//        m_listModel->removeRows(0,m_listModel->rowCount());


        //QStandardItem *item=new QStandardItem(categoryName);
        item->setText(categoryName);
        item->setData(categoryId,ItemDataUserRoleCategory::CategoryId);
        item->setData(categoryName,ItemDataUserRoleCategory::CategoryName);
        item->setData(categoryDescription,ItemDataUserRoleCategory::CategoryDescription);

        //m_model.->setData(curIndex,categoryName);
    }
}
//删除协议类型(右键菜单)
void ProjectBuild::on_treeView_showDeleteTypeContextMenu()
{
     QModelIndex curIndex=ui->treeView->currentIndex();
     if(curIndex.row() == -1)
         return;
     QString strId=curIndex.data(ItemDataUserRoleCategory::CategoryId).toString();
     QSqlDatabase databaseSQLite;
     databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
     databaseSQLite.setDatabaseName("sysdata.db");
     if (!databaseSQLite.open())
     {
         qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
         return;
     }
     else
     {       
         //开启事务
         databaseSQLite.transaction();
         bool sqlOK=false;
         QSqlQuery sql_querySQLite;
         QString strSQL=QString("DELETE FROM category_entity WHERE id = '%1'").arg(strId);
         //执行SQL
         sqlOK=sql_querySQLite.exec(strSQL);

         strSQL=QString("select id from protocol_entity where category_entity_id='%1'").arg(strId);
         //执行SQL
         sqlOK=sql_querySQLite.exec(strSQL);
         if(sqlOK)
         {
             while(sql_querySQLite.next())
             {
                 QString strProtocolId= sql_querySQLite.value(0).toString();

                 strSQL=QString("DELETE FROM protocol_entity WHERE id = '%1'").arg(strProtocolId);
                 //执行SQL
                 sqlOK=sql_querySQLite.exec(strSQL);

                 strSQL=QString("DELETE FROM protocol_dataType_entity WHERE protocol_entity_id = '%1'").arg(strProtocolId);
                 //执行SQL
                 sqlOK=sql_querySQLite.exec(strSQL);

                 strSQL=QString("DELETE FROM protocol_struct_entity WHERE protocol_entity_id = '%1'").arg(strProtocolId);
                 //执行SQL
                 sqlOK=sql_querySQLite.exec(strSQL);

                 strSQL=QString("DELETE FROM struct_data_entity WHERE protocol_entity_id = '%1'").arg(strProtocolId);
                 //执行SQL
                 sqlOK=sql_querySQLite.exec(strSQL);
             }
         }

         //判断是否提交事务
         if(sqlOK)
         {
             //事务提交
             databaseSQLite.commit();
             m_model->removeRow(curIndex.row(),curIndex.parent());
             m_model_dataType->removeRows(0,m_model_dataType->rowCount());
             m_model_struct->removeRows(0,m_model_struct->rowCount());
             m_listModel->removeRows(0,m_listModel->rowCount());
             QMessageBox::information(this,tr("提示"),tr("删除成功!"),tr("确定"));
         }else
         {
             qDebug()<<strSQL;
             qDebug()<<sql_querySQLite.lastError();
             //事务回滚
             databaseSQLite.rollback();
             QMessageBox::warning(this,tr("警告"),tr("删除失败！"),tr("确定"));
         }
     }
     databaseSQLite.close();
}
//修改协议(右键菜单)
void ProjectBuild::on_treeView_showEditProtocolContextMenu()
{
    int row=ui->treeView->currentIndex().row();
    if(row==-1){
        return;
    }
    ComponentEdit *componentEdit=new ComponentEdit(this);
    componentEdit->setAttribute(Qt::WA_DeleteOnClose, true);//窗口接受了关闭事件后，Qt会释放这个窗口所占用的资源。
    componentEdit->setModal(true);
    QStringList ql;
    ql<<ui->edt_name->text()<<ui->edt_description->toPlainText()<<ui->cbx_category->currentText()<<ui->edt_createUser->text()<<ui->date_createTime->text()<<m_protocol_id;
    componentEdit->sendData(ql);
    if(componentEdit->exec()==QDialog::Accepted)
    {
        HWindowApi::getInstance()->refreshProtocol();
        set_treeView_model();
        init_PortocolList();

        m_model_dataType->removeRows(0,m_model_dataType->rowCount());
        m_model_struct->removeRows(0,m_model_struct->rowCount());
        m_listModel->removeRows(0,m_listModel->rowCount());
    }
}
//删除协议(右键菜单)
void ProjectBuild::on_treeView_showDeleteProtocolContextMenu()
{
     QModelIndex curIndex=ui->treeView->currentIndex();
     if(curIndex.row() == -1)
         return;
     QString strProtocolId=curIndex.data(ItemDataUserRoleProtocol::ProtocolId).toString();
     QSqlDatabase databaseSQLite;
     databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
     databaseSQLite.setDatabaseName("sysdata.db");
     if (!databaseSQLite.open())
     {
         qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
         return;
     }
     else
     {
         //开启事务
         databaseSQLite.transaction();
         bool sqlOK=false;
         QSqlQuery sql_querySQLite;
         QString strSQL=QString("DELETE FROM protocol_entity WHERE id = '%1'").arg(strProtocolId);
         //执行SQL
         sqlOK=sql_querySQLite.exec(strSQL);

         strSQL=QString("DELETE FROM protocol_dataType_entity WHERE protocol_entity_id = '%1'").arg(strProtocolId);
         //执行SQL
         sqlOK=sql_querySQLite.exec(strSQL);

         strSQL=QString("DELETE FROM protocol_struct_entity WHERE protocol_entity_id = '%1'").arg(strProtocolId);
         //执行SQL
         sqlOK=sql_querySQLite.exec(strSQL);

         strSQL=QString("DELETE FROM struct_data_entity WHERE protocol_entity_id = '%1'").arg(strProtocolId);
         //执行SQL
         sqlOK=sql_querySQLite.exec(strSQL);

         //判断是否提交事务
         if(sqlOK)
         {
             //事务提交
             databaseSQLite.commit();
             m_model->removeRow(curIndex.row(),curIndex.parent());
             m_model_dataType->removeRows(0,m_model_dataType->rowCount());
             m_model_struct->removeRows(0,m_model_struct->rowCount());
             m_listModel->removeRows(0,m_listModel->rowCount());
             QMessageBox::information(this,tr("提示"),tr("删除成功!"),tr("确定"));
         }else
         {
             qDebug()<<strSQL;
             qDebug()<<sql_querySQLite.lastError();
             //事务回滚
             databaseSQLite.rollback();
             QMessageBox::warning(this,tr("警告"),tr("删除失败！"),tr("确定"));
         }
     }
     databaseSQLite.close();
}
//导出协议(右键菜单)
void ProjectBuild::on_treeView_showExportProtocolContextMenu()
{
    int row=ui->treeView->currentIndex().parent().row();
    if(row==-1)
        return;
    //导出协议
    QString rootPath = QFileDialog::getExistingDirectory(nullptr, "选择协议生成位置路径","/");
    if (rootPath.isEmpty())
        return;
    QString strComponentName=ui->treeView->currentIndex().data().toString();
    QString strFileComponentName=strComponentName;

    QDir dir;

    QString pathExport = rootPath+"\\"+strFileComponentName;

    dir.setPath(pathExport);

  ///begin fix///////////////////////////////////////////zhaoz
    //如果目录已存在，则删除该目录
    //dir.removeRecursively();

    QFileInfo xmldir(pathExport);
    if(xmldir.isDir()){    //文件夹已存在
        //继续判断文件是否存在
        QFileInfo filedoc(pathExport+"/数据.doc");
        QFileInfo fileuserH(pathExport+"/userdefstruct.h");
        if(filedoc.isFile()||fileuserH.isFile())
        {
            int ret = QMessageBox::warning(this, "警告","协议文件已存在，是否覆盖?",QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Cancel);
            if(QMessageBox::Cancel==ret)
                return;
            else {
               //先删除
                QFile::remove(pathExport+"/数据.doc");
                QFile::remove(pathExport+"/userdefstruct.h");
                exportProtocol(pathExport);
            }
        }
        else {
             exportProtocol(pathExport);
        }
    }
    else {
        //在指定路径建立项目目录Project
        if(dir.mkdir(pathExport))
        {
          exportProtocol(pathExport);
        }
    }
    ///end
}
void ProjectBuild::exportProtocol(QString pathExport)
{
    QString strParent=ui->treeView->currentIndex().parent().data().toString();
    QFile file(pathExport+"/数据.doc" );
    file.open( QIODevice::ReadWrite | QIODevice::Text );
    file.close();

    //--------------------导出word文件-------------------------
    ac = new ExportFile();
    QStringList dl;
    QString html = "";
    QString text="<br/>一、协议基本信息<br>协议名称："+ui->treeView->currentIndex().data().toString()+"<br/>协议描述："+ui->edt_description->toPlainText()+"<br/>创建人："+ui->edt_createUser->text()+"<br/>创建时间："+ui->date_createTime->text();
    text += "<br/><br/>二、自定义数据类型<br/>";
    for (int i = -1;i<m_model_dataType->rowCount();i++) {
        for (int j = 0;j<m_model_dataType->columnCount();j++) {
            if(i<0){
                dl<<m_model_dataType->headerData(j,Qt::Horizontal).toString();
            }else {
                dl<<m_model_dataType->item(i,j)->text();
            }
        }
    }

    html += ac->CreatText(text);
    html += ac->CreatForm(m_model_dataType->rowCount()+1,4,dl,"数据类型");
    text = "<br/>三、结构体";
    html += ac->CreatText(text);
    for (int i = 0;i<m_listModel->rowCount();i++) {
        text ="<br/>3."+QString::number(i+1) + " " +  m_listModel->item(i)->text() + "结构体";
        text +="<br/>结构体描述："+  m_listModel->item(i)->data(ItemDataUserRoleStruct::StructDescription).toString();
        if(m_listModel->item(i)->data(ItemDataUserRoleStruct::StructMark).toString()!=""){
            text +="<br/>结构体标识："+  m_listModel->item(i)->data(ItemDataUserRoleStruct::StructMark).toString();
        }
        html += ac->CreatText(text);
        on_listView_clicked(m_listModel->index(i,0));
        QStringList sl;
        for (int m = -1;m<m_model_struct->rowCount();m++) {
            for (int n = 0;n<m_model_struct->columnCount();n++) {
                if(m<0){
                    sl<<m_model_struct->headerData(n,Qt::Horizontal).toString();
                }else{
                    sl<<m_model_struct->item(m,n)->text();
                }
            }
        }
        html += ac->CreatForm(m_model_struct->rowCount(),8,sl,"");
    }

    ac->OutputWord(pathExport+"/数据.doc",ui->treeView->currentIndex().data().toString(),html);
    delete ac;
    //--------------------导出word文件-------------------------

    //--------------------导出h文件-------------------------
    QString exportH = "";
    exportH.append("#ifndef USERDEFSTRUCT_H\n");
    exportH.append("#define USERDEFSTRUCT_H\n\n\n\n");

//    for(int i=0;i<m_model_dataType->rowCount();i++){
//        QStandardItem *curItem=m_listModel->item(i,0);
//        if(curItem){
//            exportH.append("typedef ");
//            exportH.append(curItem->data(ItemDataUserRoleDataType::DataTypeSigned).toString()+" ");
//            exportH.append(curItem->data(ItemDataUserRoleDataType::DataTypeSystemDataType).toString()+" ");
//            exportH.append(curItem->data(ItemDataUserRoleDataType::DataTypeName).toString()+";\n");
//        }
//    }
    for (int i = 0;i<m_model_dataType->rowCount();i++) {
           dl<<m_model_dataType->item(i,1)->text();
        exportH.append("typedef ");
        exportH.append(m_model_dataType->item(i,2)->text()+" ");
        exportH.append(m_model_dataType->item(i,3)->text()+" ");
        exportH.append(m_model_dataType->item(i,1)->text()+";\n");
    }

    exportH.append("\n#pragma pack(1);    // 按照1字节对齐\n\n\n\n");

    for(int i = 0;i<m_listModel->rowCount();i++){
        QStandardItem *curItem=m_listModel->item(i,0);
        if(curItem){
            exportH.append("// "+curItem->data(ItemDataUserRoleStruct::StructMark).toString()+"  "+curItem->data(ItemDataUserRoleStruct::StructDescription).toString()+"\n");
            exportH.append("typedef struct\n{\n");

            on_listView_clicked(m_listModel->index(i,0));
            for (int j = 0;j<m_model_struct->rowCount();j++) {
                QStandardItem *curItemDetail=m_model_struct->item(j,0);
                if(curItemDetail){
                    QString strId= curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailId).toString();
                    QString strProtocolId= curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailProtocolId).toString();
                    QString strStructId= curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailStructId).toString();
                    QString strDataTypeId= curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailDataTypeId).toString();
                    QString strDataTypeName = curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailDataTypeName).toString();
                    QString strBit= curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailBit).toString();
                    QString strName = curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailName).toString();
                    QString strDescription = curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailDescription).toString();
                    QString strRange = curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailRange).toString();
                    QString strDefaultValue = curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailDefaultValue).toString();
                    QString strQuantization = curItemDetail->data(ItemDataUserRoleStructDetail::StructDetailQuantization).toString();

                    exportH.append("    "+strDataTypeName+" "+strName);

                    if(!strBit.isEmpty() && strBit!="0")
                    {
                        exportH.append("    : "+strBit);
                    }
                    exportH.append(";  // "+strDescription);

                    if(!strRange.isEmpty())
                    {
                        exportH.append(",取值范围：" + strRange);
                    }

                    if(!strDefaultValue.isEmpty())
                    {
                        exportH.append(",默认值：" + strDefaultValue);
                    }

                    if(!strQuantization.isEmpty())
                    {
                        exportH.append(",量化：" + strQuantization);
                    }

                    exportH.append( "\n" );
                }
            }


    //            QSqlDatabase databaseSQLite;
    //            databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
    //            databaseSQLite.setDatabaseName("sysdata.db");
    //            if (!databaseSQLite.open())
    //            {
    //                qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
    //                return;
    //            }
    //            else
    //            {
    //                QSqlQuery sql_querySQLite;
    //                QString strSQLite=QString("SELECT sde.id,sde.protocol_entity_id,sde.struct_entity_id,sde.datatype_entity_id,pde.name,sde.bit,sde.name,sde.description,sde.range,sde.defaultvalue,sde.quantization FROM struct_data_entity AS sde INNER JOIN protocol_dataType_entity AS pde on pde.id=sde.datatype_entity_id  WHERE sde.struct_entity_id = '%1'")
    //                        .arg(curItem->data(ItemDataUserRoleStruct::StructId).toString());

    //                if(!sql_querySQLite.exec(strSQLite))
    //                {
    //                    qDebug() << sql_querySQLite.lastError();
    //                }
    //                else
    //                {
    //                    m_index_struct = 1;
    //                    while (sql_querySQLite.next()) {
    //                        QString strIndex= QString::number(m_index_struct++);
    //                        QString strId= sql_querySQLite.value(0).toString();
    //                        QString strProtocolId= sql_querySQLite.value(1).toString();
    //                        QString strStructId= sql_querySQLite.value(2).toString();
    //                        QString strDataTypeId= sql_querySQLite.value(3).toString();
    //                        QString strDataTypeName = sql_querySQLite.value(4).toString();
    //                        QString strBit= sql_querySQLite.value(5).toString();
    //                        QString strName = sql_querySQLite.value(6).toString();
    //                        QString strDescription = sql_querySQLite.value(7).toString();
    //                        QString strRange = sql_querySQLite.value(8).toString();
    //                        QString strDefaultValue = sql_querySQLite.value(9).toString();
    //                        QString strQuantization = sql_querySQLite.value(10).toString();

    //                        exportH.append("    "+strDataTypeName+" "+strName);

    //                        if(!strBit.isEmpty() && strBit!="0")
    //                        {
    //                            exportH.append("    : "+strBit);
    //                        }
    //                        exportH.append(";  // "+strDescription);

    //                        if(!strRange.isEmpty())
    //                        {
    //                            exportH.append(",取值范围：" + strRange);
    //                        }

    //                        if(!strDefaultValue.isEmpty())
    //                        {
    //                            exportH.append(",默认值：" + strDefaultValue);
    //                        }

    //                        if(!strQuantization.isEmpty())
    //                        {
    //                            exportH.append(",量化：" + strQuantization);
    //                        }

    //                        exportH.append( "\n" );
    //                    }
    //                }
    //            }

            exportH.append("} "+curItem->data(ItemDataUserRoleStruct::StructName).toString()+";\n\n\n");
        }
    }

    exportH.append("\n#pragma pack(1)\n");
    exportH.append("#endif // USERDEFSTRUCT_H");

    QFile fileH(pathExport+"/userdefstruct.h");
    fileH.open( QIODevice::ReadWrite | QIODevice::Text );
    QTextStream in(&fileH);
    in.seek(fileH.size());
    in.setCodec("UTF-8");
    in<<QChar(QChar::ByteOrderMark);
    in<<exportH;
    in.flush();
    fileH.close();
    //--------------------导出h文件-------------------------

    QMessageBox::information(this,"提示","协议导出成功！");
}
//导入XML(右键菜单)
void ProjectBuild::on_treeView_showImportXMLContextMenu()
{
    QStringList fileNames;
    QFileDialog * fileDialog=new QFileDialog(this);
    fileDialog->setWindowTitle("打开文件");
    fileDialog->setDirectory(".");
    fileDialog->setNameFilter(tr("xml文件(*.xml)"));
    fileDialog->setViewMode(QFileDialog::Detail);
    if(fileDialog->exec())
    {
        fileNames=fileDialog->selectedFiles();
    }
    //导入协议 
    if (fileNames.isEmpty())
        return;
    QDomDocument dom;
    QFile r_file(fileNames[0]);
    if (!r_file.open( QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    dom.setContent(&r_file);
    r_file.close();

    QDomElement root = dom.documentElement();
    QString root_name = root.tagName();
    //判断XML头格式<protocal>
    if (root_name == "protocal")
    {
        QModelIndex curIndex=ui->treeView->currentIndex();
        if(curIndex.parent().row()!=-1){
            return;
        }

        QSqlDatabase databaseSQLite;
        databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
        databaseSQLite.setDatabaseName("sysdata.db");
        if (!databaseSQLite.open())
        {
            qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
            return;
        }
        //开启事务
        databaseSQLite.transaction();
        bool sqlOK=false;
        QSqlQuery sql_querySQLite;
        //开始插入协议
        QUuid id = QUuid::createUuid();
        QString strProtocolId = id.toString().replace("{","").replace("}","");
        QString strProtocolName=root.attributeNode("name").value();
        QString strProtocolDescription=root.attributeNode("description").value();
        QString strProtocolCreateUser=root.attributeNode("createUser").value();
        QString strProtocolCreateTime=root.attributeNode("createTime").value();
        QString strProtocolCategoryId=curIndex.data(ItemDataUserRoleCategory::CategoryId).toString();
        QString strSQL=QString("INSERT INTO protocol_entity(id,category_entity_id, create_user, create_time, description, name) VALUES ('%1', '%2', '%3', '%4', '%5', '%6')")
                .arg(strProtocolId).arg(strProtocolCategoryId).arg(strProtocolCreateUser).arg(strProtocolCreateTime).arg(strProtocolDescription).arg(strProtocolName);
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);

        QDomNodeList categoryList = root.childNodes();
        //第一层子节点内容
        for (int i = 0;i < categoryList.count();++i)
        {
            QDomNode dom_CategoryNode = categoryList.item(i);
            QDomElement elementCategory = dom_CategoryNode.toElement();
            if(elementCategory.nodeName()=="dataType")
            {
                QDomNodeList dataTypeList = elementCategory.childNodes();
                if(dataTypeList.count()<=0)
                    continue;
                //第二层<dataType>子节点内容
                for (int j = 0;j < dataTypeList.count();++j)
                {
                    QDomNode dom_dataTypeNode = dataTypeList.item(j);
                    QDomElement elemenDataType = dom_dataTypeNode.toElement();
                    if(elemenDataType.nodeName()=="dataTypeItem")
                    {
                        //开始插入数据类型
                        QUuid id = QUuid::createUuid();
                        QString strDataTypeId = id.toString().replace("{","").replace("}","");
                        QString strDataTypeName = elemenDataType.attributeNode("dataType").value();
                        QString strSigned = elemenDataType.attributeNode("signed").value();
                        QString strSystemDataType = elemenDataType.attributeNode("systemDataType").value();
                        QString strSQL=QString("INSERT INTO protocol_dataType_entity(id,protocol_entity_id, name, signed, system_dataType) VALUES ('%1', '%2', '%3', '%4', '%5')")
                                .arg(strDataTypeId).arg(strProtocolId).arg(strDataTypeName).arg(strSigned).arg(strSystemDataType);
                        //执行SQL
                        sqlOK=sql_querySQLite.exec(strSQL);
                    }
                }
            }
            else if(elementCategory.nodeName()=="struct")
            {
                //开始插入结构体
                QUuid id = QUuid::createUuid();
                QString strStructId = id.toString().replace("{","").replace("}","");
                QString strStructName = elementCategory.attributeNode("name").value();
                QString strStructDescription = elementCategory.attributeNode("description").value();
                QString strStructMark = elementCategory.attributeNode("mark").value();
                QString strSQLite=QString("INSERT INTO protocol_struct_entity(id,protocol_entity_id,name,description,mark) VALUES ('%1', '%2', '%3', '%4', '%5');")
                        .arg(strStructId).arg(strProtocolId).arg(strStructName).arg(strStructDescription).arg(strStructMark);
                //执行SQL
                sqlOK=sql_querySQLite.exec(strSQLite);qDebug()<<strSQLite;

                QDomNodeList structList = elementCategory.childNodes();
                if(structList.count()<=0)
                    continue;
                //第二层<dataType>子节点内容
                for (int j = 0;j < structList.count();++j)
                {
                    QDomNode dom_structNode = structList.item(j);
                    QDomElement elemenStruct = dom_structNode.toElement();
                    if(elemenStruct.nodeName()=="structItem")
                    {
                        //开始插入结构体详情
                        QUuid id = QUuid::createUuid();
                        QString strStructDetailId = id.toString().replace("{","").replace("}","");
                        QString strStructDetailDataType = elemenStruct.attributeNode("dataType").value();
                        QString strStructDetailDataTypeId = "";
                        QString strSQLite=QString("select id from protocol_dataType_entity where name='%1'").arg(strStructDetailDataType);
                        if(!sql_querySQLite.exec(strSQLite))
                        {
                            qDebug() << sql_querySQLite.lastError();
                            return;
                        }
                        else
                        {
                            if(sql_querySQLite.next())
                            {
                                strStructDetailDataTypeId= sql_querySQLite.value(0).toString();
                            }
                        }
                        QString strBit = elemenStruct.attributeNode("bit").value();
                        QString strStructDetailName = elemenStruct.attributeNode("name").value();
                        QString strStructDetailDescription = elemenStruct.attributeNode("description").value();
                        QString strRange = elemenStruct.attributeNode("range").value();
                        QString strDefaultValue = elemenStruct.attributeNode("defaultvalue").value();
                        QString strQuantization = elemenStruct.attributeNode("quantization").value();

                        QString strSQL=QString("INSERT INTO struct_data_entity(id,protocol_entity_id,struct_entity_id,dataType_entity_id,bit,name,description,range,defaultvalue,quantization) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10')")
                                .arg(strStructDetailId).arg(strProtocolId).arg(strStructId).arg(strStructDetailDataTypeId).arg(strBit).arg(strStructDetailName).arg(strStructDetailDescription).arg(strRange).arg(strDefaultValue).arg(strQuantization);
                        //执行SQL
                        sqlOK=sql_querySQLite.exec(strSQL);
                    }
                }
            }
        }

        //判断是否提交事务
        if(sqlOK)
        {
            //事务提交
            databaseSQLite.commit();

            HWindowApi::getInstance()->refreshProtocol();
            set_treeView_model();
            init_PortocolList();

            m_model_dataType->removeRows(0,m_model_dataType->rowCount());
            m_model_struct->removeRows(0,m_model_struct->rowCount());
            m_listModel->removeRows(0,m_listModel->rowCount());
            QMessageBox::information(this,tr("提示"),tr("导入成功!"),tr("确定"));
        }else
        {
            qDebug()<<strSQL;
            qDebug()<<sql_querySQLite.lastError();
            //事务回滚
            databaseSQLite.rollback();
            QMessageBox::warning(this,tr("警告"),tr("导入失败！"),tr("确定"));
        }

        databaseSQLite.close();
    }
}
//导出XML(右键菜单)
void ProjectBuild::on_treeView_showExportXMLContextMenu()
{
    int row=ui->treeView->currentIndex().parent().row();
    if(row==-1)
        return;
    //导出协议
    QString rootPath = QFileDialog::getExistingDirectory(nullptr, "选择协议生成位置路径","/");
    if (rootPath.isEmpty())
        return;
    QString strFileComponentName=ui->treeView->currentIndex().data().toString();

    QDir dir;

    QString pathExport = rootPath+"\\"+strFileComponentName;

    dir.setPath(pathExport);
    ///begin fix///////////////////////////////////////////zhaoz
    QFileInfo xmldir(pathExport);
    if(xmldir.isDir()){//文件夹已存在
        //继续判断文件是否存在
        QFileInfo file(pathExport+"/"+strFileComponentName+".xml" );
        if(file.isFile())
        {
             int r = QMessageBox::warning(this, "警告","文件已存在，是否覆盖?",QMessageBox::Ok|QMessageBox::Cancel, QMessageBox::Cancel);
            if(QMessageBox::Cancel==r)
                return;
            else {
               //先删除
                QFile::remove(pathExport+"/"+strFileComponentName+".xml");
                exportXml(pathExport+"/"+strFileComponentName+".xml");
            }
        }
        else {
             exportXml(pathExport+"/"+strFileComponentName+".xml");
        }
    }
    else{
        //在指定路径建立项目目录Project
        if(dir.mkdir(pathExport))
        {
           exportXml(pathExport+"/"+strFileComponentName+".xml");
        }
    }
    //如果目录已存在，则删除该目录
   // dir.removeRecursively();
///end///////////////////////////////////////////zhaoz
}
void ProjectBuild::exportXml(QString filepath)
{
    QString strParent=ui->treeView->currentIndex().parent().data().toString();
    QFile file(filepath );
    if(file.exists())
    {
        QMessageBox::information(this,"提示","文件已存在，请重新选择！");
        return;
    }
    file.open( QIODevice::ReadWrite | QIODevice::Text );
    //file.close();

    //--------------------导出xml文件-------------------------
    QDomDocument document;
    QString strHeader("version=\"1.0\" encoding=\"UTF-8\"");
    document.appendChild(document.createProcessingInstruction("xml",strHeader));

    QDomElement base_elem = document.createElement("protocal");
    base_elem.setAttribute("name",ui->treeView->currentIndex().data().toString());
    base_elem.setAttribute("description",ui->edt_description->toPlainText());
    base_elem.setAttribute("createUser",ui->edt_createUser->text());
    base_elem.setAttribute("createTime",ui->date_createTime->text());
    document.appendChild(base_elem);

    QDomElement dataType_elem = document.createElement("dataType");
    base_elem.appendChild(dataType_elem);

    for (int i = 0;i<m_model_dataType->rowCount();i++) {
        QDomElement itemDataType = document.createElement("dataTypeItem");
        itemDataType.setAttribute("dataType",m_model_dataType->item(i,1)->text());
        itemDataType.setAttribute("signed",m_model_dataType->item(i,2)->text());
        itemDataType.setAttribute("systemDataType",m_model_dataType->item(i,3)->text());
        dataType_elem.appendChild(itemDataType);
    }

    for (int i = 0;i<m_listModel->rowCount();i++) {
        QDomElement struct_elem = document.createElement("struct");
        struct_elem.setAttribute("name",m_listModel->item(i)->text());
        struct_elem.setAttribute("description",m_listModel->item(i)->data(ItemDataUserRoleStruct::StructDescription).toString());
        struct_elem.setAttribute("mark",m_listModel->item(i)->data(ItemDataUserRoleStruct::StructMark).toString());
        base_elem.appendChild(struct_elem);

        on_listView_clicked(m_listModel->index(i,0));
        QStringList sl;
        for (int m = 0;m<m_model_struct->rowCount();m++) {
            QDomElement itemStruct = document.createElement("structItem");
            itemStruct.setAttribute("dataType",m_model_struct->item(m,1)->text());
            itemStruct.setAttribute("bit",m_model_struct->item(m,2)->text());
            itemStruct.setAttribute("name",m_model_struct->item(m,3)->text());
            itemStruct.setAttribute("description",m_model_struct->item(m,4)->text());
            itemStruct.setAttribute("range",m_model_struct->item(m,5)->text());
            itemStruct.setAttribute("defaultvalue",m_model_struct->item(m,6)->text());
            itemStruct.setAttribute("quantization",m_model_struct->item(m,7)->text());
            struct_elem.appendChild(itemStruct);
        }
    }

    QTextStream out(&file);
    document.save(out,4);
    file.close();

    QMessageBox::information(this,"提示","协议导出成功！");
}
//获取当前编辑的协议类型
void ProjectBuild::getCategoryInfo(QString id,QString name,QString description)
{
    categoryId=id;
    categoryName=name;
    categoryDescription=description;
}
//添加协议类型
void ProjectBuild::on_btnCreateType_clicked()
{
    CategoryEdit *categoryEdit=new CategoryEdit(this);
    categoryEdit->setAttribute(Qt::WA_DeleteOnClose, true);//窗口接受了关闭事件后，Qt会释放这个窗口所占用的资源。
    connect(categoryEdit,SIGNAL(setCategoryInfo(QString,QString,QString)),this,SLOT(getCategoryInfo(QString,QString,QString)));
    categoryEdit->setModal(true);
    if(categoryEdit->exec()==QDialog::Accepted)
    {
        category_info *_info = new category_info;
        _info->categoryId = categoryId;
        _info->categoryName = categoryName;
        _info->categoryDescription = categoryDescription;

        HConfigManage::getInstance()->m_categoryList.push_back(_info);

        QStandardItem *item = new QStandardItem(categoryName);
        item->setEditable(false);        
        item->setData(categoryId,ItemDataUserRoleCategory::CategoryId);
        item->setData(categoryName,ItemDataUserRoleCategory::CategoryName);
        item->setData(categoryDescription,ItemDataUserRoleCategory::CategoryDescription);
        m_model->appendRow(item);
        ui->cbx_category->addItem(categoryName);
    }
}

//添加协议
void ProjectBuild::on_btn_CreateProtocol_clicked()
{
    ComponentEdit *componentEdit=new ComponentEdit(this);
    componentEdit->setAttribute(Qt::WA_DeleteOnClose, true);//窗口接受了关闭事件后，Qt会释放这个窗口所占用的资源。
    componentEdit->setModal(true);
    if(componentEdit->exec()==QDialog::Accepted)
    {
        HWindowApi::getInstance()->refreshProtocol();
        set_treeView_model();
        init_PortocolList();

        m_model_dataType->removeRows(0,m_model_dataType->rowCount());
        m_model_struct->removeRows(0,m_model_struct->rowCount());
        m_listModel->removeRows(0,m_listModel->rowCount());
    }
}
//导出
void ProjectBuild::on_btn_ExportProtocol_clicked()
{
    Export *exportEdit = new Export(this);
    exportEdit->setAttribute(Qt::WA_DeleteOnClose, true);//窗口接受了关闭事件后，Qt会释放这个窗口所占用的资源。
    exportEdit->setModal(true);
    exportEdit->show();

}

//添加数据类型
void ProjectBuild::on_btn_AddDataType_clicked()
{
    QModelIndex curIndex=ui->treeView->currentIndex();
    if(curIndex.row()==-1){
        QMessageBox::warning(this,tr("警告"),tr("请选择协议！"),tr("确定"));
        return;
    }

    DataTypeEdit* dataTypeEdit=new DataTypeEdit(this);
//    connect(dataTypeEdit,SIGNAL(addDataToPage(QStringList)),this,SLOT(recvDataFromPage(QStringList)));
    dataTypeEdit->setAttribute(Qt::WA_DeleteOnClose, true);//窗口接受了关闭事件后，Qt会释放这个窗口所占用的资源。
    dataTypeEdit->setModal(true);

    QString strProtocolId= ui->treeView->currentIndex().data(ItemDataUserRoleProtocol::ProtocolId).toString();

    QStringList ql;
    ql<<""<<""<<""<<""<<strProtocolId;
    dataTypeEdit->sendData(ql);

    if(dataTypeEdit->exec()==QDialog::Accepted)
    {
        int row=ui->treeView->currentIndex().row();
        if(row!=-1)
            init_dataTypeList(ui->treeView->currentIndex().data(Qt::UserRole+1).toString());
    }
}

//修改数据类型
void ProjectBuild::on_btn_EditDataType_clicked()
{
    QModelIndex curIndex=ui->tableView_dataType->currentIndex();
    if(curIndex.row()==-1){
        QMessageBox::warning(this,tr("警告"),tr("请选择要修改的数据类型！"),tr("确定"));
        return;
    }

    DataTypeEdit* dataTypeEdit=new DataTypeEdit(this);
//    connect(dataTypeEdit,SIGNAL(addDataToPage(QStringList)),this,SLOT(recvDataFromPage(QStringList)));
    dataTypeEdit->setAttribute(Qt::WA_DeleteOnClose, true);//窗口接受了关闭事件后，Qt会释放这个窗口所占用的资源。
    dataTypeEdit->setModal(true);

    QString strId= curIndex.siblingAtColumn(0).data(ItemDataUserRoleDataType::DataTypeId).toString();
    QString strProtocolId= curIndex.siblingAtColumn(0).data(ItemDataUserRoleDataType::DataTypeProtocolId).toString();
    QString strName = curIndex.siblingAtColumn(0).data(ItemDataUserRoleDataType::DataTypeName).toString();
    QString strSigned= curIndex.siblingAtColumn(0).data(ItemDataUserRoleDataType::DataTypeSigned).toString();
    QString strSystemDataType = curIndex.siblingAtColumn(0).data(ItemDataUserRoleDataType::DataTypeSystemDataType).toString();

    QStringList ql;
    ql<<strId<<strName<<strSigned<<strSystemDataType<<strProtocolId;
    dataTypeEdit->sendData(ql);
    if(dataTypeEdit->exec()==QDialog::Accepted)
    {
        int row=ui->treeView->currentIndex().row();
        if(row!=-1)
            init_dataTypeList(ui->treeView->currentIndex().data(Qt::UserRole+1).toString());
    }
}

//删除数据类型
void ProjectBuild::on_btn_DeleteDataType_clicked()
{
    QModelIndex curIndex=ui->tableView_dataType->currentIndex();
    if(curIndex.row()==-1){
        QMessageBox::warning(this,tr("警告"),tr("请选择要修改的数据类型！"),tr("是"));
        return;
    }
    int result=QMessageBox::question(this,tr("询问"),tr("是否要删除该数据类型！"),tr("是"),tr("否"));
    if(result==0)//确定删除
    {
        QSqlDatabase databaseSQLite;
        databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
        databaseSQLite.setDatabaseName("sysdata.db");
        if (!databaseSQLite.open())
        {
            qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
            return;
        }
        else
        {
            QSqlQuery sql_querySQLite;
            QString strSQL=QString("DELETE FROM protocol_dataType_entity WHERE id = '%1'").arg(curIndex.siblingAtColumn(0).data(ItemDataUserRoleDataType::DataTypeId).toString());
            if(sql_querySQLite.exec(strSQL)){
                m_model_dataType->removeRow(curIndex.row());
                QMessageBox::information(this,tr("提示"),tr("删除成功!"),tr("确定"));
                return;
            }else{
                QMessageBox::warning(this,tr("警告"),tr("删除失败！"),tr("确定"));
            }
        }
        databaseSQLite.close();
    }
}

//结构体选择
void ProjectBuild::on_listView_clicked(const QModelIndex &index)
{
    ui->edt_StructName->setText(index.data(ItemDataUserRoleStruct::StructName).toString());
    ui->edt_StructDescription->setText(index.data(ItemDataUserRoleStruct::StructDescription).toString());
    ui->edt_StructMark->setText(index.data(ItemDataUserRoleStruct::StructMark).toString());

    m_listRow = index.row();

    init_structDetailList(index.data(ItemDataUserRoleStruct::StructId).toString());
}

//显示结构体详情列表
void ProjectBuild::init_structDetailList(QString structId)
{
    m_model_struct->removeRows(0,m_model_struct->rowCount());

    QSqlDatabase databaseSQLite;
    databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
    databaseSQLite.setDatabaseName("sysdata.db");
    if (!databaseSQLite.open())
    {
        qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
        return;
    }
    else
    {
        QSqlQuery sql_querySQLite;
        QString strSQLite=QString("SELECT sde.id,sde.protocol_entity_id,sde.struct_entity_id,sde.datatype_entity_id,pde.name,sde.bit,sde.name,sde.description,sde.range,sde.defaultvalue,sde.quantization FROM struct_data_entity AS sde INNER JOIN protocol_dataType_entity AS pde on pde.id=sde.datatype_entity_id  WHERE sde.struct_entity_id = '%1'")
                .arg(structId);

        if(!sql_querySQLite.exec(strSQLite))
        {
            qDebug() << sql_querySQLite.lastError();
            return;
        }
        else
        {
            m_index_struct = 1;
            while (sql_querySQLite.next()) {
                QString strIndex= QString::number(m_index_struct++);
                QString strId= sql_querySQLite.value(0).toString();
                QString strProtocolId= sql_querySQLite.value(1).toString();
                QString strStructId= sql_querySQLite.value(2).toString();
                QString strDataTypeId= sql_querySQLite.value(3).toString();
                QString strDataTypeName = sql_querySQLite.value(4).toString();
                QString strBit= sql_querySQLite.value(5).toString();
                QString strName = sql_querySQLite.value(6).toString();
                QString strDescription = sql_querySQLite.value(7).toString();
                QString strRange = sql_querySQLite.value(8).toString();
                QString strDefaultValue = sql_querySQLite.value(9).toString();
                QString strQuantization = sql_querySQLite.value(10).toString();

                QStandardItem *itemIndex = new QStandardItem(strIndex);
                itemIndex->setData(strId,ItemDataUserRoleStructDetail::StructDetailId);
                itemIndex->setData(strProtocolId,ItemDataUserRoleStructDetail::StructDetailProtocolId);
                itemIndex->setData(strStructId,ItemDataUserRoleStructDetail::StructDetailStructId);
                itemIndex->setData(strDataTypeId,ItemDataUserRoleStructDetail::StructDetailDataTypeId);
                itemIndex->setData(strDataTypeName,ItemDataUserRoleStructDetail::StructDetailDataTypeName);
                itemIndex->setData(strBit,ItemDataUserRoleStructDetail::StructDetailBit);
                itemIndex->setData(strName,ItemDataUserRoleStructDetail::StructDetailName);
                itemIndex->setData(strDescription,ItemDataUserRoleStructDetail::StructDetailDescription);
                itemIndex->setData(strRange,ItemDataUserRoleStructDetail::StructDetailRange);
                itemIndex->setData(strDefaultValue,ItemDataUserRoleStructDetail::StructDetailDefaultValue);
                itemIndex->setData(strQuantization,ItemDataUserRoleStructDetail::StructDetailQuantization);

                QStandardItem *itemDataType = new QStandardItem(strDataTypeName);
                QStandardItem *itemBit = new QStandardItem(strBit);
                QStandardItem *itemName = new QStandardItem(strName);
                QStandardItem *itemDescription = new QStandardItem(strDescription);
                QStandardItem *itemRange = new QStandardItem(strRange);
                QStandardItem *itemDefaultValue = new QStandardItem(strDefaultValue);
                QStandardItem *itemQuantization = new QStandardItem(strQuantization);

                QList<QStandardItem *> rowItems;
                rowItems <<itemIndex<<itemDataType<<itemBit<<itemName<<itemDescription<<itemRange<<itemDefaultValue<<itemQuantization;

                m_model_struct->appendRow(rowItems);
            }
        }
    }
}

//添加结构体名称
void ProjectBuild::on_btn_CreateStruct_clicked()
{
    int row=ui->treeView->currentIndex().row();
    if(row==-1){
        QMessageBox::warning(this,tr("警告"),tr("请选择协议！"),tr("确定"));
        return;
    }

    QSqlDatabase databaseSQLite;
    databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
    databaseSQLite.setDatabaseName("sysdata.db");
    if (!databaseSQLite.open())
    {
        qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
        return;
    }
    else
    {
        QSqlQuery sql_querySQLite;
        QString strSQLite=QString("select * from protocol_struct_entity  where name = '%1' and protocol_entity_id='%2'").arg(ui->edt_StructName->text()).arg(m_protocol_id);
        if(!sql_querySQLite.exec(strSQLite))
        {
            qDebug() << sql_querySQLite.lastError();
            return;
        }
        else
        {
            if(sql_querySQLite.next()){
                QMessageBox::warning(this,tr("警告"),tr("结构体已存在！"),tr("确定"));
                return;
            }
            else
            {
                QUuid id = QUuid::createUuid();
                QString strId = id.toString().replace("{","").replace("}","");

                strSQLite=QString("INSERT INTO protocol_struct_entity(id,protocol_entity_id,name,description,mark) VALUES ('%1', '%2', '%3', '%4', '%5');")
                        .arg(strId).arg(m_protocol_id).arg(ui->edt_StructName->text()).arg(ui->edt_StructDescription->text()).arg(ui->edt_StructMark->text());

                if(!sql_querySQLite.exec(strSQLite))
                {
                    qDebug() << sql_querySQLite.lastError();
                    return;
                }
                else
                {
                    QStandardItem *item=new QStandardItem(ui->edt_StructName->text());
                    item->setData(strId,ItemDataUserRoleStruct::StructId);
                    item->setData(ui->edt_StructName->text(),ItemDataUserRoleStruct::StructName);
                    item->setData(ui->edt_StructDescription->text(),ItemDataUserRoleStruct::StructDescription);
                    item->setData(ui->edt_StructMark->text(),ItemDataUserRoleStruct::StructMark);

                    m_listModel->insertRow(m_listModel->rowCount(),item);
                }
            }
        }
    }
    databaseSQLite.close();
}

//删除结构体名称
void ProjectBuild::on_btn_DeleteStruct_clicked()
{
    QModelIndex curIndex=ui->listView->currentIndex();
    if(curIndex.row()==-1){
        QMessageBox::warning(this,tr("警告"),tr("请选择结构体！"),tr("确定"));
        return;
    }
    QString strStructId=curIndex.data(ItemDataUserRoleStruct::StructId).toString();
    QSqlDatabase databaseSQLite;
    databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
    databaseSQLite.setDatabaseName("sysdata.db");
    if (!databaseSQLite.open())
    {
        qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
        return;
    }
    else
    {
        //开启事务
        databaseSQLite.transaction();
        bool sqlOK=false;
        QSqlQuery sql_querySQLite;
        QString strSQL=QString("DELETE FROM protocol_struct_entity WHERE id = '%1'").arg(strStructId);
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);

        strSQL=QString("DELETE FROM struct_data_entity WHERE struct_entity_id = '%1'").arg(strStructId);
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);

        //判断是否提交事务
        if(sqlOK)
        {
            //事务提交
            databaseSQLite.commit();
            m_listModel->removeRow(curIndex.row());
            m_model_struct->removeRows(0,m_model_struct->rowCount());
            QMessageBox::information(this,tr("提示"),tr("删除成功!"),tr("确定"));
        }else
        {
            qDebug()<<strSQL;
            qDebug()<<sql_querySQLite.lastError();
            //事务回滚
            databaseSQLite.rollback();
            QMessageBox::warning(this,tr("警告"),tr("删除失败！"),tr("确定"));
        }
    }
    databaseSQLite.close();
}

//添加结构体明细
void ProjectBuild::on_btn_AddDataType_2_clicked()
{
    if(ui->treeView->currentIndex().row()==-1){
        QMessageBox::warning(this,tr("警告"),tr("请选择协议！"),tr("确定"));
        return;
    }
    if(ui->listView->currentIndex().row()==-1){
        QMessageBox::warning(this,tr("警告"),tr("请选择结构体！"),tr("确定"));
        return;
    }

    StructEdit *pStructEdit = new StructEdit(this);
    pStructEdit->setAttribute(Qt::WA_DeleteOnClose, true);//窗口接受了关闭事件后，Qt会释放这个窗口所占用的资源。
    pStructEdit->setModal(true);

    QStringList ql;
    ql<<""<<""<<""<<""<<""<<""<<""<<""<<ui->listView->currentIndex().data(ItemDataUserRoleStruct::StructId).toString()<<""<<ui->treeView->currentIndex().data(ItemDataUserRoleProtocol::ProtocolId).toString();
    pStructEdit->sendData(ql);
    if(pStructEdit->exec()==QDialog::Accepted)
    {
        init_structDetailList(ui->listView->currentIndex().data(ItemDataUserRoleStruct::StructId).toString());
    }
}

//修改结构体明细
void ProjectBuild::on_btn_EditDataType_2_clicked()
{
    QModelIndex curIndex=ui->tableView_struct->currentIndex();
    if(curIndex.row()==-1){
        QMessageBox::warning(this,tr("警告"),tr("请选择要修改的结构体！"),tr("确定"));
        return;
    }
    StructEdit *pStructEdit = new StructEdit(this);
    pStructEdit->setAttribute(Qt::WA_DeleteOnClose, true);//窗口接受了关闭事件后，Qt会释放这个窗口所占用的资源。
    pStructEdit->setModal(true);

    QString strId= curIndex.siblingAtColumn(0).data(ItemDataUserRoleStructDetail::StructDetailId).toString();
    QString strProtoclId=curIndex.siblingAtColumn(0).data(ItemDataUserRoleStructDetail::StructDetailProtocolId).toString();
    QString strStructId=curIndex.siblingAtColumn(0).data(ItemDataUserRoleStructDetail::StructDetailStructId).toString();
    QString strDataTypeId=curIndex.siblingAtColumn(0).data(ItemDataUserRoleStructDetail::StructDetailDataTypeId).toString();

    QString strDataType = curIndex.siblingAtColumn(1).data().toString();
    QString strBit= curIndex.siblingAtColumn(2).data().toString();
    QString strName = curIndex.siblingAtColumn(3).data().toString();
    QString strDescription = curIndex.siblingAtColumn(4).data().toString();
    QString strRange = curIndex.siblingAtColumn(5).data().toString();
    QString strDefaultValue = curIndex.siblingAtColumn(6).data().toString();
    QString strQuantization = curIndex.siblingAtColumn(7).data().toString();

    QStringList ql;
    ql<<strId<<strDataType<<strBit<<strName<<strDescription<<strRange<<strDefaultValue<<strQuantization<<strStructId<<strDataTypeId<<strProtoclId;
    pStructEdit->sendData(ql);
    if(pStructEdit->exec()==QDialog::Accepted)
    {
        init_structDetailList(ui->listView->currentIndex().data(ItemDataUserRoleStruct::StructId).toString());
    }
}

//删除结构体明细
void ProjectBuild::on_btn_DeleteDataType_2_clicked()
{
    QModelIndex curIndex=ui->tableView_struct->currentIndex();
    if(curIndex.row()==-1){
        QMessageBox::warning(this,tr("警告"),tr("请选择要删除的数据！"),tr("确定"));
        return;
    }

    QSqlDatabase databaseSQLite;
    databaseSQLite = QSqlDatabase::addDatabase("QSQLITE");
    databaseSQLite.setDatabaseName("sysdata.db");
    if (!databaseSQLite.open())
    {
        qDebug() << "Error: Failed to connect database." << databaseSQLite.lastError();
        return;
    }
    else
    {
        QSqlQuery sql_querySQLite;
        QString strSQLite=QString("DELETE FROM struct_data_entity WHERE id = '%1'").arg(curIndex.siblingAtColumn(0).data(ItemDataUserRoleStructDetail::StructDetailId).toString());

        if(sql_querySQLite.exec(strSQLite)){
            init_structDetailList(ui->listView->currentIndex().data(ItemDataUserRoleStruct::StructId).toString());
            QMessageBox::information(this,tr("提示"),tr("删除成功!"),tr("确定"));
            return;
        }else{
            QMessageBox::warning(this,tr("警告"),tr("删除失败！"),tr("确定"));
        }
    }
    databaseSQLite.close();
}

//导出协议
void ProjectBuild::on_btn_Import_clicked()
{
    emit on_treeView_showExportProtocolContextMenu();
}




