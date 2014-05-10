#include "server.h"

Server::Server()
{
    Socet::InitializeSockets();
}

Server::~Server()
{
    Socet::ShutdownSockets();
}

void Server::initServer()
{

}
