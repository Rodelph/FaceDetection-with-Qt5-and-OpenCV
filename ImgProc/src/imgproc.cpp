#include "../../InfoOnApp/src/Header/infoapp.h"
#include "./Header/imgproc.h"
#include "ui_imgproc.h"

#define WIDTH 1280
#define HEIGHT 720

ImgProc::ImgProc(QWidget *parent) : QMainWindow(parent),
                                    ui(new Ui::ImgProc)
{
    ui->setupUi(this);

    this->deviceID = 0;
    this->apiID = 0; //Check apiID for windows
    this->count = 0;
    this->error = new QErrorMessage(this);
}

ImgProc::~ImgProc() 
{ 
    delete ui;
    this->cap.release();
    cv::destroyAllWindows();
}

void ImgProc::setUpCam()
{
    this->cap.open(this->deviceID, this->apiID);
    this->cap.set(cv::CAP_PROP_FOURCC, cv::VideoWriter::fourcc('M', 'J', 'P', 'G'));
    this->cap.set(cv::CAP_PROP_FRAME_WIDTH, WIDTH);
    this->cap.set(cv::CAP_PROP_FRAME_HEIGHT, HEIGHT);
    printf("Camera apiID :: %d\n", this->apiID);
    if (!cap.isOpened()) error->showMessage("Error ! Unable to open camera because it is being used in another program !\n");
    std::cout << "/******************************************************* INFO *******************************************************\\";
    std::cout << "                                                    Start grabbing" << "\n";
}

cv::Mat ImgProc::deployCam(cv::Mat& _frame)
{
    this->cap.read(_frame);
    std::cout << "FPS :: " << this->cap.get(cv::CAP_PROP_FPS) << "\n";
    return _frame;
}

cv::Mat ImgProc::detectFace(cv::Mat& _frameDet, std::string& _namePerson)
{
    this->face_cascade.load(this->backToOrigin + "HaarCascadeXML/haarcascade_frontalface_alt.xml");
    if (this->face_cascade.empty()) std::cerr << "The cascade classifier is empty ! \n";

    this->face_cascade.detectMultiScale(_frameDet, this->faces, 1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
    std::filesystem::create_directories("res/" + _namePerson);
     
    for (int i = 0; i < this->faces.size(); i++)
    {
        cv::imwrite("res/" + _namePerson + "/" + std::to_string(this->count) + ".png", _frameDet);
        cv::Point center(this->faces[i].x + this->faces[i].width * 0.5, this->faces[i].y + this->faces[i].height * 0.5);
        ellipse(_frameDet, center, cv::Size(this->faces[i].width * 0.5, this->faces[i].height * 0.5), 0, 0, 360, cv::Scalar(0, 255, 0), 1, 8, 0);
        this->count++;
    }
 
    return _frameDet;
}

cv::Mat ImgProc::filterGpu(std::string& _namePerson, cv::Mat& _frameUp, cv::Mat& _frameDown)
{
    this->srcGpu.upload(_frameUp);
    /*
     *Detect face cascade
     */
    this->srcGpu.copyTo(this->dstGpu);
    this->dstGpu.download(_frameDown);
    return _frameDown;
}

void ImgProc::on_startBtn_clicked()
{
    this->name = ui->editName->text().toStdString();
    
    if(this->name.empty()) this->error->showMessage("Please select a name !");
    else if(!this->name.empty())
    {
        setUpCam();
        
        for (;;)
        {
            deployCam(this->frame);
            detectFace(this->frame, this->name);
            filterGpu(this->name, this->frame, this->frameGpu); 
            if (this->frameGpu.empty()) {
                std::cerr << "ERROR::Blank frame grabbed\n";
                break;
            }

            cv::imshow("Camera Capture", this->frameGpu);

            if (cv::waitKey(5) >= 27) 
            {   
                this->cap.release();
                cv::destroyAllWindows();
                std::cout << "\nFinished grabbing !\n";
                printf("\n%d images were saved !\n", this->count);
                break;
            }
        }
    }
}

void ImgProc::on_retBtn_clicked()
{
    this->hide();

    InfoOnApp *info = new InfoOnApp();
    info->show();
}

void ImgProc::on_actionMore_info_triggered()
{
    QMessageBox::information(this,
                             "Info on how it works",
                             this->_howItWorks
                             );
}