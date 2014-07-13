/**
 * @file	cameracapture.cpp
 * @brief	Camera capturing class implementation
 * @author  mnxoid
 *
 * Copyright 2014 by mnxoid,
 *
 * This software is the confidential and proprietary information
 * of mnxoid ("Confidential Information").  You
 * shall not disclose such Confidential Information and shall use
 * it only in accordance with the terms of the license agreement
 * you entered into with mnxoid.
 **/
#include "cameracapture.h"
#include <opencv2/highgui/highgui.hpp>
#include <pthread.h>
#include <QMessageBox>
#include <QDebug>
/**
 * @brief       CameraCapture constructor
 * @param		[in]		par - Parent for creating QMessageBox`es
 *
 * @return		QImage      Converted from cv::Mat
 *
 **/
CameraCapture::CameraCapture(QWidget* par)
{
    parent = par;
}


/**
 * @brief       This function does initialization and starts the capturing thread
 **/
void CameraCapture::Start()
{
    cap = new cv::VideoCapture(0);
    if (!cap->isOpened())  // if not success, exit program
        {
            QMessageBox* msg = new QMessageBox(parent);
            msg->setText("Sorry, an error occured while trying to read camera device.");
            msg->setWindowTitle("Oops!");
            msg->show();
        }
}
/**
 * @brief       The main function of the thread (capturing routine)
 **/
void CameraCapture::run()
{
    cv::Mat frame;

    while(true)
    {
        bool bSuccess = cap->read(frame); // read a new frame from video
        if (!bSuccess) //if not success, break loop
        {
            qDebug() << "Cannot read a frame from video stream";
            break;
        }
        emit CameraCapture::updatePic(frame);
        cv::waitKey(20);
    }
    qDebug() << "Thread ended";
    if (cap) delete cap;
    emit CameraCapture::response();
}
/**
 * @brief       This function cancels the capturing thread
 **/
void CameraCapture::End()
{
    this->terminate();
    if (cap) delete cap;
}
