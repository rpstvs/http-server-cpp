#include "socket.h"

Socket::Socket(int domain, int service, int protocol, int port, u_long interface)
{
    address.sin_family = domain;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = htonl(interface);
    socketfd = socket(domain, service, protocol);
    test_connection(socketfd);

    std::cout<< "Socket created: " << socketfd << std::endl;
   
}

void Socket::test_connection(int i)
{
    if (i < 0)
    {
        perror("Connection failed");
        exit(1);
    }
}

int Socket::get_connection()
{
    return connection;
}

int Socket::get_socketfd()
{
    return socketfd;
}

struct sockaddr_in Socket::get_address()
{
    return address;
}

void Socket::set_connection(int m_connection)
{
        connection = m_connection;
}