#ifndef COMMANDEMITTER_HPP
#define COMMANDEMITTER_HPP

#include <Qt/qkeysequence.h>
#include <QString>

#include "mousoid_constants.hpp"

#ifdef Q_WS_X11
#include "commandemitter_x11.hpp"
#include <chrono>
#include <thread>
#define M_SLEEP(_T) std::this_thread::sleep_for( std::chrono::milliseconds(_T) )
#endif
#ifdef Q_WS_WIN
#include "commandemitter_win.hpp"
#include <Windows.h>
#define M_SLEEP(_T) Sleep(_T)
#endif

namespace CommandEmitter {
#ifdef Q_OS_WIN
#undef DOUBLE_CLICK
#endif
void executeCommand(QByteArray& command){
    NativeCommandEmitter e;

    switch (command[1]) {
    case Mousoid::MOUSEMOVE:
        e.sendNativeMouseMotion(command[2], command[3]);
        return;

    case Mousoid::MOUSEBUTTON:
        if(command[2] == Mousoid::CLICK){
            e.sendNativeButton((Qt::MouseButton)(char)command[3], true);
            M_SLEEP(60);
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
        if (command[2] == Mousoid::DOUBLE_CLICK) {
            e.sendNativeButton((Qt::MouseButton)(char)command[3], true);
            M_SLEEP(60);
            e.sendNativeButton((Qt::MouseButton)(char)command[3], false);
            M_SLEEP(70);
            e.sendNativeButton((Qt::MouseButton)(char)command[3], true);
            M_SLEEP(60);
            e.sendNativeButton((Qt::MouseButton)(char)command[3], false);
            return;
        }
        if (command[2] == Mousoid::SCROLL_VERTICAL) {
            e.sendNativeScroll(0, command[3], 1.0);
            return;
        }

    case Mousoid::KEYCOMMAND:
    {
        char mod_num = command[2];
        char char_num = command[3];
        for(register char i = 0; i < mod_num; ++i){
            int v;
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
            char c[] = {command[7+i*4], command[6+i*4], command[5+i*4], command[4+i*4]};
#else
            char c[] = {command[4+i*4], command[5+i*4], command[6+i*4], command[7+i*4]};
#endif
            memcpy(&v, c, 4);
            e.sendNativeKey((Qt::Key)v, true);
        }
        for(register char i = 0; i < char_num; ++i){
            short v;
            short _in = 4+(mod_num*4);
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
            char c[] = {command[_in+1+i*2], command[_in+i*2]};
#else
            char c[] = {command[_in+i*2], command[_in+1+i*2]};
#endif
            memcpy(&v, c, 2);
            e.sendNativeKey((Qt::Key)v, true);
        }
        for(register char i = 0; i < mod_num; ++i){
            int v;
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
            char c[] = {command[7+i*4], command[6+i*4], command[5+i*4], command[4+i*4]};
#else
            char c[] = {command[4+i*4], command[5+i*4], command[6+i*4], command[7+i*4]};
#endif
            memcpy(&v, c, 4);
            e.sendNativeKey((Qt::Key)v, false);
        }
        for(register char i = 0; i < char_num; ++i){
            short v;
            short _in = 4+(mod_num*4);
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
            char c[] = {command[_in+1+i*2], command[_in+i*2]};
#else
            char c[] = {command[_in+i*2], command[_in+1+i*2]};
#endif
            memcpy(&v, c, 2);
            e.sendNativeKey((Qt::Key)v, false);
        }
        return;
    }

#ifdef Q_OS_LINUX
    case Mousoid::SYSTEM:
    {
        char* _temp = new char[command[2]+3];
        for(register uchar i = 0; i < command[2]; ++i){
            _temp[i] = command[3+i];
        }
        _temp[command[2]] = ' ';
        _temp[command[2] + 1] = '&';
        _temp[command[2] + 2] = 0;
        system(_temp);
        delete _temp;
        return;
    }
#endif

    default:
        return;
    }
}

}
#ifdef Q_OS_WIN
#define DOUBLE_CLICK  0x0002
#endif
#endif // COMMANDEMITTER_HPP
