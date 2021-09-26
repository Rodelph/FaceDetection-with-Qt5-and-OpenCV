#ifndef TRAINIMAGE_H
#define TRAINIMAGE_H

#include "../../../Precompiled_H/precom_Header.h"

namespace Ui {
class TrainImage;
}

class MyVideoCapture;

class TrainImage : public QMainWindow
{
    Q_OBJECT

    public:
        explicit TrainImage(QWidget *parent = nullptr);
        ~TrainImage();

    private slots :
        void on_openCam_clicked();

    private:
        std::string setUpCam();
        cv::Mat deployCam(cv::Mat& _frame);
        void captureImage(cv::Mat& _frameCapt, std::string _namePerson);
        cv::Mat detectFace(cv::Mat& _frameDet);

        cv::Mat frame;
        cv::CascadeClassifier face_cascade;
        cv::VideoCapture cap;

        uint8_t deviceID, apiID;
        uint8_t x, y;
        uint8_t width, height;
        uint8_t count;
        
        std::vector<cv::Rect> faces;
        const cv::String backToOrigin = "../../";
        std::string name;

        Ui::TrainImage *ui;
};

#endif // TRAINIMAGE_H
