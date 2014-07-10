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
    
private slots:
    /**
     * @brief       Exit button click handler
     **/
    void on_pushButton_2_clicked();

    /**
     * @brief       Start button click handler
     **/
    void on_pushButton_clicked();

private:
    Ui::UserScreen *ui; //!< User interface reference
};

#endif // USERSCREEN_H
