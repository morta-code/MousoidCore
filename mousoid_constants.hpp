#ifndef MOUSOID_CONSTANTS_HPP
#define MOUSOID_CONSTANTS_HPP

typedef unsigned char uchar;
typedef unsigned short ushort;

/**
 * Namespace for Mousoid constants.
 * All states of server application can be described with an unsigned char variable:
 * +----------------+-+-+-+-+--------------+--------------+-------------+
 * | SERVER_ENABLED |-|-|-|-| MORE_ALLOWED | BLUETOOTH_ON | WIRELESS_ON |
 * +----------------+-+-+-+-+--------------+--------------+-------------+
 *
 * The limitations of accepting UDP datagrams can be:
 * +-+-+-+-+-+------------------+-----------------------+-----------------------+
 * |-|-|-|-|-| ONLY_ONE_ALLOWED | ONLY_FROM_SET_ALLOWED | ONLY_FROM_SET_BLOCKED |
 * +-+-+-+-+-+------------------+-----------------------+-----------------------+
 *
 * @author Móréh Tamás 2012.
 */
namespace Mousoid {

    /// Server states
    const uchar WIRELESS_ON = 0x1;
    const uchar BLUETOOTH_ON = 0x2;
    const uchar MORE_ALLOWED = 0x4;
    const uchar SERVER_ENABLED = 0x80;

    /// Datagram limitations
    const uchar ONLY_ONE_ALLOWED = 0x4;
    const uchar ONLY_FROM_SET_ALLOWED = 0x2;
    const uchar ONLY_FROM_SET_BLOCKED = 0x1;
    const uchar NO_LIMITATION = 0x0;

    /// UDP port
    const ushort PORT = 10066;

    /// Command header parts
    const char HEADER = 66;

    const char WHO_ARE_YOU = -128;
    const char KEYCOMMAND = 1;
    const char KEYPRESS = 2;
    const char KEYRELEASE = 3;
    const char MOUSEMOVE = 4;
    const char MOUSEBUTTON = 5;
    const char NAME = 8;


    /// Command value parts
    /// Keycodes
    const char KEY_UP = 0;
    const char KEY_DOWN = 1;
    const char KEY_LEFT = 2;
    const char KEY_RIGHT = 3;
    const char KEY_PGUP = 4;
    const char KEY_PGDN = 5;
    const char KEY_SPACE = 6;
    const char KEY_ESC = 7;
    const char KEY_ALT = 8;
    const char KEY_ALTGR = 9;
    const char KEY_CTRL = 10;
    const char KEY_SUPER = 11;
    const char KEY_SHIFT = 12;
    const char KEY_ENTER = 13;
    const char KEY_INSERT = 14;
    const char KEY_DELETE = 15;
    const char KEY_HOME = 16;
    const char KEY_END = 17;
    const char KEY_TAB = 18;
    const char KEY_F1 = 19;
    const char KEY_F2 = 20;
    const char KEY_F3 = 21;
    const char KEY_F4 = 22;
    const char KEY_F5 = 23;
    const char KEY_F6 = 24;
    const char KEY_F7 = 25;
    const char KEY_F8 = 26;
    const char KEY_F9 = 27;
    const char KEY_F10 = 28;
    const char KEY_F11 = 29;
    const char KEY_F12 = 30;
    const char KEY_BACKSPACE = 31;
    const char KEY_A = -1;
    const char KEY_B = -2;
    const char KEY_C = -3;
    const char KEY_D = -4;
    const char KEY_E = -5;
    const char KEY_F = -6;
    const char KEY_G = -7;
    const char KEY_H = -8;
    const char KEY_I = -9;
    const char KEY_J = -10;
    const char KEY_K = -11;
    const char KEY_L = -12;
    const char KEY_M = -13;
    const char KEY_N = -14;
    const char KEY_O = -15;
    const char KEY_P = -16;
    const char KEY_Q = -17;
    const char KEY_R = -18;
    const char KEY_S = -19;
    const char KEY_T = -20;
    const char KEY_U = -21;
    const char KEY_V = -22;
    const char KEY_W = -23;
    const char KEY_X = -24;
    const char KEY_Y = -25;
    const char KEY_Z = -26;
    const char KEY_DOT = -27;
    const char KEY_COMMA = -28;
    const char KEY_SEMICOLON = -29;
    const char KEY_COLON = -30;
    const char KEY_DASH = -31;
    const char KEY_SLASH = -32;

    /// Mouse codes
    const char CLICK = -1;
    const char PRESS = -2;
    const char RELEASE = -3;
    const char DOUBLE_CLICK = -4;
    const char SCROLL_VERTICAL = -5;
    const char SCROLL_HORIZONTAL = -6;

    const char MOUSE_LEFT = 0;
    const char MOUSE_MIDDLE = 1;
    const char MOUSE_RIGHT = 2;
}

#endif // MOUSOID_CONSTANTS_HPP
