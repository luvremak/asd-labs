#include <stdio.h>

#define SIZE 7

void printMatrix(double matrix[SIZE][SIZE]) {
    printf("Matrix:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%.1lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int findLeftmostDiagonal(double matrix[SIZE][SIZE], double target) {
    for (int i = 0; i < SIZE; i++) {
        if (matrix[i][i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    double matrix[SIZE][SIZE] = {
        {6.0, -8.0, 7.2, 0.0, -4.4, 10.0, -2.0},
        {4.6, -2.0, -8.8, 8.0, 2.0, -8.6, 9.5},
        {-10.0, -6.8, 1.9, -3.1, 0.6, 10.0, 8.0},
        {-8.0, -6.6, 4.0, -0.2, 8.4, -2.0, 5.2},
        {-4.0, 6.6, 8.0, -2.2, 0.0, -3.0, 4.3},
        {2.0, 0.4, -6.0, 4.8, -10.3, 1.9, 6.0},
        {2.0, 4.0, -10.0, 8.4, -7.7, -0.6, -2.0}
    };

    printMatrix(matrix);

    double target;
    printf("\nEnter the number to search for in the main diagonal: ");
    scanf("%lf", &target);

    int index = findLeftmostDiagonal(matrix, target);

    if (index != -1) {
        printf("Element %.1lf found at position [%d, %d] in the main diagonal.\n", target, index, index);
    } else {
        printf("Element %.1lf not found in the main diagonal.\n", target);
    }

    return 0;
}
