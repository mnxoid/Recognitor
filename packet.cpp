/**
 * @file	packet.cpp
 * @brief	Packet class implementation
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
#include "packet.h"
#include <QTcpSocket>
#include <QIODevice>
/**
 * @brief       Default Packet constructor
 **/
Packet::Packet()
{
    REQUEST_ID = EMPTY;
    SESSION_ID = 0;
    SIZE = 0;
    DATA = NULL;
}
/**
 * @brief       Copy Packet constructor
 **/
Packet::Packet(Packet &p) : QTcpServer()
{
    this->REQUEST_ID = p.REQUEST_ID;
    this->SESSION_ID = p.SESSION_ID;
    this->SIZE = p.SIZE;
    if (p.SIZE > 0)
    {
        this->DATA = (char*)malloc(p.SIZE);
        memcpy(this->DATA,p.DATA,p.SIZE);
    }
}
/**
 * @brief       Full-parameter Packet constructor
 * @param       [in]        REQUEST_ID - Request type
 * @param       [in]        SESSION_ID - Session key
 * @param       [in]        SIZE - Data size
 * @param       [in]        DATA - Raw packet data
 **/
Packet::Packet(RQTYPE REQUEST_ID, int SESSION_ID, int SIZE, char *DATA)
{
    if (REQUEST_ID <= AUTH || REQUEST_ID >= EMPTY)
    {
        this->REQUEST_ID = INT_ERR;
    } else {
        this->REQUEST_ID = REQUEST_ID;
    }
    this->SESSION_ID = SESSION_ID;
    if (this->REQUEST_ID != INT_ERR)
    {
        this->SIZE = SIZE;
        this->DATA = (char*)malloc(SIZE);
        memcpy(this->DATA,DATA,SIZE);
    } else {
        this->SIZE = 0;
        this->DATA = NULL;
    }
}
/**
 * @brief       Raw packet getter
 * @return      QByteArray - packet (ready to be sent)
 **/
QByteArray Packet::getBytes()
{
    QByteArray qa;
    char* raw=(char*)malloc(2*sizeof(int)+sizeof(RQTYPE)+SIZE);
    *((RQTYPE*)raw)=REQUEST_ID;
    *((int*)(raw+sizeof(RQTYPE)))=SESSION_ID;
    *((int*)(raw+sizeof(RQTYPE))+1)=SIZE;
    memcpy((char*)raw+sizeof(RQTYPE)+2*sizeof(int),DATA,SIZE);
    qa.fromRawData(raw,2*sizeof(int)+sizeof(RQTYPE)+SIZE);
    free(raw);
    return qa;
}
/**
 * @brief       Communication function
 * @param       [in]        IP - server IP-address
 * @param       [in]        port - server port
 * @return      Packet - server response
 **/
Packet* Packet::send(QString IP, int port)
{
    QTcpSocket socket(this);
    socket.connectToHost(IP,port);
    QDataStream stream(&socket);
    stream << this->getBytes();
    QByteArray resp;
    resp = socket.readAll();
    char *data = (char*)malloc(resp.size());
    memcpy(data,resp.data(),resp.size());
    Packet* response = new Packet((RQTYPE)(*((int*)data)),
                    (*((int*)data+1)),
                    (*((int*)data+2)),
                    data+3*sizeof(int)
                    );
    if (response->validate())
    {
        return response;
    } else {
        delete response;
        return new Packet();
    }
}
/**
 * @brief       Request ID getter
 * @return      RQTYPE - Request ID
 * @see         RQTYPE
 **/
RQTYPE Packet::getRequestID()
{
    return REQUEST_ID;
}

/**
 * @brief       Session ID getter
 * @return      int - Session ID
 **/
int Packet::getSessionID()
{
    return SESSION_ID;
}

/**
 * @brief       Raw data size getter
 * @return      int - Raw data size
 **/
int Packet::getDataSize()
{
    return SIZE;
}

/**
 * @brief       Raw data getter
 * @return      char* - Raw data
 **/
char* Packet::rawData()
{
    return DATA;
}
/**
 * @brief       Packet validator
 * @return      bool - result
 **/
bool Packet::validate()
{
    if (REQUEST_ID <= AUTH || REQUEST_ID >= EMPTY) return false;
    if (SIZE > 0 && DATA==NULL) return false;
    return true;
}
