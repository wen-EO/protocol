#include "datatypeedit.h"
#include "ui_datatypeedit.h"
#include "projectbuild.h"

#include <QMessageBox>
#include <QtDebug>

//添加头文件
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QUuid>
#include <QDateTime>

DataTypeEdit::DataTypeEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DataTypeEdit)
{
    ui->setupUi(this);
    //去掉帮助按钮
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
    
    ui->buttonGroup->setId(ui->rbtn_Signed,0);
    ui->buttonGroup->setId(ui->rbtn_Unsigned,1);
    
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
        //查询数据
        QSqlQuery sql_querySQLite;
        QString strSQLite=QString("select id,name from systemDataType_entity");
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
                
                ui->cbx_SystemDataType->addItem(strName);                
            }
        }
    }
    databaseSQLite.close();
}

DataTypeEdit::~DataTypeEdit()
{
    delete ui;
}

void DataTypeEdit::sendData(QStringList  s)
{
    m_dataType_id=s.at(0);
    ui->edt_Name->setText(s.at(1));
    if(s.at(2)=="signed")
    {
        ui->rbtn_Signed->setChecked(true);
    }
    else
    {
        ui->rbtn_Unsigned->setChecked(true);
    }
    ui->cbx_SystemDataType->setCurrentText(s.at(3));
    m_protocol_id=s.at(4);
    if(m_dataType_id=="")
    {
        this->setWindowTitle(tr("新建数据类型"));
    }
    else
    {
        this->setWindowTitle(tr("修改数据类型"));
    }
}

void DataTypeEdit::on_btn_OK_clicked()
{
    QString strName=ui->edt_Name->text();
    int checkedId = ui->buttonGroup->checkedId();
    QString strSigned=checkedId==0?"signed":"unsigned";
    QString strSystemDataType=ui->cbx_SystemDataType->currentText();

    //检查必填项
    if (strName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请输入数据类型名称！");
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
    QSqlQuery sql_querySQLite;

    if(m_dataType_id.isEmpty()){
        QUuid id = QUuid::createUuid();
        QString strId = id.toString().replace("{","").replace("}","");
        QString strSQL=QString("INSERT INTO protocol_dataType_entity(id,protocol_entity_id, name, signed, system_dataType) VALUES ('%1', '%2', '%3', '%4', '%5')")
                .arg(strId).arg(m_protocol_id).arg(strName).arg(strSigned).arg(strSystemDataType);
        if(!sql_querySQLite.exec(strSQL)){
            QMessageBox::warning(this,tr("警告"),tr("添加失败！"),tr("确定"));
            return;
        }
        DataTypeEdit::accept();
        QMessageBox::information(this,tr("提示"),tr("添加成功！"),tr("确定"));
    }
    else
    {
        //修改
        QString strSQL=QString("UPDATE protocol_dataType_entity SET name = '%1', signed = '%2', system_dataType = '%3'  WHERE id = '%4'")
                .arg(strName).arg(strSigned).arg(strSystemDataType).arg(m_dataType_id);
        if(!sql_querySQLite.exec(strSQL)){
            QMessageBox::warning(this,tr("警告"),tr("修改失败！"),tr("确定"));
            return;
        }
        DataTypeEdit::accept();
        QMessageBox::information(this,tr("提示"),tr("修改成功！"),tr("确定"));
    }
    databaseSQLite.close();
    this->close();
}

void DataTypeEdit::on_btn_Cancel_clicked()
{
    DataTypeEdit::reject();
    this->close();
}
