
#ifndef listenSocket_h
#define listenSocket_h

#include "bindingSocket.h"

class ListenSocket : public BindingSocket
{
    private: 
    int backlog;
    int listening;
    public:
    ListenSocket(int domain, int service, int protocol, int port, u_long interface, int m_backlog);

    void StartListening();

};

#endif