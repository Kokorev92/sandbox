#include <iostream>
#include <vector>
#include <thread>
#include <unistd.h>
#include <signal.h>

void thread_func(int num);

auto f_signal = [](int signum) {
    exit(signum);
};

int main(int argc, char** argv){

    int count_threads = 0;

    std::cout << "Input number of threads: ";
    std::cin >> count_threads;

    std::vector<std::thread> threads;
    for(int i = 0; i < count_threads; i++) {
        threads.push_back(std::thread(thread_func, i));
        threads[i].detach();
    }
    signal(SIGINT, f_signal);
    while(true){
    sleep(0.1);
    }
    return 0;
}

void thread_func(int num) {

    while(true){
        std::cout << num << std::endl;
        sleep(0.5);
    }
}
