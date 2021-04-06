#include <stdio.h>
#include <math.h>
#include <stdlib.h>

double f(float x)
{
  // return x*x*x - 3*x - 5;
  return x - exp(-x);
  // return x*log10(x)-1.2;
}

float f_dash(float x)
{
  // return 3*x*x - 3;
  return 1 + exp(-x);
  // return (x*1/x) - (log10(x));
}

float NRformula(float x0)
{
  return (x0 - f(x0)/f_dash(x0));
}

int main(int argc, char const *argv[])
{
  float x0, x1, x2, x, allo_err;
  int i=1, maxIteration;
  printf("Enter the value of x1: ");
  scanf(" %f", &x1);
  printf("Enter the value of x2: ");
  scanf(" %f", &x2);

  if (f(x1)*f(x2)>0)
  {
    printf("Invalid limit bound\ntry again with new value of x1 and x2\n");
    return 0;
  }

  printf("Enter maximum Iteration: ");
  scanf(" %d", &maxIteration);
  printf("Enter allowed error: ");
  scanf(" %f", &allo_err);
  x0 = (x1+x2)/2;
  while(i!=maxIteration)
  {

    x = NRformula(x0);

    if(fabs(x-x0)<=allo_err)
    {
      printf("Root: %f\tIteration: %i\n", x, i);
      return 0;
    }

    printf("Root: %f\tIteration: %i\n", x, i);
    x0 = x;
    i++;
  }

  printf("Root: %f\tIteration: %i\n", x, i);
  return 0;
}
