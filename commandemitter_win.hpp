#ifndef COMMANDEMITTER_WIN_HPP
#define COMMANDEMITTER_WIN_HPP

#include <Qt>
#define WINVER 0x0601
#include <Windows.h>
class NativeCommandEmitter
{
public:
    explicit NativeCommandEmitter(){}
    ~NativeCommandEmitter(){}
    void sendNativeKey(Qt::Key key, bool down);
    void sendNativeKeyModifiers(Qt::KeyboardModifiers modifiers, bool down);
    void sendNativeButton(Qt::MouseButton button, bool down);
    void sendNativeScroll(int direction, int delta, double acceleration);
    void sendNativeMouseMotion(int x, int y);

private:
    quint32 nativeKeycode(Qt::Key key) const;

};

#endif // COMMANDEMITTER_WIN_HPP
