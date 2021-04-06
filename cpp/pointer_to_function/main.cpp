#include <iostream>

static void thread(void* obj) {}

using func = void (*)(void*);

func test() {
    return &thread;
}

int main(int argc, char** argv) {
    auto f = test();
    f(argv);
    return 0;
}