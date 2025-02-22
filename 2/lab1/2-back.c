#include <stdio.h>

double SUM = 0;

double seriesSumBack(double x, int n) {
    double Fi;
    if (n == 1) {
        Fi = x;
    } else {
        Fi = seriesSumBack(x, n - 1);
        Fi = -Fi * x * x / (4 * (n - 1) * (n - 1) + 2 * (n - 1));
    }
    SUM += Fi;
    return Fi;
}

int back() {
    double x;
    int n;

    printf("x = ");
    scanf("%lf", &x);
    printf("n = ");
    scanf("%d", &n);

    seriesSumBack(x, n);
    printf("Result: %lf\n", SUM);

    return 0;
}
