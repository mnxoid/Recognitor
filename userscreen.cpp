/**
* @file userscreen.cpp
* @brief User window implementation
* @author mnxoid
*
* Copyright 2014 by mnxoid,
*
* This software is the confidential and proprietary information
* of mnxoid ("Confidential Information"). You
* shall not disclose such Confidential Information and shall use
* it only in accordance with the terms of the license agreement
* you entered into with mnxoid.
**/

#include "userscreen.h"
#include "ui_userscreen.h"
#include "windowmanager.h"
#include <opencv2/highgui/highgui.hpp>
#include "cameracapture.h"
#include "cvtoqt.h"
extern int isCapturing; //!< Determines, whether capturing session is active
/**
* @brief Window Manager instance
* @see main.cpp
**/
extern WindowManager WMgr;
/**
* @brief Camera capture instance
* @see CameraCapture
**/
extern CameraCapture* cc;
/**
* @brief UserScreen constructor
* @param [in] parent - Window parent
**/
UserScreen::UserScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserScreen)
{
    ui->setupUi(this);
}
/**
* @brief UserScreen destructor
**/
UserScreen::~UserScreen()
{
    delete ui;
}
/**
* @brief Exit button click handler
**/
void UserScreen::on_pushButton_2_clicked()
{
    emit stopCap();
    WMgr.mw->show();
    WMgr.us->hide();
}

/**
* @brief Start button click handler
**/
void UserScreen::on_pushButton_clicked()
{
    if (isCapturing == 0)
    {
        isCapturing = 1;
        ui->pushButton->setText("STOP");
        cc = new CameraCapture(this);
        //cc->setParent(this);
        qRegisterMetaType<cv::Mat>("cv::Mat");
        connect(cc, SIGNAL(updatePic(cv::Mat)), this, SLOT(imShow(cv::Mat)));
        connect(cc, SIGNAL(response()), this, SLOT(respond()));
        cc->Start();
        cc->start();
    } else {
        emit stopCap();
    }
}
/**
* @brief Unexpected end of capturing handler
**/
void UserScreen::respond()
{
    emit stopCap();
}
/**
* @brief Camera stream receiver
**/
void UserScreen::imShow(cv::Mat m)
{
    QImage qm = MatToQImage(m);
    QPixmap px;
    px.convertFromImage(qm);
    QPixmap scaledPixmap = px.scaled(ui->label_3->size(), Qt::KeepAspectRatio);
    ui->label_3->setPixmap( scaledPixmap);
}
/**
 * @brief       Capture stopping handler
 **/
void UserScreen::captureStop()
{
    if(isCapturing)
    {
        isCapturing = 0;
        ui->pushButton->setText("START");
        cc->End();
        delete cc;
    }
}

/**
 * @brief       Sender
 **/
void UserScreen::sendPic()
{

}
