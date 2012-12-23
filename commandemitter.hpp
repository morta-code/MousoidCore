#pragma once

#include <QObject>
#include <Qt/qkeysequence.h>
#include <QDebug>

#ifdef Q_WS_X11
#include "commandemitter_x11.hpp"
#endif
#ifdef Q_WS_WIN
#include "commandemitter_win.hpp"
#endif

//class CommandEmitter : public QObject
//{
//    Q_OBJECT
//public:
//    inline static void create(QObject *parent = 0){
//        instance = new CommandEmitter(parent);
//    }

//    inline static CommandEmitter* self(){
//        return instance;
//    }

//    inline static void destroy(){
//        instance->deleteLater();
//    }
    

//    void (* forNewClient)(QString&);

//public slots:
//    void executeCommand(QByteArray& command);

//private:
//    explicit CommandEmitter(QObject *parent = 0) :QObject(parent){}

//    static CommandEmitter *instance;
//};


namespace NOOP_CommandEmitter {

void (* newClientCallback)(QString&);
void executeCommand(QByteArray& command){
    /// @todo parancsfeldolgozás
    // test mouse motion
    command.clear();
    NativeCommandEmitter e;
    e.sendNativeMouseMotion(10, 10);
}

}

