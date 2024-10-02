

#ifndef bindingSocket_h
#define bindingSocket_h

#include "socket.h"

class BindingSocket : public Socket
{
    public:
    BindingSocket(int domain, int service, int protocol, int port, u_long interface);
    int NetworkConnection(int socketfd, struct sockaddr_in address);
};


#endif