

#include "listenSocket.h"

ListenSocket::ListenSocket(int domain, int service, int protocol, int port, u_long interface, int m_backlog): BindingSocket( domain,  service,  protocol,  port,  interface)
{
    backlog = m_backlog;
    StartListening();
    test_connection(listening);
    std::cout << "Listening with success" << std::endl;
}

void ListenSocket::StartListening()
{
    listening = listen(get_socketfd(), backlog);
}