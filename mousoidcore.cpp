#include "mousoidcore.hpp"
#include "ethernet.hpp"

MousoidCore* MousoidCore::instance = 0;

MousoidCore::MousoidCore()
{
    c = 0;
}

void MousoidCore::changeServerState(uchar state)
{
    c = state;
    if(c & Mousoid::SERVER_ENABLED){
        if(c & Mousoid::WIRELESS_ON)
            Ethernet::listen();
        else
            Ethernet::suspend();
        if(c & Mousoid::BLUETOOTH_ON) {}
            /// @todo Bluetooth::listen();
        else {}
            /// @todo Bluetooth::suspend();
        if(c & Mousoid::MORE_ALLOWED){
            Ethernet::setLimitations(Mousoid::NO_LIMITATION);
            /// @todo other limitations
        }else{
            Ethernet::setLimitations(Mousoid::ONLY_ONE_ALLOWED);
        }
    }else{
        Ethernet::suspend();
        /// @todo Bluetooth::suspend();
    }
}

void MousoidCore::stopServer()
{
    c &= ~Mousoid::SERVER_ENABLED;
    Ethernet::suspend();
    /// @todo Bluetooth::suspend();
}


void MousoidCore::create(QString &name)
{
    instance = new MousoidCore();
    Ethernet::create(name, 0, instance);
    /// @todo connect(Ethernet::self(), SIGNAL(commandArrived(QByteArray)),
    /// @todo Bluetooth::create
}

void MousoidCore::destroy()
{
    Ethernet::destroy();
    /// @todo Bluetooth::destroy
    instance->deleteLater();
}

