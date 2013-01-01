#include "mousoidcore.hpp"
#include "ethernet.hpp"
#include "commandemitter.hpp"

MousoidCore* MousoidCore::instance = 0;

MousoidCore::MousoidCore()
{
    c = 0;
}

void MousoidCore::changeServerState(uchar state)
{
    instance->c = state;
    if(state & Mousoid::SERVER_ENABLED){
        if(state & Mousoid::WIRELESS_ON)
            Ethernet::listen();
        else
            Ethernet::suspend();
        if(state & Mousoid::BLUETOOTH_ON) {}
            /// @todo Bluetooth::listen();
        else {}
            /// @todo Bluetooth::suspend();
        if(state & Mousoid::MORE_ALLOWED){
            Ethernet::setLimitations(Mousoid::NO_LIMITATION);
            /// @todo other limitations
        }else{
            Ethernet::setLimitations(Mousoid::ONLY_ONE_ALLOWED);
        }
    }else{
        Ethernet::suspend();
        /// @todo Bluetooth::suspend();
    }
    qDebug() << "MousoidCore changed";
}

void MousoidCore::create()
{
    instance = new MousoidCore();
    Ethernet::create();
    /// @todo Bluetooth::create
    Ethernet::setCommandExecuterFunc(CommandEmitter::executeCommand);
    qDebug() << "MousoidCore ok";
}

void MousoidCore::destroy()
{
    Ethernet::destroy();
    /// @todo Bluetooth::destroy
    delete instance;
}

void MousoidCore::changeName(QString &name)
{
    Ethernet::setName(name);
}

void MousoidCore::funcForNewClient(void (*callback)(char *))
{
    Ethernet::self()->newClientCallback = callback;
}

void MousoidCore::changeLimitations(uchar limitations)
{
    Ethernet::setLimitations(limitations);
}

