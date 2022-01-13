#ifndef __IMGPROC_H
#define __IMGPROC_H

#include "../../../precompHeader/preH.h"

namespace Ui { class ImgProc; }

class ImgProc : public QMainWindow
{
    Q_OBJECT

    public:
        
        explicit ImgProc(QWidget *parent = nullptr);
        ~ImgProc();

    private slots:

        void on_startBtn_clicked();
        void on_retBtn_clicked();
        void on_actionMore_info_triggered();
        
    private:

        void setUpCam();
        cv::Mat deployCam(cv::Mat& _frame);
        cv::Mat detectFace(cv::Mat& _frameDet, std::string& _namePerson);
        cv::Mat filterGpu(std::string& _namePerson, cv::Mat& _frameUp, cv::Mat& _frameDown);
        
        Ui::ImgProc *ui;      
        
        cv::Mat frame, frameGpu;
        cv::CascadeClassifier face_cascade;
        cv::VideoCapture cap;
        cv::cuda::GpuMat dstGpu, srcGpu;

        uint8_t deviceID;
        uint32_t count;
        uint16_t apiID; 
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

    public :
        uint32_t getCount();
        uint16_t getapiID();
};

#endif //__IMGPROC_H
