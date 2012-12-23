#ifndef MOUSOIDCORE_HPP
#define MOUSOIDCORE_HPP

#include "MousoidCore_global.hpp"
#include "mousoid_constants.hpp"
#include <QtCore>

class MOUSOIDCORESHARED_EXPORT MousoidCore
{
public:
    static void create();
    static void destroy();

    static void changeName(QString &name);
    static void funcForNewClient(void (* callback)(QString &n));

    static void changeLimitations(uchar limitations);
    static void changeServerState(uchar state);

private:
    MousoidCore();

    static MousoidCore *instance;
    uchar c;
};

#endif // MOUSOIDCORE_HPP
