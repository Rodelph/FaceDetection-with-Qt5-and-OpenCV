#ifndef __DETECT_H
#define __DETECT_H

#include "../../Precompiled_H/precom_Header.h"

namespace Ui { class detect; }

class detect : public QMainWindow
{
    Q_OBJECT

    public:
        explicit detect(QWidget *parent = nullptr);
        ~detect();

    private slots:
        void on_pushButton_clicked();
        void on_retBtn_clicked();
        cv::Mat lbpFace(cv::Mat _frame);

    private:
        void setupCam();
        cv::Mat deployCam(cv::Mat& _frame);

        Ui::detect *ui;
       
        cv::VideoCapture capt;
        cv::Mat frame;

        uint8_t deviceID, apiID, count;
        const QString pathToFiles = QDir::currentPath() + "/res/";
};

#endif // __DETECT_H
