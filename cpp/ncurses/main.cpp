#include <ncurses.h>
#include <stdio.h>


static constexpr int width = 50;
static constexpr int height = 50;

int main(int argc, char** argv){
    
    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);

    int x = 5;
    int y = 5;

    while(true) {
        mvprintw(y, x, "X");

        int ch = getch();
        switch(ch) {
            case KEY_UP:
                y -= 5;
                break;
            case KEY_DOWN:
                y += 5;
                break;
            case KEY_LEFT:
                x -= 5;
                break;
            case KEY_RIGHT:
                x += 5;
                break;
        }
        clear();
        refresh();
    }
    endwin();
    return 0;
}
