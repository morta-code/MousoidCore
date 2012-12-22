#ifndef BLUETOOTH_HPP
#define BLUETOOTH_HPP

#include <QObject>

#ifdef Q_OS_LINUX
#include <bluedevil/bluedevil.h>
#include <bluedevil/bluedevilmanager.h>
#include <bluedevil/bluedeviladapter.h>
#include <bluedevil/bluedevildevice.h>
#include <bluedevil/bluedevilutils.h>
#endif


class Bluetooth : public QObject
{
    Q_OBJECT
public:
    explicit Bluetooth(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // BLUETOOTH_HPP
