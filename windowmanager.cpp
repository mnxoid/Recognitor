/**
 * @file	windowmanager.cpp
 * @brief	Window switcher class implementation
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

#include "windowmanager.h"

/**
 * @brief       WindowManager constructor
 **/
WindowManager::WindowManager()
{
}
/**
 * @brief       Initialization function
 * @param		[in]		m - MainWindow reference
 * @param		[in]		a - AdminScreen reference
 * @param		[in]		u - UserScreen reference
 * @param		[in]		x - ExUserScreen reference
 * @param		[in]		g - GoodsMgmtScreen reference
 **/
void WindowManager::Init(MainWindow *m, AdminScreen *a, UserScreen *u, ExUserScreen *x, GoodsMgmtScreen *g)
{
    WindowManager::mw = m;
    WindowManager::ad = a;
    WindowManager::us = u;
    WindowManager::xu = x;
    WindowManager::gs = g;
}
