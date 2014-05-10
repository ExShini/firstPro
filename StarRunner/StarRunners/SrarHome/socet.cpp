#include "socet.h"
#include "iostream"

using namespace std;

/*************************************
FUNC: InitializeSockets()
DESC: initialize socet mechanism for current os
*************************************/
bool Socet::InitializeSockets()
{
#if PLATFORM == PLATFORM_WINDOWS
    WSADATA WsaData;
    return WSAStartup( MAKEWORD(2,2), &WsaData ) == NO_ERROR;
#else
    return true;
#endif
}

/*************************************
FUNC: ShutdownSockets()
DESC: Shutdown socet mechanism for current os
*************************************/
void Socet::ShutdownSockets()
{
#if PLATFORM == PLATFORM_WINDOWS
    WSACleanup();
#endif
}


/*************************************
FUNC: Socet(int port)
DESC: constructor
*************************************/
Socet::Socet(unsigned short port):
    m_handle(0),
    m_isReady(false)
{
    if (port < 1025)
    {
        cout << "Bad socet port. You must use number of port more then 1024!"<< endl;
        return;
    }

    m_handle = socket( AF_INET, SOCK_DGRAM, IPPROTO_UDP );

    if ( m_handle <= 0 )
    {
        cout << "failed to create socket\n" << endl;
        return;
    }

    //set port to socet

    m_address.sin_family = AF_INET;
    m_address.sin_addr.s_addr = INADDR_ANY;
    m_address.sin_port = htons( port );

    if ( bind( m_handle, (const sockaddr*) &m_address, sizeof(sockaddr_in) ) < 0 )
    {
        cout << "failed to bind socket\n" << endl;
        return;
    }

    //set non-blocking mode
    if(!SetNonblocking())
        return;


    //now socet is ready
    m_isReady = true;
}


/*************************************
FUNC: SetNonblocking()
DESC: set non-blocking mode for current socet
*************************************/
bool Socet::SetNonblocking()
{
#if PLATFORM == PLATFORM_MAC || PLATFORM == PLATFORM_UNIX

    int nonBlocking = 1;
    if ( fcntl( m_handle, F_SETFL, O_NONBLOCK, nonBlocking ) == -1 )
    {
        cout << "failed to set non-blocking socket\n" << endl;
        return false;
    }

#elif PLATFORM == PLATFORM_WINDOWS

    DWORD nonBlocking = 1;
    if ( ioctlsocket( m_handle, FIONBIO, &nonBlocking ) != 0 )
    {
        cout << "failed to set non-blocking socket\n" << endl;
        return false;
    }

#endif
    return true;
}

/*************************************
FUNC: SendMessage()
DESC: send message to target address
WARNING! At the end of function socet destroy input message
*************************************/
bool Socet::SendMessage(Message *message)
{
    int sent_bytes = sendto( handle, (const char*)message->data, message->size,
                             0, (sockaddr*)&m_address, sizeof(sockaddr_in) );

    if ( sent_bytes != message->size )
    {
        cout << "Failed to send packet: return value = " << sent_bytes << endl;
        return false;
    }

    //free memory after sending
    delete message;
    return true;
}
