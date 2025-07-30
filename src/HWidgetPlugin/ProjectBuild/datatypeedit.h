#ifndef DATATYPEEDIT_H
#define DATATYPEEDIT_H

#include <QDialog>

namespace Ui {
class DataTypeEdit;
}

class DataTypeEdit : public QDialog
{
    Q_OBJECT

public:
    explicit DataTypeEdit(QWidget *parent = nullptr);
    ~DataTypeEdit();

private slots:
    void on_btn_OK_clicked();

    void on_btn_Cancel_clicked();

public:
    void sendData(QStringList  s);
    
signals:
    void addDataToPage(QStringList);

private:
    Ui::DataTypeEdit *ui;

    QString m_dataType_id;
    QString m_protocol_id;
    
};

#endif // DATATYPEEDIT_H
