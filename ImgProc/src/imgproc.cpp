#include "./Header/imgproc.h"
#include "ui_imgproc.h"

ImgProc::ImgProc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ImgProc)
{
    ui->setupUi(this);
}

ImgProc::~ImgProc() { delete ui; }