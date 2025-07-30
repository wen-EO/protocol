#include "categoryedit.h"
#include "ui_categoryedit.h"

#include <QtDebug>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QUuid>
#include <QStandardItem>

CategoryEdit::CategoryEdit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CategoryEdit)
{
    ui->setupUi(this);

    //去掉帮助按钮
    this->setWindowFlags(windowFlags()&~Qt::WindowContextHelpButtonHint);
}

CategoryEdit::~CategoryEdit()
{
    delete ui;
}

void CategoryEdit::sendData(QStringList  s)
{
    ui->edt_name->setText(s.at(0));
    ui->edt_description->setText(s.at(1));
    m_category_id = s.at(2);
    this->setWindowTitle(tr("修改协议类型"));
}

void CategoryEdit::on_btn_OK_clicked()
{
    QString strDescription=ui->edt_description->toPlainText();
    QString strName=ui->edt_name->text();

    //检查必填项
    if (strName.isEmpty())
    {
        QMessageBox::warning(this,"警告","请输入协议类型名称！");
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

    if(m_category_id.isEmpty()){
        QUuid id = QUuid::createUuid();
        QString strId = id.toString().replace("{","").replace("}","");
        QString strSQL=QString("INSERT INTO category_entity(id,name, description) VALUES ('%1', '%2', '%3')")
                .arg(strId).arg(strName).arg(strDescription);
        if(!sql_querySQLite.exec(strSQL)){
            QMessageBox::warning(this,tr("警告"),tr("添加失败！"),tr("确定"));
            return;
        }
        emit setCategoryInfo(strId,strName,strDescription);
        CategoryEdit::accept();
        QMessageBox::information(this,tr("提示"),tr("添加成功！"),tr("确定"));
    }
    else
    {
        //修改
        QString strSQL=QString("UPDATE category_entity SET name = '%1', description = '%2' WHERE id = '%3'")
                .arg(strName).arg(strDescription).arg(m_category_id);
        if(!sql_querySQLite.exec(strSQL)){
            QMessageBox::warning(this,tr("警告"),tr("修改失败！"),tr("确定"));
            return;
        }
        emit setCategoryInfo(m_category_id,strName,strDescription);
        CategoryEdit::accept();
        QMessageBox::information(this,tr("提示"),tr("修改成功！"),tr("确定"));
    }

    databaseSQLite.close();
    this->close();
}

void CategoryEdit::on_btn_Cancel_clicked()
{
    CategoryEdit::reject();
    this->close();
}
