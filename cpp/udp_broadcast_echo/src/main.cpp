#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <string>

const std::string request = std::string("where_you\n");

char buff[255];

std::string str;

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addr;
    addr.sin_family      = AF_INET;
    addr.sin_port        = htons(5500);
    addr.sin_addr.s_addr = INADDR_ANY;

    struct sockaddr_in in_addr;

    bind(sock, (struct sockaddr*)&addr, sizeof(addr));

    socklen_t addr_len = sizeof(in_addr);

    while (true) {
        int len =
            recvfrom(sock, buff, 255, 0, (struct sockaddr*)&in_addr, &addr_len);
        if (len > 0) {
            str = std::string(buff);
            if (str == request) {
                std::string response = std::string("I am here\n");
                in_addr.sin_port     = htons(5501);
                sendto(sock, response.c_str(), response.length(), 0,
                       (struct sockaddr*)&in_addr, addr_len);
            }
            std::cout << str << std::endl;
            std::cout << inet_ntoa(in_addr.sin_addr) << std::endl;
            memset(buff, 0, 255);
        }
    }
}