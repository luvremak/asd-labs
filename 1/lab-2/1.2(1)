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
        for (i = 1; i <= n; i++) {

            sum = 0;
            num = 2 * i * log(i + 3);

            for (j = 1; j <= i; j++) {
                sum += (2 * j + 1);
                ct += 7; // j=1;j<=n; j++; +; *; +; =
            }

            P *= num/sum;
            ct += 11; // i=1; i <= n; i++; *; *; log; +; =; *; /; =

        }
        printf("P = %.7lf\n", P);
        printf("Number of operations performed: %d", ct);
    }

    return 0;
}
