#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void search(int matrix[][100], int m, int n, int X) {
    int isFound = 0;
    for (int col = 0; col < n; col++) {
        for (int row = 0; row < m; row++) {
            if (matrix[row][col] == X) {
                printf("Number %d found at: row = %d, column = %d\n", X, row + 1, col + 1);
                isFound = 1;
            }
        }
    }
    if (!isFound) {
        printf("Number is not in the matrix.\n", X);
    }
}

void generateRandomMatrix(int matrix[][100], int m, int n) {
    srand(time(0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = rand() % 100 + 1;
        }
    }
}

void displayMatrix(int matrix[][100], int m, int n) {
    printf("Generated matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n, X;

    printf("Enter the number of rows (m): ");
    scanf("%d", &m);
    printf("Enter the number of columns (n): ");
    scanf("%d", &n);

    int matrix[100][100];

    generateRandomMatrix(matrix, m, n);

    displayMatrix(matrix, m, n);

    printf("Enter the number to search for (X): ");
    scanf("%d", &X);

    search(matrix, m, n, X);

    return 0;
}
