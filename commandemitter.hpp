#ifndef COMMANDEMITTER_HPP
#define COMMANDEMITTER_HPP

#include <Qt/qkeysequence.h>
#include <QDebug>

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
    command.clear();
    NativeCommandEmitter e;
    e.sendNativeMouseMotion(10, 10);
}

}

#endif // COMMANDEMITTER_HPP
