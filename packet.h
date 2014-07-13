/**
 * @file	packet.h
 * @brief	Packet class header
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
#ifndef PACKET_H
#define PACKET_H
#include <QByteArray>
#include <QTcpServer>
/**
 * @brief       Enumeration with types of requests
 **/
typedef enum
{
    AUTH,       //!< Authentication
    RESP_OK,    //!< Good server response
    RESP_ERR,   //!< Bad server response
    EMPTY       //!< No request
} RQTYPE;
/**
 * @brief       A class for Client-Server communication
 **/
class Packet : public QTcpServer
{
private:
    RQTYPE REQUEST_ID;  //!< Request type
    int SESSION_ID;     //!< Session key
    int SIZE;           //!< Data size
    char* DATA;         //!< Raw packet data
public:
    /**
     * @brief       Default Packet constructor
     **/
    Packet();
    /**
     * @brief       Copy Packet constructor
     **/
    Packet(Packet& p);
    /**
     * @brief       Full-parameter Packet constructor
     * @param       [in]        REQUEST_ID - Request type
     * @param       [in]        SESSION_ID - Session key
     * @param       [in]        SIZE - Data size
     * @param       [in]        DATA - Raw packet data
     **/
    Packet(RQTYPE REQUEST_ID, int SESSION_ID, int SIZE, char* DATA);
    /**
     * @brief       Raw packet getter
     * @return      QByteArray - packet (ready to be sent)
     **/
    QByteArray getBytes();
    /**
     * @brief       Communication function
     * @param       [in]        IP - server IP-address
     * @param       [in]        port - server port
     * @return      Packet - server response
     **/
    Packet send(QString IP,int port);
    /**
     * @brief       Request ID getter
     * @return      RQTYPE - Request ID
     * @see         RQTYPE
     **/
    RQTYPE getRequestID();
    /**
     * @brief       Session ID getter
     * @return      int - Session ID
     **/
    int getSessionID();
    /**
     * @brief       Raw data size getter
     * @return      int - Raw data size
     **/
    int getDataSize();
    /**
     * @brief       Raw data getter
     * @return      char* - Raw data
     **/
    char* rawData();
};

#endif // PACKET_H
