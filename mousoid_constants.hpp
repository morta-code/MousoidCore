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

    /// Command parts
    const char HEADER = 66;
    const char WHO_ARE_YOU = -128;
    const char NAME = 8;

    /// UDP port
    const ushort PORT = 10066;
}

#endif // MOUSOID_CONSTANTS_HPP
