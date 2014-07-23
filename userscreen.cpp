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
#include "packet.h"
#include <QTimer>
#include <QPainter>

extern int isCapturing; //!< Determines, whether capturing session is active
extern int session; //!< Session ID
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
    connect(this, SIGNAL(stopCap()), this, SLOT(captureStop()));
    t = NULL;
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
        t = new QTimer();
        connect(t, SIGNAL(timeout()), this, SLOT(sendPic()));
        t->start(ui->spinBox->value());
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
    QPainter* paint = new QPainter(&scaledPixmap);
    paint->drawRect(ui->horizontalSlider->value(),ui->horizontalSlider_2->value(),ui->horizontalSlider_3->value(),ui->horizontalSlider_4->value());
    ui->label_3->setPixmap( scaledPixmap);
    delete paint;
}
/**
 * @brief       Capture stopping handler
 **/
void UserScreen::captureStop()
{
    disconnect(this,SLOT(imShow(cv::Mat)));
    disconnect(this,SLOT(sendPic()));
    if(isCapturing)
    {
        isCapturing = 0;
        ui->pushButton->setText("START");
        cc->End();
        delete cc;
    }
    if(t->isActive())
    {
        t->stop();
        delete t;
    }
}

/**
 * @brief       Sender
 **/
void UserScreen::sendPic()
{
    if(ui->label_3->pixmap())
    {
        char *d;
        int size = ui->label_3->pixmap()->toImage().byteCount();
        d = (char*)ui->label_3->pixmap()->toImage().bits();
        Packet p(PIC_SEND, session, size, d);
        Packet* resp = p.send("127.0.0.1",1337);
        if (resp->getRequestID() != RESP_OK)
        {
            qDebug() << "Error sending pic: byte count = " << size;
        }
        delete resp;
    }
}
