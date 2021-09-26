#ifndef IMGPROC_H
#define IMGPROC_H

#include "../../../Precompiled_H/precom_Header.h"

namespace Ui {
class ImgProc;
}

class ImgProc : public QMainWindow
{
    Q_OBJECT

public:
    explicit ImgProc(QWidget *parent = nullptr);
    ~ImgProc();

private:
    Ui::ImgProc *ui;
};

#endif // IMGPROC_H
