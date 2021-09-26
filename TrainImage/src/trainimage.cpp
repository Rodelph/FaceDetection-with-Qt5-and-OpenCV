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

    img = new ImgProc();
    img->show();
}