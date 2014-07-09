/**
 * @file	goodsmgmtscreen.h
 * @brief	Goods management window header
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

#ifndef GOODSMGMTSCREEN_H
#define GOODSMGMTSCREEN_H

#include <QMainWindow>

namespace Ui {
class GoodsMgmtScreen;
}

class GoodsMgmtScreen : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit GoodsMgmtScreen(QWidget *parent = 0);
    ~GoodsMgmtScreen();
    
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::GoodsMgmtScreen *ui;
};

#endif // GOODSMGMTSCREEN_H
