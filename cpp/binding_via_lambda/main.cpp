#include <functional>
#include <iostream>
#include <utility>

using namespace std;

class A {
public:
    A() {}

    float get_temp() {
        return temp_;
    }

private:
    float temp_ = 0.10;
};

class B {
public:
    template <typename T>
    B(const T& func) : func_(func) {}

    void print() {
        cout << func_();
    }

private:
    std::function<float()> func_;
};

int main() {
    A a;

    B b([&a]() -> float { return a.get_temp(); });

    b.print();

    return 0;
}