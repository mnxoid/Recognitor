/**
 * @file	cvtoqt.h
 * @brief	OpenCV-Qt conversion header
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
#ifndef CVTOQT_H
#define CVTOQT_H

#include <opencv2/highgui/highgui.hpp>

/**
 * @brief       This function converts cv::Mat to QImage
 * @param		[in]		mat - reference to the cv::Mat to convert
 *
 * @return		QImage      Converted from cv::Mat
 *
 **/
extern QImage MatToQImage(const cv::Mat& mat);

#endif // CVTOQT_H
