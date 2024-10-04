#include "server.h"

Server::Server(int domain, int service, int protocol, int port, u_long interface, int m_backlog, int num_threads)
{
    socket = new ListenSocket( domain,  service,  protocol,  port,  interface,  m_backlog);
    pool = new ThreadPool(num_threads);
}

ListenSocket* Server::getSocket()
{
    return socket;
}

ThreadPool * Server::getPool()
{
    return pool;
}