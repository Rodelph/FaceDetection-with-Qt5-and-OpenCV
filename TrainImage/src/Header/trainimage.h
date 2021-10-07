#ifndef __TRAINIMAGE_H
#define __TRAINIMAGE_H

#include "../../../Precompiled_H/precom_Header.h"

namespace Ui { class TrainImage; }

class TrainImage : public QMainWindow
{
    Q_OBJECT

    public:
        explicit TrainImage(QWidget *parent = nullptr);
        ~TrainImage();

    private slots :
        void on_openCam_clicked();
        void on_detBtn_clicked();

    private:
        Ui::TrainImage *ui;
};

#endif // __TRAINIMAGE_H
