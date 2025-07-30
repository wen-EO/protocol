#ifndef COMPONENTEDIT_H
#define COMPONENTEDIT_H

#include <QDialog>

namespace Ui {
class ComponentEdit;
}

class ComponentEdit : public QDialog
{
    Q_OBJECT
    
public:
    explicit ComponentEdit(QWidget *parent = nullptr);
    ~ComponentEdit();
    
        void sendData(QStringList);
        
signals:
    void addComponentToPage(QStringList);
    
private slots:
    
    void on_btn_OK_clicked();
    
    void on_btn_Cancel_clicked();
    
private:
    Ui::ComponentEdit *ui;
    
    QString m_protocol_id;
};

#endif // COMPONENTEDIT_H
