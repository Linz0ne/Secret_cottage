#ifndef FORMMEMERY_H
#define FORMMEMERY_H
#include <QWidget>
namespace Ui {
class Formmemery;
}

class Formmemery : public QWidget
{
    Q_OBJECT

public:
    explicit Formmemery(QWidget *parent = nullptr);
    ~Formmemery();

private:
    Ui::Formmemery *ui;
};

#endif // FORMMEMERY_H
