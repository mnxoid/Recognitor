/**
 * @file	main.cpp
 * @brief	Main source file
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

#include <QApplication>
#include "mainwindow.h"
#include "windowmanager.h"
#include <X11/Xlib.h>
WindowManager WMgr; //!< WindowManager instance
int main(int argc, char *argv[])
{
    XInitThreads();
    QApplication a(argc, argv);
    MainWindow w;
    AdminScreen as;
    UserScreen us;
    ExUserScreen xu;
    GoodsMgmtScreen gs;
    w.show();
    WMgr.Init(&w,&as,&us,&xu,&gs);
    return a.exec();
}
