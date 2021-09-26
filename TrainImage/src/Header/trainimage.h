#ifndef TRAINIMAGE_H
#define TRAINIMAGE_H

#include "../../../Precompiled_H/precom_Header.h"
#include "../../../ImgProc/src/Header/imgproc.h"

namespace Ui { class TrainImage; }

class ImgProc;

class TrainImage : public QMainWindow
{
    Q_OBJECT

    public:
        explicit TrainImage(QWidget *parent = nullptr);
        ~TrainImage();

    private slots :
        void on_openCam_clicked();

    private:
        Ui::TrainImage *ui;
        ImgProc *img;
};

#endif // TRAINIMAGE_H