#include "../../TrainImage/src/Header/trainimage.h"
#include "./Header/detect.h"
#include "ui_detect.h"

detect::detect(QWidget *parent) : QMainWindow(parent),
                                  ui(new Ui::detect)
{
    ui->setupUi(this);

    deviceID = 0;
    apiID = cv::CAP_ANY;
    count = 0;
}

detect::~detect() 
{ 
    delete ui; 
    capt.release();
    cv::destroyAllWindows();
}

void detect::setupCam()
{
    capt.open(deviceID, apiID);

    if (!capt.isOpened()) std::cerr << "Error:: Unable to activate the camera !\n";

    std::cout << "/******************************************************* INFO *******************************************************\\";
    std::cout << "                                                    Start grabbing" << "\n";
}

cv::Mat detect::deployCam(cv::Mat& _frame)
{
    capt.read(_frame);

    return _frame;
}

cv::Mat detect::lbpFace(cv::Mat &_frame)
{
    //std::vector<int> labels(_frame.size());

    //cv::face::LBPHFaceRecognizer::create(1, 8, 8, DBL_MAX);
    return _frame;   
}

void detect::on_pushButton_clicked()
{
    setupCam();
    capt.set(cv::CAP_PROP_FRAME_WIDTH , 1280);
    capt.set(cv::CAP_PROP_FRAME_HEIGHT,  720);

    for (;;)
    {
        deployCam(frame);

        if (frame.empty())
        {
            std::cerr << "Error:: Blank frame grabbed \n";
            break;
        }

        cv::imshow("Detecting faces", frame);

        if (cv::waitKey(5) >= 27)
        {
            capt.release();
            cv::destroyAllWindows();
            std::cout << "                                            Finished grabbing" << "\n";
            std::cout << "/********************************************************************************************************************\\";
            break;
        }
    }
}
void detect::on_retBtn_clicked()
{
    this->hide();

    TrainImage *img = new TrainImage();
    img->show();
}
