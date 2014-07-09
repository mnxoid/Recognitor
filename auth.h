/**
 * @file	auth.h
 * @brief	Authentication header
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

#ifndef AUTH_H
#define AUTH_H
/**
 * @brief       Enumeration with types of access privileges
 **/
typedef enum
{
    ADMIN,  //!< Administrator privileges
    EXUSER, //!< Extended user privileges
    USER,   //!< Default user privileges
    DENIED  //!< Access denied
}Access;
#ifndef AUTH_CPP
/**
 * @brief       The authentication function
 * @param		[in]		login - User name
 * @param		[in]		pwd - User password
 *
 * @return		Access      Privilege level
 * @see         Access
 *
 **/
extern Access Check(QString login, QString pwd);
#endif
#endif // AUTH_H
