#include "commandemitter.hpp"

CommandEmitter* CommandEmitter::instance = 0;

CommandEmitter::CommandEmitter(QObject *parent) :
    QObject(parent)
{
}

CommandEmitter* CommandEmitter::self()
{
    return instance;
}

void CommandEmitter::executeCommand(QByteArray &command)
{

}


void CommandEmitter::create(QObject *parent)
{
    instance = new CommandEmitter(parent);
}

void CommandEmitter::destroy()
{
    instance->deleteLater();
}
