#include <stdio.h>

void binaryInsertionSortDescending(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float T = arr[i];
        int L = 0, R = i;

        while (L < R) {
            int j = (L + R) / 2;
            if (arr[j] >= T)
                L = j + 1;
            else
                R = j;
        }

        for (int k = i; k > R; k--)
            arr[k] = arr[k - 1];

        arr[R] = T;
    }
}

void sortMainDiagonal(float matrix[8][8]) {
    float diagonal[8];

    for (int i = 0; i < 8; i++)
        diagonal[i] = matrix[i][i];

    binaryInsertionSortDescending(diagonal, 8);

    for (int i = 0; i < 8; i++)
        matrix[i][i] = diagonal[i];
}

int main() {
    float matrix[8][8] = {
        {45, 20, 13, 44, 58, 16, 72, 18},
        {11, 38, 59, 10, 11, 12, 13, 14},
        {15, 16, 29, 18, 19, 20, 21, 22},
        {23, 24, 25, 12, 27, 28, 29, 30},
        {31, 32, 33, 34, 56, 36, 37, 38},
        {39, 40, 41, 42, 43, 17, 45, 46},
        {47, 48, 49, 50, 51, 52, 22, 54},
        {55, 56, 57, 58, 59, 60, 61, 13}
    };




    printf("Original matrix:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    sortMainDiagonal(matrix);

    printf("\nMatrix after sorting the main diagonal in descending order:\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
