#include <stdio.h>
#include <stdlib.h>

int main() {
  float x;
  printf("Whats x? ");
  scanf("%f", &x);
  if (-15 < x && x <= 3) {
    float y = 4 * (x * x) + 2;
    printf("y = %f\n", y);
  }
  else if (x <= -30 || x > 20) {
    float z = (3 * (x * x * x)) / 4 - 5;
    printf("y = %f\n", z);
  } else {
    printf("no such value for x");
  }

  return 0;
}
