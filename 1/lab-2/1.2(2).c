#include <stdio.h>
#include <math.h>

int main() {

    int n, i, j, ct = 0;
    double num, sum = 0, P = 1;

    printf("Enter n:\n");
    scanf("%d", &n);
    ct++;

    if (n <= 0) {
        printf("Please enter a valid value for n\n");
    } else {
        sum = 0;

        for (i = 1; i <= n; i++) {
            sum += (2 * i + 1);
            num = 2 * i * log(i + 3);
            P *= num / sum;
            ct += 10;
        }

        printf("P = %.7lf\n", P);
        printf("Number of operations performed: %d", ct);
    }

    return 0;
}
