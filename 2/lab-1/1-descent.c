#include <stdio.h>

double seriesSumDescent(double x, int n, double Fi, int i, double sum) {
    if (i == 1) Fi = x;
    if (n > i - 1) {
        sum += Fi;
        Fi = -Fi * x * x / (4 * i * i + 2 * i);
        sum = seriesSumDescent(x, n, Fi, i + 1, sum);
    }
    return sum;
}

int descent() {
    double x;
    int n;

    printf("x = ");
    scanf("%lf", &x);
    printf("n = ");
    scanf("%d", &n);

    printf("Result: %lf\n", seriesSumDescent(x, n, 0, 1, 0));

    return 0;
}
