#ifndef COMMANDEMITTER_HPP
#define COMMANDEMITTER_HPP

#include <Qt/qkeysequence.h>
#include <QDebug>
#include "mousoid_constants.hpp"

#ifdef Q_WS_X11
#include "commandemitter_x11.hpp"
#endif
#ifdef Q_WS_WIN
#include "commandemitter_win.hpp"
#endif

namespace CommandEmitter {

void (* newClientCallback)(QString&);
void executeCommand(QByteArray& command){
    /// @todo parancsfeldolgozás
    // test mouse motion

    NativeCommandEmitter e;

    switch (command[1]) {
    case Mousoid::MOUSEMOVE:
        e.sendNativeMouseMotion(command[2], command[3]);
        break;
    case Mousoid::NAME:

        break;
    case Mousoid::MOUSEBUTTON:

        break;
    default:
        break;
    }
}

}

#endif // COMMANDEMITTER_HPP
