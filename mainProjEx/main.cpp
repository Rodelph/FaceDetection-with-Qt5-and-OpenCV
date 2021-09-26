#include "../TrainImage/src/Header/trainimage.h"
#include <QApplication>

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    TrainImage img;
    img.show();
    return a.exec();
}