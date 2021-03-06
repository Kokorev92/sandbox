#include <math.h>
#include <ncurses.h>
#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <set>
#include <string>
#include <utility>
#include <vector>

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    int points_count = 0;
    int percent      = 1;

    if (argc > 1) {
        percent = atoi(argv[1]);
    }

    initscr();
    curs_set(0);
    noecho();
    keypad(stdscr, TRUE);
    std::srand(std::time(nullptr));

    std::set<std::pair<int, int>> points;

    points_count = round(((LINES - 3) * (COLS - 2) / 100)) * percent;

    int i = 0;
    while (i < points_count) {
        std::pair<int, int> p;
        p.first  = std::rand() % (LINES - 3) + 2;
        p.second = std::rand() % (COLS - 2) + 1;

        points.insert(p);
        i = points.size();
    }

    int x = 5;
    int y = 5;

    int score = 0;

    WINDOW* win = newwin(LINES - 1, COLS, 1, 0);

    bool game_is_running = true;
    while (game_is_running) {
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
        std::string score_str =
            std::string("Score: ") + std::to_string(score) +
            std::string(" Y: ") + std::to_string(y) + std::string(" X: ") +
            std::to_string(x) + std::string(" LINES: ") +
            std::to_string(LINES) + " COLS: " + std::to_string(COLS) +
            " TOTAL POINTS: " + std::to_string(points_count);

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
                game_is_running = false;
        }
        if (points.empty()) {
            int x_offset = (COLS - 20) / 2;
            int y_offset = (LINES - 6) / 2;

            WINDOW*     end_game_win = newwin(6, 20, y_offset, x_offset);
            std::string win_msg("You WIN!");
            mvaddstr(LINES / 2, ((COLS - win_msg.length()) / 2),
                     win_msg.c_str());
            box(end_game_win, 0, 0);
            wrefresh(end_game_win);
            refresh();
            delwin(end_game_win);
            getch();
            game_is_running = false;
        }
        clear();
        refresh();
    }
    delwin(win);
    endwin();
    return 0;
}
