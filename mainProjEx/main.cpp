#include "../TrainImage/src/Header/trainimage.h"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    TrainImage imgT;
    imgT.show();
    return a.exec();
}
