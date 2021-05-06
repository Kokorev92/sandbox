#include <unistd.h>
#include <iostream>
#include <thread>

class Thredas_class {
public:
    Thredas_class() {}

    static void thread_1(void* o) {
        if (o == nullptr) {
            return;
        }
        Thredas_class* thr = static_cast<Thredas_class*>(o);
        thr->thread_internal_1();
    }

    static void thread_2(void* o) {
        if (o == nullptr) {
            return;
        }
        Thredas_class* thr = static_cast<Thredas_class*>(o);
        thr->thread_internal_2();
    }

private:
    void thread_internal_1() {
        while (true) {
            usleep(100000);
        }
    }
    void thread_internal_2() {
        while (true) {
            usleep(100000);
        }
    }
};

Thredas_class test_thr;

class Test {
public:
    Test() {}
    void run() {
        std::thread thr1(Thredas_class::thread_1, &test_thr);
        std::thread thr2(Thredas_class::thread_2, &test_thr);

        thr1.detach();
        thr2.detach();
    }
};

int main() {
    Test t;
    t.run();
}