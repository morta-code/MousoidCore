#ifndef COMMANDEMITTER_HPP
#define COMMANDEMITTER_HPP

#include <QObject>

class CommandEmitter : public QObject
{
    Q_OBJECT
public:
    explicit CommandEmitter(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // COMMANDEMITTER_HPP
