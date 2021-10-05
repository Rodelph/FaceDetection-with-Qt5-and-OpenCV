#ifndef IMGPROC_H
#define IMGPROC_H

#include "../../../Precompiled_H/precom_Header.h"
#include "../../../TrainImage/src/Header/trainimage.h"

namespace Ui { class ImgProc; }

class TrainImage;

class ImgProc : public QMainWindow
{
        Q_OBJECT

    public:
    
        explicit ImgProc(QWidget *parent = nullptr);
        ~ImgProc();

    private slots:

        void on_actionCheck_stored_images_triggered();
        void on_startBtn_clicked();
        void on_retBtn_clicked();
        void on_actionHow_it_works_triggered();
        
    private:

        void setUpCam();
        cv::Mat deployCam(cv::Mat& _frame);
        cv::Mat detectFace(cv::Mat& _frameDet, std::string& _namePerson);

        Ui::ImgProc *ui;
        TrainImage *train;

        cv::Mat frame;
        cv::CascadeClassifier face_cascade;
        cv::VideoCapture cap;

        uint8_t deviceID, apiID, count;
        
        std::vector<cv::Rect> faces;
        const cv::String backToOrigin = "../../";
        std::string name;
        
        const QString pathToFiles = QDir::currentPath() + "/res/";
        QString path;
        QString _howItWorks = tr(
            "This part will give you the ability to store you images, <br>"
            "in a folder. Please stay close to your camera when taking <br>"
            "images of the desired person."
        );

        QErrorMessage *error;
};

#endif // IMGPROC_H