
#ifndef socket_h
#define socket_h

#include <sys/socket.h>
#include <netinet/in.h>

class Socket
{
    private:
    int socketfd;
    public:
    Socket(int domain, int service, int protocol);
};

#endif