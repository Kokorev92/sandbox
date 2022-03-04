#include <iostream>

using namespace std;

namespace my {
unsigned strlen(const char* str) {
    unsigned len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

void strcat(char* to, const char* from) {
    unsigned len = strlen(to);
    for (unsigned i = 0; i < strlen(from); ++i) {
        to[len + i] = from[i];
    }
    to[len + strlen(from)] = '\0';
}
}  // namespace my

char str[15] = "fuck off!";
char str2[]  = " bitch";

int main() {
    cout << my::strlen(str) << endl;
    my::strcat(str, str2);

    for (int i = 0; i < my::strlen(str); ++i) {
        cout << str[i];
    }
    return 0;
}
