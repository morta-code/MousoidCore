#ifndef ETHERNET_HPP
#define ETHERNET_HPP

#include <QtNetwork>

class Ethernet : public QObject
{
    Q_OBJECT
public:
    static void create(QString &name, uchar connectionLimitations = 0, QObject *parent = 0);
    static void destroy();
    static Ethernet* self() {return instance;}

    static void listen();
    static void suspend();

    static void addToBlocked(QHostAddress &address);
    static void addToAllowed(QHostAddress &address);
    static void deleteFromAllowed(QHostAddress &address);
    static void deleteFromBlocked(QHostAddress &address);

    static void setLimitations(uchar limitations);

signals:
    void commandArrived(QByteArray&);

private slots:
    void readPendingDatagram();

private:
    Ethernet(QString &name, uchar connectionLimitations = 0, QObject *parent = 0);
    ~Ethernet();

    static Ethernet* instance;

    uchar limitations;
    QUdpSocket *socket;
    QSet<QHostAddress> allowedSet;
    QSet<QHostAddress> blockedSet;
    QString localName;
};

#endif // ETHERNET_HPP
