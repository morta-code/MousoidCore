#ifndef MOUSOIDCORE_HPP
#define MOUSOIDCORE_HPP

#include "MousoidCore_global.hpp"
#include "mousoid_constants.hpp"
#include <QtCore>

class MOUSOIDCORESHARED_EXPORT MousoidCore
{
public:
    static void create();
    inline static MousoidCore* self() {return instance;}
    static void destroy();

    static void changeName(QString &name);
    static void funcForNewClient(void (* callback)(QString &n));


    void changeServerState(uchar state);
    void stopServer();

private:
    MousoidCore();

    static MousoidCore *instance;
    uchar c;
};

#endif // MOUSOIDCORE_HPP
