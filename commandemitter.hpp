#ifndef COMMANDEMITTER_HPP
#define COMMANDEMITTER_HPP

#include <QObject>
#include <Qt/qkeysequence.h>
#include <QDebug>

#ifdef Q_WS_X11
#include "commandemitter_x11.hpp"
#endif
#ifdef Q_WS_WIN
#include "commandemitter_win.hpp"
#endif

class CommandEmitter : public QObject
{
    Q_OBJECT
public:
    explicit CommandEmitter(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // COMMANDEMITTER_HPP
