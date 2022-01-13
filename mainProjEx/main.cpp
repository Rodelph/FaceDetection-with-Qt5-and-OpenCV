#include "../InfoOnApp/src/Header/infoapp.h"

int main(int argc, char** argv)
{
    QApplication a(argc, argv);
    InfoOnApp info;
    info.show();
    return a.exec();
}
