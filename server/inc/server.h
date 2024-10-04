#ifndef server_h
#define server_h

#include "listenSocket.h"
#include "threadpool.h"
#include <unistd.h>

class Server
{
    private:
    ListenSocket *socket;
    ThreadPool *pool;

    public:
    Server(int domain, int service, int protocol, int port, u_long interface, int m_backlog, int num_threads);
    virtual void accept_connection() = 0;
    virtual void handler(int client_con) = 0;
    virtual void responder() = 0;
    virtual void launch() = 0;

    ThreadPool *getPool();
    ListenSocket* getSocket();
};


#endif