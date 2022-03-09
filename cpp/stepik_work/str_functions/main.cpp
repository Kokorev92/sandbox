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

int strstr(const char* text, const char* pattern) {
    unsigned text_len    = strlen(text);
    unsigned pattern_len = strlen(pattern);

    if (text_len < pattern_len) {
        return -1;
    }
    if (text_len == 0 && pattern_len > 0) {
        return -1;
    }
    if (text_len == 0 && pattern_len == 0) {
        return 0;
    }
    if (text_len > 0 && pattern_len == 0) {
        return 0;
    }

    for (int i = 0; i < text_len; i++) {
    }
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
