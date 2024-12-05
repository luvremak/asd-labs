#include <stdio.h>
#include <windows.h>

int main() {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord;
    int rows = 24, columns = 80, pause = 5;
    int grid[24][80] = {{' '}};
    int x = columns / 2, y = rows / 2;
    int left = x - 1, right = x + 1, up = y - 1, down = y + 1;
    grid[y][x] = '@';

    SetConsoleTextAttribute(h, FOREGROUND_RED);

    while (left >= 0 && right < columns && up >= 0 && down < rows) {
        // Move left
        for (; x >= left && x >= 0; x--) {
            grid[y][x] = '@';
            coord.X = x; coord.Y = y;
            SetConsoleCursorPosition(h, coord);
            printf("@");
            Sleep(pause);
        }
        x++; y++; left--;

        for (; y <= down && y < rows; y++) {
            grid[y][x] = '@';
            coord.X = x; coord.Y = y;
            SetConsoleCursorPosition(h, coord);
            printf("@");
            Sleep(pause);
        }
        y--; x++; down++;

        for (; x <= right && x < columns; x++) {
            grid[y][x] = '@';
            coord.X = x; coord.Y = y;
            SetConsoleCursorPosition(h, coord);
            printf("@");
            Sleep(pause);
        }
        x--; y--; right++;

        for (; y >= up && y >= 0; y--) {
            grid[y][x] = '@';
            coord.X = x; coord.Y = y;
            SetConsoleCursorPosition(h, coord);
            printf("@");
            Sleep(pause);
        }
        y++; x--; up--;
    }

    coord.X = 0; coord.Y = right + 1;
    SetConsoleCursorPosition(h, coord);
    return 0;
}
