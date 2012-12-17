#ifndef MOUSOIDCORE_HPP
#define MOUSOIDCORE_HPP

#include "MousoidCore_global.hpp"
#include "mousoid_constants.hpp"
#include <QtCore>

class MOUSOIDCORESHARED_EXPORT MousoidCore : public QObject
{
public:
    static void create(QString &name);
    inline static MousoidCore* self() {return instance;}
    static void destroy();

signals:
    void clientConnected(QString &name);

public slots:
    void changeServerState(uchar state);
    void stopServer();

private:
    MousoidCore();

    static MousoidCore *instance;
    uchar c;
};

#endif // MOUSOIDCORE_HPP
