/**
 * @file	userscreen.h
 * @brief	User window header
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

#ifndef USERSCREEN_H
#define USERSCREEN_H

#include <QMainWindow>
#include <opencv2/highgui/highgui.hpp>
#include <QTimer>

namespace Ui {
class UserScreen;
}
/**
 * @brief       User window class
 **/
class UserScreen : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief       UserScreen constructor
     * @param       [in]    parent - Window parent
     **/
    explicit UserScreen(QWidget *parent = 0);
    /**
     * @brief       UserScreen destructor
     **/
    ~UserScreen();
public slots:
    /**
     * @brief       Unexpected end of capturing handler
     **/
    void respond();
    /**
     * @brief       Camera stream receiver
     **/
    void imShow(cv::Mat m);
    /**
     * @brief       Sender
     **/
    void sendPic();

private slots:
    /**
     * @brief       Exit button click handler
     **/
    void on_pushButton_2_clicked();

    /**
     * @brief       Start button click handler
     **/
    void on_pushButton_clicked();
    /**
     * @brief       Capture stopping handler
     **/
    void captureStop();
signals:
    /**
     * @brief       Capture stopper
     **/
    void stopCap();
private:
    Ui::UserScreen *ui; //!< User interface reference
    QTimer* t;          //!< Timer instance
};

#endif // USERSCREEN_H
