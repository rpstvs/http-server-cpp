#include "socket.h"

Socket::Socket(int domain, int service, int protocol)
{
    int socketfd = socket(domain, service, protocol);
    
}