#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>   // for getch() and kbhit()
#include <windows.h> // for Sleep()

#define WIDTH 10
#define HEIGHT 20

int field[HEIGHT][WIDTH] = {0};

int score = 0;

// Tetromino definitions (4x4)
int tetromino[7][4] = {
    {1, 3, 5, 7}, // I
    {2, 4, 5, 7}, // Z
    {3, 5, 4, 6}, // S
    {3, 5, 4, 7}, // T
    {2, 3, 5, 7}, // L
    {3, 5, 7, 6}, // J
    {2, 3, 4, 5}  // O
};

typedef struct {
    int x, y;
} Point;

Point current[4], backup[4];

int check() {
    for (int i = 0; i < 4; i++) {
        if (current[i].x < 0 || current[i].x >= WIDTH || current[i].y >= HEIGHT)
            return 0;
        if (field[current[i].y][current[i].x])
            return 0;
    }
    return 1;
}

void rotate() {
    Point p = current[1]; // rotate around second block
    for (int i = 0; i < 4; i++) {
        int x = current[i].y - p.y;
        int y = current[i].x - p.x;
        current[i].x = p.x - x;
        current[i].y = p.y + y;
    }
    if (!check())
        for (int i = 0; i < 4; i++)
            current[i] = backup[i]; // revert if not valid
}

void draw() {
    system("cls");
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (field[y][x])
                printf("[]");
            else {
                int block = 0;
                for (int i = 0; i < 4; i++)
                    if (current[i].x == x && current[i].y == y)
                        block = 1;
                if (block)
                    printf("[]");
                else
                    printf(" .");
            }
        }
        printf("\n");
    }
    printf("Score: %d\n", score);
}

void removeLine() {
    for (int y = HEIGHT - 1; y >= 0; y--) {
        int full = 1;
        for (int x = 0; x < WIDTH; x++)
            if (!field[y][x])
                full = 0;
        if (full) {
            for (int ty = y; ty > 0; ty--)
                for (int tx = 0; tx < WIDTH; tx++)
                    field[ty][tx] = field[ty - 1][tx];
            for (int tx = 0; tx < WIDTH; tx++)
                field[0][tx] = 0;
            score += 100;
            y++; // recheck same line
        }
    }
}

int main() {
    int n = rand() % 7;
    for (int i = 0; i < 4; i++) {
        current[i].x = tetromino[n][i] % 2 + WIDTH/2 - 1;
        current[i].y = tetromino[n][i] / 2;
    }

    int dx = 0;
    int rotateFlag = 0;
    int speed = 500;
    int tick = 0;

    while (1) {
        Sleep(50);
        tick += 50;

        dx = 0;
        rotateFlag = 0;

        if (kbhit()) {
            char c = getch();
            if (c == 'a') dx = -1;
            else if (c == 'd') dx = 1;
            else if (c == 'w') rotateFlag = 1;
            else if (c == 's') tick = speed; // drop faster
        }

        for (int i = 0; i < 4; i++)
            backup[i] = current[i];

        for (int i = 0; i < 4; i++)
            current[i].x += dx;
        if (!check())
            for (int i = 0; i < 4; i++)
                current[i] = backup[i];

        if (rotateFlag) rotate();

        if (tick >= speed) {
            tick = 0;
            for (int i = 0; i < 4; i++)
                current[i].y += 1;
            if (!check()) {
                for (int i = 0; i < 4; i++)
                    field[backup[i].y][backup[i].x] = 1;

                removeLine();

                n = rand() % 7;
                for (int i = 0; i < 4; i++) {
                    current[i].x = tetromino[n][i] % 2 + WIDTH/2 - 1;
                    current[i].y = tetromino[n][i] / 2;
                }
                if (!check()) {
                    system("cls");
                    printf("Game Over!\nScore: %d\n", score);
                    break;
                }
            }
        }

        draw();
    }

    return 0;
}
