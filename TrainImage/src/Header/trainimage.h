#ifndef TRAINIMAGE_H
#define TRAINIMAGE_H

#include "../../../Precompiled_H/precom_Header.h"
#include "../../../ImgProc/src/Header/imgproc.h"
#include "../../../Detect//src/Header/detect.h"

namespace Ui { class TrainImage; }

class ImgProc;

class detect;

class TrainImage : public QMainWindow
{
    Q_OBJECT

    public:
        explicit TrainImage(QWidget *parent = nullptr);
        ~TrainImage();

    private slots :
        void on_openCam_clicked();
        void on_detBtn_clicked();

private:
        Ui::TrainImage *ui;
        ImgProc *img;
        detect *det;
};

#endif // TRAINIMAGE_H
