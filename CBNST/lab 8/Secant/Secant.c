#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x)
{
  return (x*x*x - 6*x*x +x +9);
}

float valueOfX(float x1, float x2)
{
  return ((x1 * f(x2) - x2 * f(x1))/(f(x2) - f(x1)));
}

int main(int argc, char const *argv[])
{
  int maxIteration;
  float allo_err;
  printf("Enter maximum Iterations: ");
  scanf(" %d", &maxIteration);
  printf("Enter Allowed Error: ");
  scanf(" %f", &allo_err);
  float x, x1, x2;
  printf("Enter value of x1: ");
  scanf(" %f", &x1);
  printf("Enter value of x2: ");
  scanf(" %f", &x2);
  int i;
  x = valueOfX(x1, x2);
  for(i = 1; i <= maxIteration; i++)
  {
    printf("Value of X: %f\tIteration: %d\n", x, i);
    if(fabs(f(x)) < fabs(allo_err))
    {
      printf("Root Required: %f\n", x);
      return 0;
    }
    x = valueOfX(x1, x2);
    x1 = x2;
    x2 = x;
  }
  printf("Required Root: %f\n", x);
  // printf("%d", i);

  return 0;
}
