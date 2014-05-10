#ifndef SOCET_H
#define SOCET_H

// platform detection
#define PLATFORM_WINDOWS  1
#define PLATFORM_MAC      2
#define PLATFORM_UNIX     3

#if defined(_WIN32) or defined(_WIN64)
#define PLATFORM PLATFORM_WINDOWS
#elif defined(__APPLE__)
#define PLATFORM PLATFORM_MAC
#else
#define PLATFORM PLATFORM_UNIX
#endif

//includes
#if PLATFORM == PLATFORM_WINDOWS

#include <winsock2.h>

#elif PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX

#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

#endif

//connect lib for windows version
#if PLATFORM == PLATFORM_WINDOWS
#pragma comment( lib, "wsock32.lib" )
#endif

/*******************************************************************************/
//Socet body

#include "message.h"

class Socet
{
public:
    Socet(unsigned short port);

    static void ShutdownSockets();
    static bool InitializeSockets();

    bool SendMessage(Message* message);

protected:
    bool SetNonblocking();


    int m_handle;
    bool m_isReady;
    sockaddr_in m_address;
};

#endif // SOCET_H
