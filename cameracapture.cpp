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
 * @brief       The capturing thread function
 * @param		[in]		arg - the arguments
 * @see         ARGS
 *
 * @return		void*       NULL
 *
 **/
void* lf(void* arg);
/**
 * @brief       This function does initialization and starts the capturing thread
 **/
void CameraCapture::Start()
{
    cv::VideoCapture cap(0);
    if (!cap.isOpened())  // if not success, exit program
        {
            QMessageBox* msg = new QMessageBox(parent);
            msg->setText("Sorry, an error occured while trying to read camera device.");
            msg->setWindowTitle("Oops!");
            msg->show();
        }
    //double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
    //double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video
    ARGS arg;
    arg.pid = pid;
    arg.cap = &cap;
    //arg.parent = parent;
    int err = pthread_create(&pid, NULL, &lf, &arg);
    if (err != 0)
    {
        QMessageBox* msg = new QMessageBox(parent);
        msg->setText("Sorry, an error occured while trying to create a thread.");
        msg->setWindowTitle("Oops!");
        msg->show();
    }
}
void* lf(void* arg)
{
    cv::Mat frame;
    ARGS* args = (ARGS*)arg;
    while(true)
    {
        bool bSuccess = args->cap->read(frame); // read a new frame from video

        if (!bSuccess) //if not success, break loop
        {
//            QMessageBox* msg = new QMessageBox(NULL);
//            msg->setText("Cannot read a frame from video stream");
//            msg->setWindowTitle("Oops!");
//            msg->show();
            qDebug() << "Cannot read a frame from video stream";
            break;
        }

                cv::imshow("MyVideo", frame); //show the frame in "MyVideo" window

                if (cv::waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
        {

        break;
        }
    }
    qDebug() << "Thread ended";
    return NULL;
}
/**
 * @brief       This function cancels the capturing thread
 **/
void CameraCapture::End()
{
    pthread_cancel(pid);
}
