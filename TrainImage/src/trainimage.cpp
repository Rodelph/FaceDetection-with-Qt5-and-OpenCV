#include "./Header/trainimage.h"
#include "ui_trainimage.h"

TrainImage::TrainImage(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TrainImage)
{
    ui->setupUi(this);

    deviceID = 0;
    apiID = cv::CAP_ANY;
    count = 0;
    height = 0;
    width = 0;
    x = 0;
    y = 0;
}

TrainImage::~TrainImage()
{
    delete ui;
    cap.release();
    cv::destroyAllWindows();
}

std::string TrainImage::setUpCam()
{
    cap.open(deviceID, apiID);
   
    if (!cap.isOpened()) std::cerr << "Error ! Unable to open camera \n";

    std::cout << "Start grabbing" << "\n";
    std::cout << "Please select a name : ";
    std::cin >> name;
    return name;
}

cv::Mat TrainImage::deployCam(cv::Mat& _frame)
{
    cap.read(_frame);

    return _frame;
}

void TrainImage::captureImage(cv::Mat& _frameCapt, std::string _namePerson)
{
    std::filesystem::create_directories("res/" + _namePerson);
    cv::imwrite("res/" + _namePerson + "/" + std::to_string(count) + ".png", _frameCapt);
}


cv::Mat TrainImage::detectFace(cv::Mat& _frameDet)
{
    face_cascade.load(backToOrigin + "HaarCascadeXML/haarcascade_frontalface_alt.xml"); 

    if (face_cascade.empty()) std::cerr << "The cascade classifier is empty ! \n";

    face_cascade.detectMultiScale(frame, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    for (int i = 0; i < faces.size(); i++)
    {
        captureImage(frame, name);
        cv::Point center(faces[i].x + faces[i].width * 0.5, faces[i].y + faces[i].height * 0.5);
        ellipse(frame, center, cv::Size(faces[i].width * 0.5, faces[i].height * 0.5), 0, 0, 360, cv::Scalar(0, 255, 0), 1, 8, 0);
        count++;
    }

    return frame;
}

void TrainImage::on_openCam_clicked()
{
    setUpCam();
    cv::Rect rect(x, y, width, height);
    cap.set(cv::CAP_PROP_FRAME_WIDTH,640);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT,480); 

    for (;;)
    {
        deployCam(frame);
        
        detectFace(frame);

        if (frame.empty()) {
            std::cerr << "ERROR! blank frame grabbed\n";
            break;
        }
        
        cv::imshow("Capturing images", frame);

        if (cv::waitKey(5) >= 27) 
        {   
            cap.release();
            cv::destroyAllWindows();
            break;
        }
    }
}