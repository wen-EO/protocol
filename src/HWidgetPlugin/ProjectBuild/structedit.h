#ifndef STRUCTEDIT_H
#define STRUCTEDIT_H

#include <QDialog>

namespace Ui {
class StructEdit;
}

class StructEdit : public QDialog
{
    Q_OBJECT
    
public:
    explicit StructEdit(QWidget *parent = nullptr);
    ~StructEdit();
    
    void sendData(QStringList);
    
signals:
    void addStructToPage(QStringList);
    
private slots:
    void on_btn_OK_clicked();
    
    void on_btn_Cancel_clicked();
    
private:
    Ui::StructEdit *ui;
    QString m_structId;
    QString m_dataTypeId;
    QString m_prototclId;
    QString m_structDetailId;
};

#endif // STRUCTEDIT_H
