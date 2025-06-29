#include <stdio.h>

int w = 0, b = 0;

void count(int arr[][128], int x, int y, int size) {
    int color = arr[x][y];
    int check = 1;

    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            if (arr[i][j] != color) {
                check = 0;
                break;
            }
        }
        if (!check) break;
    }

    if (check) {
        if (color == 0) w++;
        else b++;
        return;
    }

    int half = size / 2;
    count(arr, x, y, half);
    count(arr, x + half, y, half);
    count(arr, x, y + half, half);
    count(arr, x + half, y + half, half);
}

int main(void) {
    int n;
    scanf("%d", &n);
    int arr[128][128];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    count(arr, 0, 0, n);

    printf("%d\n%d", w, b);

    return 0;
}
