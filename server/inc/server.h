#ifndef server_h
#define server_h

#include "listenSocket.h"
#include <unistd.h>

class Server
{
    private:
    ListenSocket *socket;
    public:
    Server(int domain, int service, int protocol, int port, u_long interface, int m_backlog);
    virtual void accept_connection() = 0;
    virtual void handler() = 0;
    virtual void responder() = 0;
    virtual void launch() = 0;

    ListenSocket* getSocket();
};


#endif