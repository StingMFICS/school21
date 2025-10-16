#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>

#define W 80
#define H 25
#define STEP 50
#define MIN_DELAY 50
#define MAX_DELAY 500

void view(int f[H][W], int f_nxt[H][W]);
void input_from_file(int f[H][W]);
void swap(int cur[H][W], int nxt[H][W]);
int new_speed(int *delay, int ch);
int number_neigh(int f[H][W], int y, int x);
void update_matrix(int cur[H][W], int nxt[H][W]);
int end_game(int cur[H][W], int nxt[H][W]);
void draw(int f[H][W], int delay);

int main() {
    initscr();  // начало ncurses
    cbreak();
    noecho();
    curs_set(0);
    nodelay(stdscr, TRUE);
    int arr[H][W], arr_nxt[H][W];
    input_from_file(arr);
    freopen("/dev/tty", "r", stdin);
    view(arr, arr_nxt);
    endwin();
    printf("ALL DEAD");  // убить всех
    return 0;
}

void input_from_file(int f[H][W]) {
    char a;
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 80;) {
            scanf("%c", &a);
            if (a == '1' || a == '0') {
                f[i][j] = a - '0';
                j++;
            }
        }
    }
}

void view(int f[H][W], int f_nxt[H][W]) {
    char ch;
    int delay = 150;
    while (1) {
        int flag = 0;
        move(0, 0);

        ch = getch();

        if (ch == ' ') {
            flag++;
        }

        new_speed(&delay, ch);
        move(0, 0);
        draw(f, delay);
        refresh();

        update_matrix(f, f_nxt);
        if (end_game(f, f_nxt) != 0) {
            flag++;
        }
        swap(f, f_nxt);

        if (flag != 0) {
            break;
        }

        napms(delay);
    }
}

int number_neigh(int f[H][W], int y, int x) {
    int cnt = 0;
    for (int dy = -1; dy <= 1; dy++) {
        for (int dx = -1; dx <= 1; dx++) {
            if (dy == 0 && dx == 0) {
                continue;
            }
            int ny = (y + dy + H) % H;
            int nx = (x + dx + W) % W;
            cnt += f[ny][nx];
        }
    }
    return cnt;
}

void update_matrix(int cur[H][W], int nxt[H][W]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            int n = number_neigh(cur, i, j);
            if (cur[i][j] == 1) {
                if (n == 2 || n == 3) {
                    nxt[i][j] = 1;
                } else {
                    nxt[i][j] = 0;
                }
            } else {
                if (n == 3) {
                    nxt[i][j] = 1;
                } else {
                    nxt[i][j] = 0;
                }
            }
        }
    }
}

void swap(int cur[H][W], int nxt[H][W]) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cur[i][j] = nxt[i][j];
        }
    }
}

int new_speed(int *delay, int ch) {
    if (ch == 'a' || ch == 'A') {
        if (*delay > MIN_DELAY) {
            *delay -= STEP;
        }
    } else if (ch == 'z' || ch == 'Z') {
        if (*delay < MAX_DELAY) {
            *delay += STEP;
        }
    }
    return *delay;
}

int end_game(int cur[H][W], int nxt[H][W]) {
    int same = 1;
    for (int i = 0; i < H && same; i++)
        for (int j = 0; j < W; j++)
            if (cur[i][j] != nxt[i][j]) {
                same = 0;
            }
    return same;
}

void draw(int f[H][W], int delay) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            move(i, j);
            if (f[i][j] == 1) {
                printw("*");
            } else {
                printw(" ");
            }
        }
    }
    move(H + 1, 20);
    printw("A / Z / Space - KILL ALL!!!!!!!! >:(");
    move(H + 2, 35);
    printw("SPEED: %d FPS", 500 / delay);
}