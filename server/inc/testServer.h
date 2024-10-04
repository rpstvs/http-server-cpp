

#include "server.h"
#include <stdio.h>

class TestServer : public Server
{
    private:
    char buffer[1024] = {0};
    int new_socket;
    public:
        TestServer();
        void launch();
    void accept_connection();
    void handler(int client_con);
    void responder();
};