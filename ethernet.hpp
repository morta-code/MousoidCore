#ifndef ETHERNET_HPP
#define ETHERNET_HPP

#include <QtNetwork>
#include "mousoid_constants.hpp"

class Ethernet : public QObject
{
    Q_OBJECT
public:
    inline static void create(uchar connectionLimitations = Mousoid::NO_LIMITATION, QObject *parent = 0){
        instance = new Ethernet(connectionLimitations, parent);
    }

    static void destroy();
    static Ethernet* self() {return instance;}

    static void listen();
    static void suspend();

    static void addToBlocked(QHostAddress &address);
    static void addToAllowed(QHostAddress &address);
    static void deleteFromAllowed(QHostAddress &address);
    static void deleteFromBlocked(QHostAddress &address);

    static void setLimitations(uchar limitations);
    static void setName(QString &name);
    static void setCommandExecuterFunc(void (* callback)(QByteArray &datagram));

signals:
    void commandArrived(QByteArray&);

private slots:
    void readPendingDatagram();

private:
    Ethernet(uchar connectionLimitations = 0, QObject *parent = 0);
    ~Ethernet();

    static Ethernet* instance;

    uchar limitations;
    QUdpSocket *socket;
    QSet<QHostAddress> allowedSet;
    QSet<QHostAddress> blockedSet;
    QString localName;
    void (* commandArrivedCallback)(QByteArray &datagram);
};

#endif // ETHERNET_HPP
