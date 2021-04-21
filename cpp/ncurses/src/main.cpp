#include <ncurses.h>
#include <stdio.h>

static constexpr int width  = 50;
static constexpr int height = 50;

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);

    int x = 5;
    int y = 5;

    int l = LINES;
    int c = COLS;

    while (true) {
        mvprintw(y, x, "X");

        int ch = getch();
        switch (ch) {
            case KEY_UP:
                if ((y - 1) >= 0) {
                    y--;
                }
                break;
            case KEY_DOWN:
                if ((y + 1) < l) {
                    y++;
                }
                break;
            case KEY_LEFT:
                if ((x - 1) >= 0) {
                    x--;
                }
                break;
            case KEY_RIGHT:
                if ((x + 1) < c) {
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
