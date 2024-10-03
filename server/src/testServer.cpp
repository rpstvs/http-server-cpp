
#include "testServer.h"

TestServer::TestServer() : Server(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10)

{
    launch();
}

void TestServer::accept_connection()
{
    struct sockaddr_in address = getSocket()->get_address();
    int addrlen = sizeof(address);
    int serverfd = getSocket()->get_socketfd();
    new_socket = accept(serverfd,
                        (struct sockaddr *)&address,
                        (socklen_t *)&addrlen);

    if (new_socket < 0)
    {

        perror("Failed Connect");
        exit(1);
    }

    read(new_socket, buffer, 1024);
}

void TestServer::handler()
{
    std::cout << buffer << std::endl;
}

void TestServer::responder()
{
    std::string htmlFile = "<!DOCTYPE html><html lang=\"en\"><body><h1> HOME </h1><p> Hello from your Server :) </p></body></html>";
    std::ostringstream ss;
    ss << "HTTP/1.1 200 OK\nContent-Type: text/html\nContent-Length: " << htmlFile.size() << "\n\n"
       << htmlFile;
    std::string response = ss.str();

    write(new_socket, response.c_str(), response.size());
    close(new_socket);
}

void TestServer::launch()
{
    while (true)
    {
        std::cout << "====== WAITING ======" << std::endl;
        accept_connection();
        handler();
        responder();
        std::cout << "======== DONE ======" << std::endl;
    }
}