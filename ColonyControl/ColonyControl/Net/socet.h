#ifndef SOCET_H
#define SOCET_H


#if defined(_WIN32) or defined(_WIN64)
#include <winsock2.h>
//connect lib for windows version
#pragma comment( lib, "wsock32.lib" )
#else
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#endif


#include "message.h"



/*******************************************************************************/
//Socet body



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
