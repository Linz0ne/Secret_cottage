#ifndef SDQWDW_H
#define SDQWDW_H
#include "tytrh.h"
#include <QDialog>
namespace Ui {
class sdqwdw;
}

class sdqwdw : public QDialog
{
    Q_OBJECT

public:
    explicit sdqwdw(QWidget *parent = nullptr);
    ~sdqwdw();

private slots:
    void on_pushButtonlocksss_clicked();

private:
    Ui::sdqwdw *ui;
    tytrh sdw;
};

#endif // SDQWDW_H
