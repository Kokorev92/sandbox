#include <iostream>

using namespace std;

namespace my {
unsigned strlen(const char* str) {
    unsigned len = 0;
    while (str[++len] != '\0') {
    }
    return len;
}

void strcat(char* to, const char* from) {}
}  // namespace my

char str[] = "fuck off!";

int main() {
    cout << my::strlen(str) << endl;
    my::strcat(str, str);
    return 0;
}
