#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <cstring>
#include <iostream>

static constexpr int PORT = 5500;

char buff[255];

int main(int argc, char** argv) {
    (void)argc;
    (void)argv;

    int sock = socket(AF_INET, SOCK_DGRAM, 0);

    struct sockaddr_in addr;
    addr.sin_family      = AF_INET;
    addr.sin_port        = htons(PORT);
    addr.sin_addr.s_addr = INADDR_ANY;

    struct sockaddr_in in_addr;

    bind(sock, (struct sockaddr*)&addr, sizeof(addr));

    socklen_t addr_len = sizeof(in_addr);
    while (true) {
        int len = recvfrom(sock, buff, sizeof(buff), 0,
                           (struct sockaddr*)&in_addr, &addr_len);
        if (len > 0) {
            char resp[2] = {buff[0], buff[1]};
            if ((resp[0] == 82 && (resp[1] == 81))) {
                resp[1] -= 1;

                // TODO: из релиза убрать. Другой порт нужен для
                // отладки на одной машине с использованием netcat
                // или socat. Отправка должна идти тому, кто прислал
                // корректный запрос
                in_addr.sin_port = htons(5501);
                sendto(sock, resp, sizeof(resp), 0, (struct sockaddr*)&in_addr,
                       addr_len);
            }
            std::cout << inet_ntoa(in_addr.sin_addr) << std::endl;
        } else {
            continue;
        }
    }
}