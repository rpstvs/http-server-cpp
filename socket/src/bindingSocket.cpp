
#include "bindingSocket.h"

BindingSocket::BindingSocket(int domain, int service, int protocol,int port, u_long interface) : Socket(domain, service, protocol, port, interface)
{
   
   set_connection(NetworkConnection(get_socketfd(), get_address()));
   test_connection(get_connection());
   std::cout << "Binding with success" << get_connection() << std::endl;
}

int BindingSocket::NetworkConnection(int socketfd,struct sockaddr_in address)
{
  return bind(socketfd, (struct sockaddr*)&address, sizeof(address));
}