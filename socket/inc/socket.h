
#ifndef socket_h
#define socket_h

#include <sys/socket.h>
#include <netinet/in.h>
#include <iostream>

class Socket
{
    private:
    int connection;
    int socketfd;
    struct sockaddr_in address;

    public:
    Socket(int domain, int service, int protocol, int port, u_long interface);
    virtual int NetworkConnection(int socketfd, struct sockaddr_in address) =0;
    void test_connection(int i);

    int get_connection();
    int get_socketfd();
    struct sockaddr_in get_address();

    void set_connection(int m_connection);
};

#endif