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
    static void create(QObject *parent = 0);
    static CommandEmitter* self() {return instance;}
    static void destroy();
    
signals:
    
public slots:
    void executeCommand(QByteArray& command);

private:
    explicit CommandEmitter(QObject *parent = 0);

    CommandEmitter *instance;
    
};

#endif // COMMANDEMITTER_HPP
