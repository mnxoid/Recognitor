#ifndef PACKET_H
#define PACKET_H
#include <QByteArray>
#include <QTcpServer>
typedef enum
{
    AUTH,   //!< Authentication
    RESP,   //!< Server response
    EMPTY   //!< No request
} RQTYPE;

class Packet : public QTcpServer
{
private:
    RQTYPE REQUEST_ID;
    int SESSION_ID;
    int SIZE;
    char* DATA;
public:
    Packet();
    Packet(Packet& p);
    Packet(RQTYPE REQUEST_ID, int SESSION_ID, int SIZE, char* DATA);
    QByteArray getBytes();
    Packet send(QString IP,int port);
};

#endif // PACKET_H
