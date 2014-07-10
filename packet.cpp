#include "packet.h"
#include <QTcpSocket>
#include <QIODevice>
Packet::Packet()
{
    REQUEST_ID = EMPTY;
    SESSION_ID = 0;
    SIZE = 0;
    DATA = NULL;
}

Packet::Packet(Packet &p) : QTcpServer()
{
    this->REQUEST_ID = p.REQUEST_ID;
    this->SESSION_ID = p.SESSION_ID;
    this->SIZE = p.SIZE;
    this->DATA = (char*)malloc(p.SIZE);
    memcpy(this->DATA,p.DATA,p.SIZE);
}

Packet::Packet(RQTYPE REQUEST_ID, int SESSION_ID, int SIZE, char *DATA)
{
    this->REQUEST_ID = REQUEST_ID;
    this->SESSION_ID = SESSION_ID;
    this->SIZE = SIZE;
    this->DATA = (char*)malloc(SIZE);
    memcpy(this->DATA,DATA,SIZE);
}

QByteArray Packet::getBytes()
{
    QByteArray qa;
    qa.append(this->REQUEST_ID);
    qa.append(this->SESSION_ID);
    qa.append(this->SIZE);
    qa.append(this->DATA);
    return qa;
}

Packet Packet::send(QString IP, int port)
{
    QTcpSocket socket(this);
    socket.connectToHost(IP,port);
    QDataStream stream(&socket);
    stream << this->getBytes();
    QByteArray resp;
    resp = socket.readAll();
    char *data = resp.data();
    Packet response((RQTYPE)(*((int*)data)),
                    (*((int*)data+1)),
                    (*((int*)data+2)),
                    data+3*sizeof(int)
                    );
    return response;
}
