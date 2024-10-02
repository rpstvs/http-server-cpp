
#include "listenSocket.h"

int main() 
{
    ListenSocket ls = ListenSocket(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10);
    std::cout << "success" << std::endl;
}