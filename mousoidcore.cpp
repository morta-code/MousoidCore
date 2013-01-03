#include "mousoidcore.hpp"
#include "ethernet.hpp"
#include <QtNetwork>

MousoidCore* MousoidCore::instance = 0;


// Static functions

void MousoidCore::changeServerState(uchar state)
{
    instance->c = state;
    if(state & Mousoid::SERVER_ENABLED){
        Ethernet::listen();
    } else {
        Ethernet::suspend();
    }
    Ethernet::self()->hidden = (state & Mousoid::HIDDEN_MODE);

}

void MousoidCore::addToBlocked(QString &address)
{
    QHostAddress addr(address);
    Ethernet::addToBlocked(addr);
    Ethernet::deleteFromAllowed(addr);
}

void MousoidCore::addToAllowed(QString &address)
{
    QHostAddress addr(address);
    Ethernet::addToAllowed(addr);
    Ethernet::deleteFromBlocked(addr);
}

void MousoidCore::removeFromSets(QString &address)
{
    QHostAddress addr(address);
    Ethernet::deleteFromAllowed(addr);
    Ethernet::deleteFromBlocked(addr);
}

void MousoidCore::create()
{
    instance = new MousoidCore();
    Ethernet::create();
}

void MousoidCore::destroy()
{
    Ethernet::destroy();
    delete instance;
}

void MousoidCore::changeName(QString &name)
{
    Ethernet::setName(name);
}

void MousoidCore::funcForNewClient(void (*callback)(char *,char *))
{
    Ethernet::self()->newClientCallback = callback;
}

void MousoidCore::changeLimitations(uchar limitations)
{
    Ethernet::setLimitations(limitations);
}

