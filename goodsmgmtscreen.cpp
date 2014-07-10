/**
 * @file	goodsmgmtscreen.cpp
 * @brief	Goods management window implementation
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

#include "goodsmgmtscreen.h"
#include "ui_goodsmgmtscreen.h"
#include "windowmanager.h"
#include <QMessageBox>
/**
 * @brief       Window Manager instance
 * @see         main.cpp
 **/
extern WindowManager WMgr;
/**
 * @brief       GoodsMgmtScreen constructor
 * @param       [in]    parent - Window parent
 **/
GoodsMgmtScreen::GoodsMgmtScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GoodsMgmtScreen)
{
    ui->setupUi(this);
}
/**
 * @brief       GoodsMgmtScreen destructor
 **/
GoodsMgmtScreen::~GoodsMgmtScreen()
{
    delete ui;
}
/**
 * @brief       Add Item button click handler
 **/
void GoodsMgmtScreen::on_pushButton_clicked()
{
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Sorry, this feature will be implemented in the near future.");
    msg->setWindowTitle("Oops!");
    msg->show();
}
/**
 * @brief       Edit Item button click handler
 **/
void GoodsMgmtScreen::on_pushButton_2_clicked()
{
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Sorry, this feature will be implemented in the near future.");
    msg->setWindowTitle("Oops!");
    msg->show();
}
/**
 * @brief       Remove Item button click handler
 **/
void GoodsMgmtScreen::on_pushButton_3_clicked()
{
    QMessageBox* msg = new QMessageBox(this);
    msg->setText("Sorry, this feature will be implemented in the near future.");
    msg->setWindowTitle("Oops!");
    msg->show();
}
/**
 * @brief       Exit button click handler
 **/
void GoodsMgmtScreen::on_pushButton_4_clicked()
{
    WMgr.gs->hide();
    WMgr.xu->show();
}
