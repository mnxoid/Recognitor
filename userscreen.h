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

class UserScreen : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit UserScreen(QWidget *parent = 0);
    ~UserScreen();
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::UserScreen *ui;
};

#endif // USERSCREEN_H
