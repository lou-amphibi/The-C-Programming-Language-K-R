#include <stdio.h>

float fncte(float m);

int main()
{
    float fahr;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        printf("%3.0f %6.1f\n", fahr, fncte(fahr));
        fahr = fahr + step;
    }
}

float fncte(float m)
{
  float celsius;
  celsius = (5.0/9.0) * (m-32.0);
  return (celsius);
}