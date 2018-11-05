#ifndef PASSWORDBACKUP_H
#define PASSWORDBACKUP_H

#include <QDialog>

namespace Ui {
class Passwordbackup;
}

class Passwordbackup : public QDialog
{
    Q_OBJECT

public:
    explicit Passwordbackup(QWidget *parent = nullptr);
    ~Passwordbackup();

private slots:
    void on_pushButton_saves_clicked();

    void on_pushButton_cancerss_clicked();

    void on_pushButtonhash_clicked();

private:
    Ui::Passwordbackup *ui;
};

#endif // PASSWORDBACKUP_H
