/**
 * @file	adminscreen.h
 * @brief	Administration window header
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

#ifndef ADMINSCREEN_H
#define ADMINSCREEN_H

#include <QMainWindow>

namespace Ui {
class AdminScreen;
}

/**
 * @brief       Administrator window class
 **/
class AdminScreen : public QMainWindow
{
    Q_OBJECT
    
public:
    /**
     * @brief       AdminScreen constructor
     * @param       [in]    parent - Window parent
     **/
    explicit AdminScreen(QWidget *parent = 0);
    /**
     * @brief       AdminScreen destructor
     **/
    ~AdminScreen();
    
private slots:
    /**
     * @brief       Exit button click handler
     **/
    void on_pushButton_clicked();

    /**
     * @brief       Add User button click handler
     **/
    void on_pushButton_2_clicked();

    /**
     * @brief       Edit User button click handler
     **/
    void on_pushButton_3_clicked();

    /**
     * @brief       Delete User button click handler
     **/
    void on_pushButton_4_clicked();

private:
    Ui::AdminScreen *ui; //!< User interface reference
};

#endif // ADMINSCREEN_H
