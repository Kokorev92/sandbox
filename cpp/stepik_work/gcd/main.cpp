#include <iostream>

using namespace std;

/*
 * @brief Функция нахождения НОД по алгоритму Евклида
 */
unsigned gcd(unsigned a, unsigned b) {
    if (a == b) {
        return a;
    }
    if ((a != 0) && (b != 0)) {
        if (a > b) {
            a = a % b;
        } else if (a < b) {
            b = b % a;
        }
        return gcd(a, b);
    }

    return a + b;
}

int main() {
    auto nod = gcd(64, 48);
    cout << nod << endl;
    return 0;
}
