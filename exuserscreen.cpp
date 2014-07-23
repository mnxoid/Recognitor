/**
* @file exuserscreen.cpp
* @brief Extended User window implementation
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
#include "exuserscreen.h"
#include "ui_exuserscreen.h"
#include "windowmanager.h"
#include <QMessageBox>
#include "cameracapture.h"
#include "cvtoqt.h"
#include <QDebug>
#include "packet.h"
#include <QTimer>
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
* @brief ExUserScreen constructor
* @param [in] parent - Window parent
**/
ExUserScreen::ExUserScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExUserScreen)
{
    ui->setupUi(this);
    connect(this, SIGNAL(stopCap()), this, SLOT(captureStop()));
    t = NULL;
}
/**
* @brief ExUserScreen destructor
**/
ExUserScreen::~ExUserScreen()
{
    delete ui;
}
/**
* @brief Exit button click handler
**/
void ExUserScreen::on_pushButton_2_clicked()
{
    emit stopCap();
    WMgr.xu->hide();
    WMgr.mw->show();
}
/**
* @brief Start button click handler
**/
void ExUserScreen::on_pushButton_clicked()
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
* @brief Manage Goods button click handler
**/
void ExUserScreen::on_pushButton_3_clicked()
{
    emit stopCap();
    WMgr.xu->hide();
    WMgr.gs->show();
}
/**
* @brief Unexpected end of capturing handler
**/
void ExUserScreen::respond()
{
     emit stopCap();
}
/**
* @brief Camera stream receiver
**/
void ExUserScreen::imShow(cv::Mat m)
{
   // qDebug() << "ExUserScreen::imShow called";
    QImage qm = MatToQImage(m);
    QPixmap px;
    px.convertFromImage(qm);
    QPixmap scaledPixmap = px.scaled(ui->label_3->size(), Qt::KeepAspectRatio);
    ui->label_3->setPixmap( scaledPixmap);
}
/**
 * @brief       Capture stopping handler
 **/
void ExUserScreen::captureStop()
{
    if(isCapturing)
    {
        isCapturing = 0;
        ui->pushButton->setText("START");
        cc->terminate();
        cc->End();
        delete cc;
    }
    if(t)
    {
        t->stop();
        delete t;
    }
}

/**
 * @brief       Sender
 **/
void ExUserScreen::sendPic()
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
            qDebug() << "Error sending pic";
        }
    }
}
