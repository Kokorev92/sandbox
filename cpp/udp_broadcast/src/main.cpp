#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in in_addr;
    struct sockaddr_in addr;

    addr.sin_family = AF_INET;
    addr.sin_port   = htons(5500);
    auto ip         = gethostbyname("192.168.111.255");

    socklen_t addr_len  = sizeof(in_addr);
    int       broadcast = 1;
    setsockopt(sock, SOL_SOCKET, SO_BROADCAST, &broadcast, sizeof broadcast);

    memcpy(&addr.sin_addr, ip->h_addr_list[0], sizeof(addr.sin_addr));

    char buff[255];
    while (true) {
        memset(buff, 0, 255);
        sendto(sock, "RQ\n", sizeof("RQ\n"), 0, (struct sockaddr*)&addr,
               sizeof(addr));
        int len =
            recvfrom(sock, buff, 255, 0, (struct sockaddr*)&in_addr, &addr_len);
        if (len > 0) {
            std::cout << buff << std::endl;
        }
        sleep(1);
    }

    return 0;
}