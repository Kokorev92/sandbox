#include <iostream>

using namespace std;

unsigned strlen(const char* str) {
    unsigned len = 0;
    while (str[len] != '\0') {
        len++;
    }
    return len;
}

char str[] = "fuck off!";

int main() {
    cout << strlen(str);
    return 0;
}
