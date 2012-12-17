#ifndef COMMANDEMITTER_X11_HPP
#define COMMANDEMITTER_X11_HPP

#include <QObject>
#include <X11/keysym.h>
#include <X11/XF86keysym.h>
#include <X11/keysymdef.h>
#include <X11/Xmd.h>
#include <X11/extensions/XTest.h>

class NativeCommandEmitter : public QObject
{
    Q_OBJECT
public:
    explicit NativeCommandEmitter(QObject *parent = 0);
    ~NativeCommandEmitter();
    void sendNativeKey(Qt::Key key, bool down);
    void sendNativeKeyModifiers(Qt::KeyboardModifiers modifiers, bool down);
    void sendNativeButton(Qt::MouseButton button, bool down);
    void sendNativeScroll(int direction, int delta, double acceleration);

private:
    Display* display;

    quint32 nativeKeycode(Qt::Key key) const;

signals:

public slots:

};

#endif // COMMANDEMITTER_X11_HPP
