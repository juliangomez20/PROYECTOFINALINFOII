#ifndef WINER_H
#define WINER_H

#include <QWidget>

namespace Ui {
class Winer;
}

class Winer : public QWidget
{
    Q_OBJECT

public:
    explicit Winer(QWidget *parent = nullptr);
    ~Winer();

private:
    Ui::Winer *ui;
};

#endif // WINER_H
