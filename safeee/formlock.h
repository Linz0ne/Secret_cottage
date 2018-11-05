#ifndef FORMLOCK_H
#define FORMLOCK_H
#include <QWidget>
namespace Ui {
class Formlock;
}

class Formlock : public QWidget
{
    Q_OBJECT

public:
    explicit Formlock(QWidget *parent = nullptr);
    ~Formlock();

private:
    Ui::Formlock *ui;
};

#endif // FORMLOCK_H
