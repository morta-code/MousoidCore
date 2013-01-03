#include "ethernet.hpp"
#include "commandemitter.hpp"
#include <QHostInfo>
#include <QDebug>

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
}

void Ethernet::setName(QString &name)
{
    instance->localName = (name == "") ? QHostInfo::localHostName() : name;
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
            qDebug() << "Who are you arrived!" << datagram[1] << sender.toString() << hidden;
            if(hidden)
                continue;
            QByteArray array;
            array += Mousoid::HEADER;
            array += Mousoid::NAME;
            array += localName.length();
            array += localName.toAscii();
            socket->writeDatagram(array, sender, senderPort);
            continue;
        }
        if(datagram[1] == Mousoid::NAME){
            qDebug() << "Name arrived!" << datagram[1] << sender.toString();
            if(blockedSet.contains(sender))
                continue;
            char* _temp = new char[datagram[2]+1];
            for(register uchar i = 0; i < datagram[2]; ++i){
                _temp[i] = datagram[3+i];
            }
            _temp[datagram[2]] = 0;
            newClientCallback(_temp, sender.toString().toAscii().data());
        }

        switch (limitations) {
        case Mousoid::ONLY_FROM_SET_ALLOWED:
            if(!allowedSet.contains(sender)){
                continue;
            }
            break;
        case Mousoid::ONLY_FROM_SET_BLOCKED:
            if(blockedSet.contains(sender)){
                continue;
            }
        default:
            break;
        }
        CommandEmitter::executeCommand(datagram);
    }
}

Ethernet::Ethernet(uchar connectionLimitations, QObject *parent) : QObject(parent)
{
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
