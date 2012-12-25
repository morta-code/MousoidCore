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

void (* newClientCallback)(char* str);

void executeCommand(QByteArray& command){
    NativeCommandEmitter e;
    char* _temp = 0;

    switch (command[1]) {
    case Mousoid::MOUSEMOVE:
        e.sendNativeMouseMotion(command[2], command[3]);
        return;

    case Mousoid::MOUSEBUTTON:
        if(command[2] == Mousoid::CLICK){
            e.sendNativeButton((Qt::MouseButton)(char)command[3], true);
            e.sendNativeButton((Qt::MouseButton)(char)command[3], false);
            return;
        }
        if (command[2] == Mousoid::PRESS) {
            e.sendNativeButton((Qt::MouseButton)(char)command[3], true);
            return;
        }
        if (command[2] == Mousoid::RELEASE) {
            e.sendNativeButton((Qt::MouseButton)(char)command[3], false);
            return;
        }

    case Mousoid::NAME:
        _temp = new char[command[2]+1];
        for(uchar i = 0; i < command[2]; ++i){
            _temp[i] = command[3+i];
        }
        _temp[command[2]] = 0;
        newClientCallback(_temp);
        delete _temp;
        return;

    default:
        return;
    }
}

}

#endif // COMMANDEMITTER_HPP
