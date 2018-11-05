#ifndef DIALOGLOCKSS_H
#define DIALOGLOCKSS_H

#include <QDialog>

namespace Ui {
class Dialoglockss;
}

class Dialoglockss : public QDialog
{
    Q_OBJECT

public:
    explicit Dialoglockss(QWidget *parent = nullptr);
    ~Dialoglockss();

private:
    Ui::Dialoglockss *ui;
};

#endif // DIALOGLOCKSS_H
