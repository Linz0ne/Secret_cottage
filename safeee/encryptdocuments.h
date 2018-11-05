#ifndef ENCRYPTDOCUMENTS_H
#define ENCRYPTDOCUMENTS_H
#include <QDialog>
namespace Ui {
class encryptdocuments;
}

class encryptdocuments : public QDialog
{
    Q_OBJECT

public:
    explicit encryptdocuments(QWidget *parent = nullptr);
    ~encryptdocuments();
    void EncryptionStr(QByteArray &data);
private slots:


    void on_pushButton_clicked();

    void on_pushButtondec_clicked();


    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::encryptdocuments *ui;
};

#endif // ENCRYPTDOCUMENTS_H
