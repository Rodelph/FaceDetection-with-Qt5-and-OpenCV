#include "./Header/imgproc.h"
#include "ui_imgproc.h"
#include <opencv2/core/hal/interface.h>
#include <opencv2/imgproc.hpp>
#include <opencv4/opencv2/imgproc.hpp>

ImgProc::ImgProc(QWidget *parent) : QMainWindow(parent),
                                    ui(new Ui::ImgProc)
{
    ui->setupUi(this);

    deviceID = 0;
    apiID = cv::CAP_ANY;
    count = 0;
    error = new QErrorMessage(this);
}

ImgProc::~ImgProc() 
{ 
    delete ui;
    cap.release();
    cv::destroyAllWindows();
}

void ImgProc::setUpCam()
{
    cap.open(deviceID, apiID);
   
    if (!cap.isOpened()) error->showMessage("Error ! Unable to open camera because it is being used in another program !\n");
    std::cout << "/******************************************************* INFO *******************************************************\\";
    std::cout << "                                                    Start grabbing" << "\n";
}

cv::Mat ImgProc::deployCam(cv::Mat& _frame)
{
    cap.read(_frame);

    return _frame;
}

cv::Mat ImgProc::detectFace(cv::Mat& _frameDet, std::string& _namePerson)
{
    face_cascade.load(backToOrigin + "HaarCascadeXML/haarcascade_frontalface_alt.xml"); 

    if (face_cascade.empty()) std::cerr << "The cascade classifier is empty ! \n";

    face_cascade.detectMultiScale(_frameDet, faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));

    for (int i = 0; i < faces.size(); i++)
    {
        std::filesystem::create_directories("res/" + _namePerson);
        cv::cvtColor(_frameDet, _frameDet, cv::COLOR_BGR2GRAY);
        cv::imwrite("res/" + _namePerson + "/" + std::to_string(count) + ".png", _frameDet);
        cv::cvtColor(_frameDet, _frameDet, cv::COLOR_GRAY2BGR);
        cv::Point center(faces[i].x + faces[i].width * 0.5, faces[i].y + faces[i].height * 0.5);
        ellipse(_frameDet, center, cv::Size(faces[i].width * 0.5, faces[i].height * 0.5), 0, 0, 360, cv::Scalar(0, 255, 0), 1, 8, 0);
        count++;
    }
 
    return _frameDet;
}

void ImgProc::on_startBtn_clicked()
{
    name = ui->editName->text().toStdString();
    if(name == "") 
        error->showMessage("Please select a name !");
    else if(name != "")
    {
    setUpCam();
    cap.set(cv::CAP_PROP_FRAME_WIDTH, 1280);
    cap.set(cv::CAP_PROP_FRAME_HEIGHT,720); 

    for (;;)
        {
            deployCam(frame);
            detectFace(frame, name);

            if (frame.empty()) {
                std::cerr << "ERROR! blank frame grabbed\n";
                break;
            }

            cv::imshow("Video capturing", frame);

            if (cv::waitKey(5) >= 27) 
            {   
                cap.release();
                cv::destroyAllWindows();
                std::cout << "                                            Finished grabbing" << "\n";
                std::cout << "/********************************************************************************************************************\\";
                break;
            }
        }
    }
}

void ImgProc::on_retBtn_clicked()
{
    this->hide();

    train = new TrainImage();
    train->show();
}

void ImgProc::on_actionHow_it_works_triggered()
{
    QMessageBox::information(this,
                             "Info on how it works",
                             this->_howItWorks
                             );
}

void ImgProc::on_actionCheck_stored_images_triggered()
{
    path = QFileDialog::getOpenFileName(this, 
                                       "Open stored images",
                                        pathToFiles,
                                        "Image (*.png)"
                                        );   
}
