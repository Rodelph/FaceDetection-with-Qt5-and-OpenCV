#ifndef DETECT_H
#define DETECT_H

#include <QMainWindow>

namespace Ui {
class detect;
}

class detect : public QMainWindow
{
    Q_OBJECT

public:
    explicit detect(QWidget *parent = nullptr);
    ~detect();

private:
    Ui::detect *ui;
};

#endif // DETECT_H
