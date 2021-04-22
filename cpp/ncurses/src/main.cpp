#include <ncurses.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <set>
#include <string>
#include <utility>
#include <vector>

static constexpr int points_count = 50;

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
        p.first  = 2 + std::rand() % (LINES - 2);
        p.second = 1 + std::rand() % (COLS - 1);

        points.insert(p);
        i = points.size();
    }

    int x = 5;
    int y = 5;

    int score = 0;

    WINDOW* win = newwin(LINES - 1, COLS, 1, 0);

    while (true) {
        if (!points.empty()) {
            std::set<std::pair<int, int>>::iterator iter = points.begin();
            while (iter != points.end()) {
                mvaddch(iter->first, iter->second, 'O');
                if ((iter->first == y) && (iter->second == x)) {
                    iter = points.erase(iter);
                    score++;
                    continue;
                }
                ++iter;
            }
        }

        std::string score_str = std::string("Score: ") + std::to_string(score);

        mvaddstr(0, 0, score_str.c_str());
        mvprintw(y, x, "X");
        box(win, 0, 0);
        wrefresh(win);
        int ch = getch();
        switch (ch) {
            case KEY_UP:
                if ((y - 1) >= 2) {
                    y--;
                }
                break;
            case KEY_DOWN:
                if ((y + 1) < LINES - 1) {
                    y++;
                }
                break;
            case KEY_LEFT:
                if ((x - 1) >= 1) {
                    x--;
                }
                break;
            case KEY_RIGHT:
                if ((x + 1) < COLS - 1) {
                    x++;
                }
                break;
            case 'q':
                exit(0);
        }
        clear();
        refresh();
    }
    delwin(win);
    endwin();
    return 0;
}
