#ifndef __TRAINIMAGE_H
#define __TRAINIMAGE_H

#include "../../../precompHeader/preH.h"

namespace Ui { class TrainImage; }

class TrainImage : public QMainWindow
{
    Q_OBJECT

    public:
        explicit TrainImage(QWidget *parent = nullptr);
        ~TrainImage();

    private slots :
        void on_openCam_clicked();
        void on_actionVersion_triggered();
        void on_actionAbout_us_triggered();

    private:
        Ui::TrainImage *ui;
        QString aboutUs = tr("This program was made by NAQI Amine, it's a demo of a face detection program <br>"
                             "that uses HAARXML file, and OpenCV library to achieve the goal of this application.<br>"
                             "Enjoy !!");

        QString version = tr("App: FaceDet <br>version: 1.2.2");
};

#endif // __TRAINIMAGE_H
