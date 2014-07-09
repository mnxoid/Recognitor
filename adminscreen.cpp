/**
 * @file	adminscreen.cpp
 * @brief	Administration window implementation
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

#include "adminscreen.h"
#include "ui_adminscreen.h"
#include "windowmanager.h"
#include <QMessageBox>
/**
 * @brief       Window Manager instance
 * @see         main.cpp
 **/
extern WindowManager WMgr;
/**
 * @brief       AdminScreen constructor
 * @param       [in]    parent - Window parent
 **/
AdminScreen::AdminScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminScreen)
{
    ui->setupUi(this);
}
/**
 * @brief       AdminScreen destructor
 **/
AdminScreen::~AdminScreen()
{
    delete ui;
}
/**
 * @brief       Exit button click handler
 **/
void AdminScreen::on_pushButton_clicked()
{
    //Return to login screen
    WMgr.ad->hide();
    WMgr.mw->show();
}
/**
 * @brief       Add User button click handler
 **/
void AdminScreen::on_pushButton_2_clicked()
{
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Sorry, this feature will be implemented in the near future.");
    msg->setWindowTitle("Oops!");
    msg->show();
}
/**
 * @brief       Edit User button click handler
 **/
void AdminScreen::on_pushButton_3_clicked()
{
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Sorry, this feature will be implemented in the near future.");
    msg->setWindowTitle("Oops!");
    msg->show();
}
/**
 * @brief       Delete User button click handler
 **/
void AdminScreen::on_pushButton_4_clicked()
{
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Sorry, this feature will be implemented in the near future.");
    msg->setWindowTitle("Oops!");
    msg->show();
}
