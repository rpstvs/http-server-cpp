#include "server.h"

Server::Server(int domain, int service, int protocol, int port, u_long interface, int m_backlog)
{
    socket = new ListenSocket( domain,  service,  protocol,  port,  interface,  m_backlog);
}

ListenSocket* Server::getSocket()
{
    return socket;
}