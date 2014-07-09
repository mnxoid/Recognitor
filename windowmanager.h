/**
 * @file	windowmanager.h
 * @brief	Window switcher class header
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

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H
#include "mainwindow.h"
#include "adminscreen.h"
#include "userscreen.h"
#include "exuserscreen.h"
#include "goodsmgmtscreen.h"
/**
 * @brief       A class for switching between windows of the application
 **/
class WindowManager
{
public:
    /**
     * @brief       WindowManager constructor
     **/
    WindowManager();
    /**
     * @brief       Initialization function
     * @param		[in]		m - MainWindow reference
     * @param		[in]		a - AdminScreen reference
     * @param		[in]		u - UserScreen reference
     * @param		[in]		x - ExUserScreen reference
     * @param		[in]		g - GoodsMgmtScreen reference
     **/
    void Init(MainWindow* m, AdminScreen* a, UserScreen* u, ExUserScreen* x, GoodsMgmtScreen* g);
    MainWindow* mw; //!< MainWindow reference
    AdminScreen* ad; //!< AdminScreen reference
    UserScreen* us; //!< UserScreen reference
    ExUserScreen* xu; //!< ExUserScreen reference
    GoodsMgmtScreen* gs; //!< GoodsMgmtScreen reference
};

#endif // WINDOWMANAGER_H
