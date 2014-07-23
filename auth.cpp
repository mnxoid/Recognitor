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
#include <QDebug>
#include "packet.h"
extern int session; //!< Current SESSION_ID
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
    char *data = (char*)malloc(2*sizeof(int)+login.length()+pwd.length());
    *((int*)data) = login.length();
    *((int*)data+1) = pwd.length();
    strncpy(data+2*sizeof(int),login.toStdString().c_str(),login.length());
    strncpy(data+2*sizeof(int)+login.length(),pwd.toStdString().c_str(),pwd.length());
    Packet p(AUTH,session,2*sizeof(int)+login.length()+pwd.length(),data);
//    Packet resp = p.send("127.0.0.1",1337);
//    if (resp.getRequestID()==RESP_OK)
//    {
//        session = resp.getSessionID();
//        data = resp.rawData();
//        Access a = *((Access*)data);
         // QList
//        return a;
        free(data);
        if (login == "Admin") {
            return ADMIN;
        } else if (login == "ExUser") {
            return EXUSER;
        } else if (login == "User") {
            return USER;
        } else {
            return DENIED;
        }
//    } else {
//        qDebug() << "Error: Bad request";
//    }
}
#undef AUTH_CPP
