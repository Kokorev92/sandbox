#include <ncurses.h>
#include <stdio.h>
#include <utility>
#include <vector>

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    std::vector<std::pair<int, int>> points;
    points.push_back(std::pair(14, 56));
    points.push_back(std::pair(22, 12));

    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);

    int x = 5;
    int y = 5;
    while (true) {
        if (!points.empty()) {
            std::vector<std::pair<int, int>>::iterator iter = points.begin();
            while (iter != points.end()) {
                mvaddch(iter->first, iter->second, 'O');
                if ((iter->first == y) && (iter->second == x)) {
                    points.erase(iter);
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
