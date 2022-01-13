#include "../../ImgProc/src/Header/imgproc.h"
#include "./Header/infoapp.h"
#include "ui_infoapp.h"

InfoOnApp::InfoOnApp(QWidget *parent) : QMainWindow(parent), 
                                          ui(new Ui::InfoOnApp)
{
    ui->setupUi(this);
}

InfoOnApp::~InfoOnApp() { delete ui; }

void InfoOnApp::on_openCam_clicked()
{
    this->hide();

    ImgProc *img = new ImgProc();
    img->show();
}

void InfoOnApp::on_actionAbout_us_triggered()
{
    QMessageBox::information(this, 
                             "About us",
                             aboutUs);
}

void InfoOnApp::on_actionVersion_triggered()
{
    QMessageBox::information(this, 
                             "Version",
                             version);
}
