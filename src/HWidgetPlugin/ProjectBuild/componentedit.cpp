#include "componentedit.h"
#include "ui_componentedit.h"
#include "hwidgetlibrary.h"
#include "hconfigmanage.h"
#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QUuid>
#include <QStandardItem>
//#include <QDateTime>

ComponentEdit::ComponentEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComponentEdit)
{
    ui->setupUi(this);
    //去掉帮助按钮
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    //设置默认日期
    ui->date_createTime->setDate(QDate::currentDate());
    //加载协议类型
    foreach(CATEGORY_INFO *categoryItem,HConfigManage::getInstance()->m_categoryList)
    {
        ui->cbx_category->addItem(categoryItem->categoryName);
    }
}

ComponentEdit::~ComponentEdit()
{
    delete ui;
}

void ComponentEdit::sendData(QStringList  s)
{
    ui->edt_name->setText(s.at(0));
    ui->edt_description->setText(s.at(1));
    ui->cbx_category->setCurrentText(s.at(2));
    ui->edt_createUser->setText(s.at(3));
    ui->date_createTime->setDate(QDate::fromString(s.at(4),"yyyy-MM-dd"));
    m_protocol_id = s.at(5);
    this->setWindowTitle(tr("修改协议"));
}

void ComponentEdit::on_btn_OK_clicked()
{    
    QString strCategoryId="";
    foreach(CATEGORY_INFO *categoryItem,HConfigManage::getInstance()->m_categoryList)
    {
        if(categoryItem->categoryName==ui->cbx_category->currentText())
        {
            strCategoryId=categoryItem->categoryId;
        }
    }

    QString strCreateUser=ui->edt_createUser->text();
    QString strCreateDateTime=ui->date_createTime->text();
    QString strDescription=ui->edt_description->toPlainText();
    QString strName=ui->edt_name->text();

    //检查必填项
    if (strName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请输入协议名称！");
        return;
    }

    //添加
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

    if(m_protocol_id.isEmpty()){
        QUuid id = QUuid::createUuid();
        QString strId = id.toString().replace("{","").replace("}","");
        QString strSQL=QString("INSERT INTO protocol_entity(id,category_entity_id, create_user, create_time, description, name) VALUES ('%1', '%2', '%3', '%4', '%5', '%6')")
                .arg(strId).arg(strCategoryId).arg(strCreateUser).arg(strCreateDateTime).arg(strDescription).arg(strName);
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);

        //----------------------添加默认自定义类型---------------------------
        QUuid dataId = QUuid::createUuid();
        QString strDataId = dataId.toString().replace("{","").replace("}","");
        strSQL=QString("INSERT INTO protocol_dataType_entity(id,protocol_entity_id, name, signed, system_dataType) VALUES ('%1', '%2', '%3', '%4', '%5')")
                .arg(strDataId).arg(strId).arg("INT8").arg("signed").arg("char");
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);

        dataId = QUuid::createUuid();
        strDataId = dataId.toString().replace("{","").replace("}","");
        strSQL=QString("INSERT INTO protocol_dataType_entity(id,protocol_entity_id, name, signed, system_dataType) VALUES ('%1', '%2', '%3', '%4', '%5')")
                .arg(strDataId).arg(strId).arg("INT16").arg("signed").arg("short");
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);

        dataId = QUuid::createUuid();
        strDataId = dataId.toString().replace("{","").replace("}","");
        strSQL=QString("INSERT INTO protocol_dataType_entity(id,protocol_entity_id, name, signed, system_dataType) VALUES ('%1', '%2', '%3', '%4', '%5')")
                .arg(strDataId).arg(strId).arg("INT32").arg("signed").arg("long");
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);

        dataId = QUuid::createUuid();
        strDataId = dataId.toString().replace("{","").replace("}","");
        strSQL=QString("INSERT INTO protocol_dataType_entity(id,protocol_entity_id, name, signed, system_dataType) VALUES ('%1', '%2', '%3', '%4', '%5')")
                .arg(strDataId).arg(strId).arg("UINT8").arg("unsigned").arg("char");
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);

        dataId = QUuid::createUuid();
        strDataId = dataId.toString().replace("{","").replace("}","");
        strSQL=QString("INSERT INTO protocol_dataType_entity(id,protocol_entity_id, name, signed, system_dataType) VALUES ('%1', '%2', '%3', '%4', '%5')")
                .arg(strDataId).arg(strId).arg("UINT16").arg("unsigned").arg("short");
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);

        dataId = QUuid::createUuid();
        strDataId = dataId.toString().replace("{","").replace("}","");
        strSQL=QString("INSERT INTO protocol_dataType_entity(id,protocol_entity_id, name, signed, system_dataType) VALUES ('%1', '%2', '%3', '%4', '%5')")
                .arg(strDataId).arg(strId).arg("UINT32").arg("unsigned").arg("long");
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);
        //----------------------添加默认自定义类型---------------------------
        //判断是否提交事务
        if(!sqlOK)
        {
            //事务回滚
            databaseSQLite.rollback();
            QMessageBox::warning(this,tr("警告"),tr("添加失败！"),tr("确定"));
            return;
        }
        //事务提交
        databaseSQLite.commit();
        ComponentEdit::accept();
        QMessageBox::information(this,tr("提示"),tr("添加成功！"),tr("确定"));
    }
    else
    {
        //修改
        QString strSQL=QString("UPDATE protocol_entity SET category_entity_id = '%1', create_user = '%2', create_time = '%3', description = '%4', name = '%5' WHERE id = '%6'")
                .arg(strCategoryId).arg(strCreateUser).arg(strCreateDateTime).arg(strDescription).arg(strName).arg(m_protocol_id);
        //执行SQL
        sqlOK=sql_querySQLite.exec(strSQL);
        //判断是否提交事务
        if(!sqlOK)
        {
            qDebug()<<strSQL;
            qDebug()<<sql_querySQLite.lastError();
            //事务回滚
            databaseSQLite.rollback();
            QMessageBox::warning(this,tr("警告"),tr("修改失败！"),tr("确定"));
            return;
        }
        //事务提交
        databaseSQLite.commit();
        ComponentEdit::accept();
        QMessageBox::information(this,tr("提示"),tr("修改成功！"),tr("确定"));
    }
    databaseSQLite.close();
    this->close();
}

void ComponentEdit::on_btn_Cancel_clicked()
{
    ComponentEdit::reject();
    this->close();
}
