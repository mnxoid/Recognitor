#include "keyenterreceiver.h"

keyEnterReceiver::keyEnterReceiver(QObject *parent) :
    QObject(parent)
{
}

bool keyEnterReceiver::eventFilter(QObject *obj, QEvent *event)
{
    if(event->type() == QEvent::KeyPress)
    {
        QKeyEvent *key = static_cast<QKeyEvent *>(event);

        if((key->key() == Qt::Key_Enter) || (key->key() == Qt::Key_Return))
        {
            emit enterPressed();
        }
        else
        {
            return QObject::eventFilter(obj, event);
        }
        return true;
    }
    else
    {
        return QObject::eventFilter(obj, event);
    }

    return false;
}
