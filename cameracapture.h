/**
 * @file	cameracapture.h
 * @brief	Camera capturing class header
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
#ifndef CAMERACAPTURE_H
#define CAMERACAPTURE_H
#include <pthread.h>
#include <opencv2/highgui/highgui.hpp>
#include <QWidget>
/**
 * @brief       The arguments for the capturing thread function
 * @see         lf()
 **/
struct ARGS
{
    pthread_t pid;          //!< Capturing thread handle
    cv::VideoCapture* cap;  //!< VideoCapture object
    QWidget* parent;        //!< Parent object (caller)
};
/**
 * @brief       A class for capturing frames from the camera
 **/
class CameraCapture
{
public:
    /**
     * @brief       CameraCapture constructor
     * @param		[in]		par - Parent for creating QMessageBox`es
     *
     * @return		QImage      Converted from cv::Mat
     *
     **/
    CameraCapture(QWidget *par);
    /**
     * @brief       This function does initialization and starts the capturing thread
     **/
    void Start();
    /**
     * @brief       This function cancels the capturing thread
     **/
    void End();
private:
    cv::VideoCapture* cap;
    pthread_t pid;//!< Capturing thread handle
    QWidget* parent;//!< Parent for creating QMessageBox`es
};

#endif // CAMERACAPTURE_H
