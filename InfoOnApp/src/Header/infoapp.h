#ifndef __TRAINIMAGE_H
#define __TRAINIMAGE_H

#include "../../../precompHeader/preH.h"

namespace Ui { class InfoOnApp; }

class InfoOnApp : public QMainWindow
{
    Q_OBJECT

    public:
        explicit InfoOnApp(QWidget *parent = nullptr);
        ~InfoOnApp();

    private slots :
        void on_openCam_clicked();
        void on_actionVersion_triggered();
        void on_actionAbout_us_triggered();

    private:
        Ui::InfoOnApp *ui;
        QString aboutUs = tr("This program was made by NAQI Amine, it's a demo of a face detection program <br>"
                             "that uses HAARXML file, and OpenCV library to achieve the goal of this application.<br>"
                             "Enjoy !!");

        QString version = tr("App: FaceDet <br>version: 1.2.2");
};

#endif // __TRAINIMAGE_H
