#include "../../ImgProc/src/Header/imgproc.h"
#include "../../Detect/src/Header/detect.h"
#include "./Header/trainimage.h"
#include "ui_trainimage.h"

TrainImage::TrainImage(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::TrainImage)
{
    ui->setupUi(this);
}

TrainImage::~TrainImage() { delete ui; }

void TrainImage::on_openCam_clicked()
{
    this->hide();

    ImgProc *img = new ImgProc();
    img->show();
}

void TrainImage::on_detBtn_clicked()
{
    this->hide();

    detect *det = new detect();
    det->show();
}
