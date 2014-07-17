/**
 * @file	mainwindow.cpp
 * @brief	Authorization window source
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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "auth.h"
#include "windowmanager.h"
#include <QMessageBox>
#include "keyenterreceiver.h"
/**
 * @brief       Window Manager instance
 * @see         main.cpp
 **/
extern WindowManager WMgr;
/**
 * @brief       MainWindow constructor
 * @param       [in]    parent - Window parent
 **/
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    keyEnterReceiver *key = new keyEnterReceiver();
    connect(key, SIGNAL(enterPressed()), this, SLOT(on_pushButton_clicked()));
    this->installEventFilter(key);
}
/**
 * @brief       MainWindow destructor
 **/
MainWindow::~MainWindow()
{
    delete ui;
}
/**
 * @brief       Exit button click handler
 **/
void MainWindow::on_pushButton_2_clicked()
{
    //Exit button
    QApplication::quit();
}
/**
 * @brief       Login button click handler
 **/
void MainWindow::on_pushButton_clicked()
{
    //Login button
    Access a = Check(ui->lineEdit->text(),ui->lineEdit_2->text());
    if (a == ADMIN) {
        WMgr.ad->show();
        WMgr.mw->hide();
    } else if(a == EXUSER) {
        WMgr.xu->show();
        WMgr.mw->hide();
    } else if(a == USER) {
        WMgr.us->show();
        WMgr.mw->hide();
    } else {
        QMessageBox* msg = new QMessageBox(this);
        msg->setText("Sorry, wrong login or password");
        msg->setWindowTitle("Authentication error");
        msg->show();
    }
}
