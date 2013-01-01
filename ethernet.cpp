#include "ethernet.hpp"
#include <QHostInfo>

// static field:
Ethernet* Ethernet::instance = 0;


// static members:

void Ethernet::destroy()
{
    instance->socket->close();
    instance->deleteLater();
}

void Ethernet::listen()
{
    qDebug() << "Listening";
    if(instance->socket->isOpen()) return;
    instance->socket->bind(Mousoid::PORT, QUdpSocket::ShareAddress);
    instance->socket->open(QUdpSocket::ReadWrite);
}

void Ethernet::suspend()
{
    instance->socket->close();
}

void Ethernet::addToBlocked(QHostAddress &address)
{
    instance->blockedSet.insert(address);
}

void Ethernet::addToAllowed(QHostAddress &address)
{
    if(instance->limitations == Mousoid::ONLY_ONE_ALLOWED){
        instance->allowedSet.clear();
        instance->allowedSet.insert(address);
    }else{
        instance->allowedSet.insert(address);
    }
}

void Ethernet::deleteFromAllowed(QHostAddress &address)
{
    instance->allowedSet.remove(address);
}

void Ethernet::deleteFromBlocked(QHostAddress &address)
{
    instance->blockedSet.remove(address);
}

void Ethernet::setLimitations(uchar limitations)
{
    instance->limitations = limitations;
    if(limitations == Mousoid::ONLY_ONE_ALLOWED && !instance->allowedSet.isEmpty()){
        QHostAddress e = instance->allowedSet.toList().first();
        instance->allowedSet.clear();
        instance->allowedSet.insert(e);
    }
}

void Ethernet::setName(QString &name)
{
    instance->localName = (name == "") ? QHostInfo::localHostName() : name;
}

void Ethernet::setCommandExecuterFunc(void (*callback)(QByteArray &))
{
    instance->commandArrivedCallback = callback;
}


// non-static members:

void Ethernet::readPendingDatagram()
{
    while(socket->hasPendingDatagrams()){
        QByteArray datagram(socket->pendingDatagramSize(), 0);
        QHostAddress sender;
        quint16 senderPort;
        socket->readDatagram(datagram.data(), datagram.size(), &sender, &senderPort);

        if(datagram[0] != Mousoid::HEADER){
            continue;
        }

        if(datagram[1] == Mousoid::WHO_ARE_YOU){
            QByteArray array;
            array += Mousoid::HEADER;
            array += Mousoid::NAME;
            array += localName.length();
            array += localName.toAscii();
            socket->writeDatagram(array, sender, senderPort);
            continue;
        }
        if(datagram[1] == Mousoid::NAME){
            if(blockedSet.contains(sender))
                continue;
            char* _temp = new char[command[2]+1];
            for(register uchar i = 0; i < command[2]; ++i){
                _temp[i] = command[3+i];
            }
            _temp[command[2]] = 0;
            qDebug() << _temp << sender.toString();
            newClientCallback(_temp);
        }

        switch (limitations) {
        case Mousoid::ONLY_FROM_SET_ALLOWED:
        case Mousoid::ONLY_ONE_ALLOWED:
            if(!allowedSet.contains(sender)){
                qDebug() << sender.toString() << "Datagram arrived not from allowed address";
                continue;
            }
        case Mousoid::ONLY_FROM_SET_BLOCKED:
            if(blockedSet.contains(sender)){
                qDebug() << sender.toString() << "Datagram arrived from blocked address";
                continue;
            }
        default:
            break;
        }

        commandArrivedCallback(datagram);
    }
}

Ethernet::Ethernet(uchar connectionLimitations, QObject *parent) : QObject(parent)
{
    qDebug() << "Ethernet created";
    localName = QHostInfo::localHostName();
    limitations = connectionLimitations;
    socket = new QUdpSocket(this);
    connect(socket, SIGNAL(readyRead()), this, SLOT(readPendingDatagram()));
}

Ethernet::~Ethernet()
{
    socket->close();
    delete socket;
    allowedSet.clear();
    blockedSet.clear();
}
