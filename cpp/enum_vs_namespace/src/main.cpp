#include <iostream>

enum class MSG_CLASSES { NAV = 0x01, CFG = 0x06, MON = 0x07 };

namespace MSG_CLASS {
enum { NAV = 0x01, CFG = 0x06, MON = 0x07 };
}

uint8_t msg_class = 0x06;

int main(int argc, char** argv) {
    switch (static_cast<MSG_CLASSES>(msg_class)) {
        case MSG_CLASSES::CFG:
            std::cout << "Enum class: config message" << std::endl;
            break;
    }

    switch (msg_class) {
        case MSG_CLASS::CFG:
            std::cout << "Enum in namespace: config message" << std::endl;
            break;
    }

    return 0;
}