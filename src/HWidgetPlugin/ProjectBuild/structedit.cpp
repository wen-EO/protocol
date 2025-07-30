#include "structedit.h"
#include "ui_structedit.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlError>
#include <QMessageBox>
#include <QUuid>
StructEdit::StructEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StructEdit)
{
    ui->setupUi(this);
    //去掉帮助按钮
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
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
        QString strSQLite=QString("select id,name from protocol_dataType_entity");
        if(!sql_querySQLite.exec(strSQLite))
        {
            qDebug() << sql_querySQLite.lastError();
            return;
        }
        else
        {
            int i = 0;
            while(sql_querySQLite.next())
            {
                QString strId= sql_querySQLite.value(0).toString();
                QString strName = sql_querySQLite.value(1).toString();
                //add filter zhaoz
                bool bTmpFind=false;
                for(int index=0;index<ui->cbx_systemDataType->count();++index){
                    if(strName==ui->cbx_systemDataType->itemText(index)){
                        bTmpFind=true;
                        break;
                    }
                }
                if(false==bTmpFind){
                    ui->cbx_systemDataType->addItem(strName);
                    ui->cbx_systemDataType->setItemData(i,strId,Qt::UserRole);
                    i++;
                }
            }
        }
    }
    databaseSQLite.close();
}

StructEdit::~StructEdit()
{
    delete ui;
}

void StructEdit::sendData(QStringList s)
{
    m_structDetailId = s.at(0);
    ui->cbx_systemDataType->setCurrentText(s.at(1));
    ui->edt_bit->setText(s.at(2));
    ui->edt_name->setText(s.at(3));
    ui->edt_description->setText(s.at(4));
    ui->edt_range->setText(s.at(5));
    ui->edt_defaultValue->setText(s.at(6));
    ui->edt_quantization->setText(s.at(7));

    m_structId = s.at(8);
    m_dataTypeId = s.at(9);
    m_prototclId = s.at(10);

    if(m_structDetailId=="")
    {
        this->setWindowTitle(tr("新建结构体详情"));
    }
    else
    {
        this->setWindowTitle(tr("修改结构体详情"));
    }
}

void StructEdit::on_btn_OK_clicked()
{
    QString strDataTypeId=ui->cbx_systemDataType->itemData(ui->cbx_systemDataType->currentIndex(),Qt::UserRole).toString();
    QString strBit=ui->edt_bit->text();
    QString strName=ui->edt_name->text();
    QString strDescription=ui->edt_description->text();
    QString strRange=ui->edt_range->text();
    QString strDefaultValue=ui->edt_defaultValue->text();
    QString strQuantization=ui->edt_quantization->text();

    //检查必填项
    if (strName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请输入结构体字段定义！");
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

    if(m_structDetailId.isEmpty()){
        QUuid id = QUuid::createUuid();
        QString strId = id.toString().replace("{","").replace("}","");
        QString strSQL=QString("INSERT INTO struct_data_entity(id,protocol_entity_id,struct_entity_id,dataType_entity_id,bit,name,description,range,defaultvalue,quantization) VALUES ('%1', '%2', '%3', '%4', '%5', '%6', '%7', '%8', '%9', '%10')")
                .arg(strId).arg(m_prototclId).arg(m_structId).arg(strDataTypeId).arg(strBit).arg(strName).arg(strDescription).arg(strRange).arg(strDefaultValue).arg(strQuantization);
        if(!sql_querySQLite.exec(strSQL)){
            QMessageBox::warning(this,tr("警告"),tr("添加失败！"),tr("确定"));
            return;
        }
        StructEdit::accept();
        QMessageBox::information(this,tr("提示"),tr("添加成功！"),tr("确定"));
    }
    else
    {
        //修改
        QString strSQL=QString("UPDATE struct_data_entity SET dataType_entity_id = '%1', bit = '%2',  name = '%3', description = '%4', range = '%5', defaultvalue = '%6', quantization = '%7'  WHERE id = '%8'")
                .arg(strDataTypeId).arg(strBit).arg(strName).arg(strDescription).arg(strRange).arg(strDefaultValue).arg(strQuantization).arg(m_structDetailId);
        if(!sql_querySQLite.exec(strSQL)){
            QMessageBox::warning(this,tr("警告"),tr("修改失败！"),tr("确定"));
            return;
        }
        StructEdit::accept();
        QMessageBox::information(this,tr("提示"),tr("修改成功！"),tr("确定"));
    }
    databaseSQLite.close();
    this->close();
}

void StructEdit::on_btn_Cancel_clicked()
{
    StructEdit::reject();
    this->close();
}
