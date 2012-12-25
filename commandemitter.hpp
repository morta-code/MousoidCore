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

char* _temp = 0;
void (* newClientCallback)(char* str);
void executeCommand(QByteArray& command){
    /// @todo parancsfeldolgozás
    // test mouse motion

    NativeCommandEmitter e;

    switch (command[1]) {
    case Mousoid::MOUSEMOVE:
        e.sendNativeMouseMotion(command[2], command[3]);
        break;
    case Mousoid::NAME:
        _temp = new char[command[2]+1];
        for(uchar i = 0; i < command[2]; ++i){
            _temp[i] = command[3+i];
        }
        _temp[command[2]] = 0;
        newClientCallback(_temp);
        delete _temp;
        break;
    default:
        break;
    }
}

}

#endif // COMMANDEMITTER_HPP
