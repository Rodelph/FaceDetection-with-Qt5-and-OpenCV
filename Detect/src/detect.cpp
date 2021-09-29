#include "./Header/detect.h"
#include "ui_detect.h"

detect::detect(QWidget *parent) : QMainWindow(parent),
                                  ui(new Ui::detect)
{
    ui->setupUi(this);
}

detect::~detect() { delete ui; }