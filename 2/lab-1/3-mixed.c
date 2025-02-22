#include <stdio.h>

double seriesSumMixed(double x, int n, double Fi, int i, double sum) {
    if (i == 1) Fi = x;
    sum += Fi; 
    if (n == 1) return sum; 

    Fi = -Fi * x * x / (4 * i * i + 2 * i); 
    return seriesSumMixed(x, n - 1, Fi, i + 1, sum); 
}

int mixed() {
    double x;
    int n;

    printf("x = ");
    scanf("%lf", &x);
    printf("n = ");
    scanf("%d", &n);

    printf("Result: %lf\n", seriesSumMixed(x, n, x, 1, 0)); 
    return 0;
}

