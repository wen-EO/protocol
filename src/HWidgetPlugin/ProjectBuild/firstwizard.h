#ifndef FIRSTWIZARD_H
#define FIRSTWIZARD_H

#include <QWizardPage>

namespace Ui {
class FirstWizard;
}

class FirstWizard : public QWizardPage
{
    Q_OBJECT

public:
    explicit FirstWizard(QWizardPage *parent = 0);
    ~FirstWizard();

private:
    Ui::FirstWizard *ui;
};

QString titleTemplate();
QString subTitleTemplate();

#endif // FIRSTWIZARD_H
