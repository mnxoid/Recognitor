/**
 * @file	exuserscreen.h
 * @brief	Extended User window header
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

#ifndef EXUSERSCREEN_H
#define EXUSERSCREEN_H

#include <QMainWindow>
#include <opencv2/highgui/highgui.hpp>
#include <QTimer>

namespace Ui {
class ExUserScreen;
}
/**
 * @brief       Extended User window class
 **/
class ExUserScreen : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief       ExUserScreen constructor
     * @param       [in]    parent - Window parent
     **/
    explicit ExUserScreen(QWidget *parent = 0);
    /**
     * @brief       ExUserScreen destructor
     **/
    ~ExUserScreen();
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
     * @brief       Manage Goods button click handler
     **/
    void on_pushButton_3_clicked();
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
    Ui::ExUserScreen *ui; //!< User interface reference
    QTimer* t;          //!< Timer instance
};

#endif // EXUSERSCREEN_H
