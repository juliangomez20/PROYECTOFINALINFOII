#ifndef FINDELJUEGO_H
#define FINDELJUEGO_H

#include <QWidget>

namespace Ui {
class Findeljuego;
}

class Findeljuego : public QWidget
{
    Q_OBJECT

public:
    explicit Findeljuego(QWidget *parent = nullptr);
    ~Findeljuego();

private:
    Ui::Findeljuego *ui;
};

#endif // FINDELJUEGO_H
