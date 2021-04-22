#include <ncurses.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <set>
#include <utility>
#include <vector>

static constexpr int points_count = 10;

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    std::srand(std::time(nullptr));

    std::set<std::pair<int, int>> points;

    int i = 0;
    while (i < points_count) {
        std::pair<int, int> p;
        p.first  = std::rand() % LINES;
        p.second = std::rand() % COLS;

        points.insert(p);
        i = points.size();
    }

    int x = 5;
    int y = 5;
    while (true) {
        if (!points.empty()) {
            std::set<std::pair<int, int>>::iterator iter = points.begin();
            while (iter != points.end()) {
                mvaddch(iter->first, iter->second, 'O');
                if ((iter->first == y) && (iter->second == x)) {
                    iter = points.erase(iter);
                    continue;
                }
                ++iter;
            }
        }

        mvprintw(y, x, "X");

        int ch = getch();
        switch (ch) {
            case KEY_UP:
                if ((y - 1) >= 0) {
                    y--;
                }
                break;
            case KEY_DOWN:
                if ((y + 1) < LINES) {
                    y++;
                }
                break;
            case KEY_LEFT:
                if ((x - 1) >= 0) {
                    x--;
                }
                break;
            case KEY_RIGHT:
                if ((x + 1) < COLS) {
                    x++;
                }
                break;
        }

        clear();
        refresh();
    }
    endwin();
    return 0;
}
