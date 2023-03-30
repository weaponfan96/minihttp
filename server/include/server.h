#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

class server{
public:
    server(u_short pt);
    void get();
    void post();
private:
    u_short port;
    int fd;
};