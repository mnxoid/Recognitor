/**
 * @file	exuserscreen.cpp
 * @brief	Extended User window implementation
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
#include "exuserscreen.h"
#include "ui_exuserscreen.h"
#include "windowmanager.h"
#include <QMessageBox>
#include "cameracapture.h"
extern WindowManager WMgr;
CameraCapture* cc;
ExUserScreen::ExUserScreen(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::ExUserScreen)
{
    ui->setupUi(this);
}

ExUserScreen::~ExUserScreen()
{
    delete ui;
}

void ExUserScreen::on_pushButton_2_clicked()
{
    WMgr.xu->hide();
    WMgr.mw->show();
}

void ExUserScreen::on_pushButton_clicked()
{
    cc = new CameraCapture(this);
    cc->Start();
}

void ExUserScreen::on_pushButton_3_clicked()
{
    WMgr.xu->hide();
    WMgr.gs->show();
    cc->End();
    delete cc;
}
