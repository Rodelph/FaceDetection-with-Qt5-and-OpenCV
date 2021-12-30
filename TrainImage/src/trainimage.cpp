#include "../../ImgProc/src/Header/imgproc.h"
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

void TrainImage::on_actionAbout_us_triggered()
{
    QMessageBox::information(this, 
                             "About us",
                             aboutUs);
}

void TrainImage::on_actionVersion_triggered()
{
    QMessageBox::information(this, 
                             "Version",
                             version);
}
