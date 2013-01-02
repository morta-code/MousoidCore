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
    static void funcForNewClient(void (* callback)(char* str, char* addr));

    static void changeLimitations(uchar limitations);
    static void changeServerState(uchar state);

    static void addToBlocked(QString &address);
    static void addToAllowed(QString &address);
    static void setOneAllowed(QString &address);
    static void removeFromSets(QString &address);
private:
    MousoidCore() {}

    static MousoidCore *instance;
    uchar c;
};

#endif // MOUSOIDCORE_HPP
