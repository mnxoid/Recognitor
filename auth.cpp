/**
 * @file	auth.cpp
 * @brief	Authentication implementation
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

#define AUTH_CPP
#include "auth.h"
#include <QString>
/**
 * @brief       The authentication function
 * @param		[in]		login - User name
 * @param		[in]		pwd - User password
 *
 * @return		Access      Privilege level
 * @see         Access
 *
 **/
Access Check(QString login, QString pwd)
{
    if (login == "Admin") {
        return ADMIN;
    } else if (login == "ExUser") {
        return EXUSER;
    } else if (login == "User") {
        return USER;
    } else {
        return DENIED;
    }
}
#undef AUTH_CPP
