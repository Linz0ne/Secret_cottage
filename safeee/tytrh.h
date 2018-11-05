#ifndef TYTRH_H
#define TYTRH_H
#include <QDialog>
#include <QSqlTableModel>
#include <QStandardItemModel>
namespace Ui {
class tytrh;
}

class tytrh : public QDialog
{
    Q_OBJECT

public:
    explicit tytrh(QWidget *parent = nullptr);
    ~tytrh();

private slots:
    void on_pushButtonsave_clicked();

    void on_pushButtonlockkk_clicked();

    void on_pushButtoncancer_clicked();

    void on_pushButton_clicked();

private:
    Ui::tytrh *ui;
    QSqlTableModel *model;
    QStandardItemModel *ss;
};

#endif // TYTRH_H
