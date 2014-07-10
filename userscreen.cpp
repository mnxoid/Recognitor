/**
 * @file	userscreen.cpp
 * @brief	User window implementation
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

#include "userscreen.h"
#include "ui_userscreen.h"
#include "windowmanager.h"
#include <opencv2/highgui/highgui.hpp>
#include "cvtoqt.h"
/**
 * @brief       Window Manager instance
 * @see         main.cpp
 **/
extern WindowManager WMgr;
/**
 * @brief       UserScreen constructor
 * @param       [in]    parent - Window parent
 **/
UserScreen::UserScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::UserScreen)
{
    ui->setupUi(this);
}
/**
 * @brief       UserScreen destructor
 **/
UserScreen::~UserScreen()
{
    delete ui;
}
/**
 * @brief       Exit button click handler
 **/
void UserScreen::on_pushButton_2_clicked()
{
    WMgr.mw->show();//Also consider checking whether scan session is active
    WMgr.us->hide();//Maybe just disable this button
}

/**
 * @brief       Start button click handler
 **/
void UserScreen::on_pushButton_clicked()
{
//    cv::Mat rgb;
//    cv::cvtColor(img, rgb, CV_BGR2RGB);
//    rgb = cv::Mat(rgb.rows, rgb.cols, QImage::Format_RGB888, rgb.data, rgb.bytesPerLine()).clone();
//    QPixmap qp = QPixmap::fromImage(QImage((unsigned char*) img.data, img.cols, img.rows, QImage::Format_RGB888));
//    QGraphicsScene scn;
//    QGraphicsPixmapItem it(qp);
//    scn.addItem(&it);
//    ui->graphicsView->setScene(&scn);
//    ui->graphicsView->show();
    cv::Mat img = cv::imread("/home/mnxoid/Pictures/union_jack.jpg",CV_LOAD_IMAGE_COLOR);
    QImage qm = MatToQImage(img);
    QPixmap px;
    px.convertFromImage(qm);
    QPixmap scaledPixmap = px.scaled(ui->label_3->size(), Qt::KeepAspectRatio);
    ui->label_3->setPixmap( scaledPixmap);
}
