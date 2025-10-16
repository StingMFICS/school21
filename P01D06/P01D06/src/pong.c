#include <stdio.h>

#define WIDTH 80
#define HEIGHT 25
#define PADDLE_SIZE 3
#define BALL_SIZE 1

void draw(int leftR_top, int leftR_x, int rightR_top, int rightR_x, int ball_x, int ball_y);
void play_pong(int leftR_top, int leftR_bottom, int leftR_x, int rightR_top, int rightR_bottom, int rightR_x,
               int ball_x, int ball_y, int ball_dirX, int ball_dirY, int pl1_score, int pl2_score);
void clear_screen();
char input();

int main() {
    int leftR_top = 11, leftR_bottom = 13, leftR_x = 2, rightR_top = 11, rightR_bottom = 13, rightR_x = 77,
        ball_x = 39, ball_y = 12, ball_dirX = 1, ball_dirY = 1, pl1_score = 0, pl2_score = 0;
    play_pong(leftR_top, leftR_bottom, leftR_x, rightR_top, rightR_bottom, rightR_x, ball_x, ball_y,
              ball_dirX, ball_dirY, pl1_score, pl2_score);
    return 0;
}

void clear_screen() { printf("\033[H\033[J"); }

void draw(int leftR_top, int leftR_x, int rightR_top, int rightR_x, int ball_x, int ball_y) {
    clear_screen();

    int x, y;

    for (y = 0; y < HEIGHT; y++) {
        for (x = 0; x < WIDTH; x++) {
            if (y == 0 || y == HEIGHT - 1) {
                printf("-");
            }
            if ((y != 0 && y != HEIGHT - 1) && (x == 0 || x == WIDTH - 1)) {
                printf("|");
            }
            if ((y != 0 && y != HEIGHT - 1) && (x != 0 && x != WIDTH - 1)) {
                if (x == leftR_x) {
                    if (y >= leftR_top) {
                        if (y < leftR_top + PADDLE_SIZE) {
                            printf("|");
                        }
                        if (y >= leftR_top + PADDLE_SIZE) {
                            printf(" ");
                        }
                    }
                    if (y < leftR_top) {
                        printf(" ");
                    }
                }
                if (x == rightR_x) {
                    if (y >= rightR_top) {
                        if (y < rightR_top + PADDLE_SIZE) {
                            printf("|");
                        }
                        if (y >= rightR_top + PADDLE_SIZE) {
                            printf(" ");
                        }
                    }
                    if (y < rightR_top) {
                        printf(" ");
                    }
                }
                if (x != leftR_x && x != rightR_x) {
                    if (x == ball_x) {
                        if (y == ball_y) {
                            printf("O");
                        }
                        if (y != ball_y) {
                            printf(" ");
                        }
                    }
                    if (x != ball_x) {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
}
void play_pong(int leftR_top, int leftR_bottom, int leftR_x, int rightR_top, int rightR_bottom, int rightR_x,
               int ball_x, int ball_y, int ball_dirX, int ball_dirY, int pl1_score, int pl2_score) {
    while (pl1_score < 21 || pl2_score < 21) {
        draw(leftR_top, leftR_x, rightR_top, rightR_x, ball_x, ball_y);
        printf("Enter move (A/Z for P1, K/M for P2, space to pass, Q to exit): ");
        char input_key = input();
        if (input_key == 'q') {
            printf("Game over forsed\nPlayer 1 score: %d\nPlayer 2 score: %d\n", pl1_score, pl2_score);
            break;
        }
        if (input_key == 'a' || input_key == 'z' || input_key == 'k' || input_key == 'm' ||
            input_key == ' ') {
            ball_x += ball_dirX;
            ball_y += ball_dirY;
        }
        if (input_key == 'a' && leftR_top > 1) {
            leftR_top--;
            leftR_bottom--;
        } else if (input_key == 'z' && leftR_bottom < 23) {
            leftR_top++;
            leftR_bottom++;
        } else if (input_key == 'k' && rightR_top > 1) {
            rightR_top--;
            rightR_bottom--;
        } else if (input_key == 'm' && rightR_bottom < 23) {
            rightR_top++;
            rightR_bottom++;
        }
        if (ball_x < leftR_x || ball_x > rightR_x) {
            if (ball_x < leftR_x) {
                pl2_score++;
            }
            if (ball_x > rightR_x) {
                pl1_score++;
            }
            ball_x = 39;
            ball_y = 12;
            ball_dirX = 1;
            ball_dirY = 1;
            leftR_top = 11;
            leftR_bottom = 13;
            leftR_x = 2;
            rightR_top = 11;
            rightR_bottom = 13;
            rightR_x = 77;
        }
        if (ball_x == rightR_x - 1 && ball_y >= rightR_top && ball_y <= rightR_bottom) {
            ball_dirX = -1;
        }
        if (ball_x == leftR_x + 1 && ball_y >= leftR_top && ball_y <= leftR_bottom) {
            ball_dirX = 1;
        }
        if (ball_y <= 1) {
            ball_y = 1;
            ball_dirY = 1;
        }
        if (ball_y >= 23) {
            ball_y = 23;
            ball_dirY = -1;
        }
    }
    if (pl1_score >= 21) {
        printf("Player 1 win the pong!\n");
    } else if (pl2_score >= 21) {
        printf("Player 2 win the pong!\n");
    }
}
char input() {
    char ch = getchar();
    while (getchar() != '\n');
    return ch;
}
