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

namespace Ui {
class ExUserScreen;
}

class ExUserScreen : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit ExUserScreen(QWidget *parent = 0);
    ~ExUserScreen();
    
private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ExUserScreen *ui;
};

#endif // EXUSERSCREEN_H
