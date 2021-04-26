#include <unistd.h>
#include <iostream>
#include <string>
#include <thread>
#include "ncurses.h"

WINDOW* win_one;
WINDOW* win_two;
void    thread_t(void* o) {
    (void)o;
    int a = 0;

    while (true) {
        a++;
        std::string str = std::to_string(a);
        wprintw(win_one, str.c_str());
        wrefresh(win_one);
        usleep(50000);
        wclear(win_one);
    }
}

int main() {
    initscr();
    refresh();
    win_one = newwin(5, 30, 0, 0);
    win_two = newwin(5, 30, 0, 31);

    wrefresh(win_two);
    std::thread thrd(thread_t, nullptr);
    thrd.detach();

    [[maybe_unused]] char* buf;
    mvwscanw(win_two, 0, 0, buf);
    delwin(win_one);
    delwin(win_two);
    endwin();
}