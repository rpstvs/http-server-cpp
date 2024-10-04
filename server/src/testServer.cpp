
#include "testServer.h"

TestServer::TestServer() : Server(AF_INET, SOCK_STREAM, 0, 8080, INADDR_ANY, 10,4)

{
    launch();
}

void TestServer::accept_connection()
{
    struct sockaddr_in address = getSocket()->get_address();
    int addrlen = sizeof(address);
    int serverfd = getSocket()->get_socketfd();

    int client_con = accept(serverfd, 
    (struct sockaddr *)&address,
    (socklen_t *)&addrlen);

    if (client_con < 0)
    {   
       
        perror("Failed Connect");
        exit(1);
    }
    
   getPool()->enqueue([this, client_con]
   {
        std::cout <<"Thread Serving the request: " <<  getPool()->get_thread_id().c_str() << std::endl;
        handler(client_con);
   });
}

void TestServer::handler(int client_con)
{
    int valread = read(client_con, buffer, 1024);

    if(valread < 0)
    {
        perror("failed to read from client");
        close(client_con);
        exit(1);
    }

    std::cout << buffer << std::endl;

    std::string response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nContent-Length: 20\r\n\r\n<h1>Hello</h1>";

    write(client_con, response.c_str(), response.size());

    close(client_con);
}

void TestServer::responder()
{
    std::string response = "<h1>hello</h1>";

    write(new_socket, response.c_str(), response.size());
    close(new_socket);
}

void TestServer::launch()
{
    while (true)
    {
       std::cout << "====== WAITING ======" << std::endl;
       accept_connection();
       std::cout << "======== DONE ======" << std::endl;
    }
    
}