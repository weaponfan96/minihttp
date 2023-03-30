#include "server.h"
server::server(u_short pt){
    int on = 1;
    port = pt;
    fd = socket(PF_INET, SOCK_STREAM, 0);
    if(-1 == fd){
        printf("create socket failed in %s, line : %d\n", __FUNCTION__, __LINE__);
        exit(1);
    }
    sockaddr_in name;
    memset(&name, 0, sizeof(sockaddr_in));
    name.sin_family = AF_INET;
    name.sin_port = htons(port);
    name.sin_addr.s_addr = htonl(INADDR_ANY);
    if ((setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on))) < 0)  
    {  
        printf("setsockopt failed");
        exit(1);
    }
    int ret = bind(fd, (struct sockaddr *)&name, sizeof(sockaddr_in));
    if(-1 == ret){
        printf("bind port to fd failed in %s, line : %d\n", __FUNCTION__, __LINE__);
        exit(1);
    }
}