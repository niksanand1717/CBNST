#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float f(float x)
{
  return (x*x*x - 4*x - 9);
}

float q_diff(float x)
{
  // printf("%f\n", x);
  // printf("%f\n", ((4/3.0)*(1/pow((4*x+9), 2/3.0))));
  return ((4/3.0)*(1/pow((4*x+9), 2/3.0)));
}

float q(float x)
{
  return (pow((4*x + 9), 1/3.0));
}

int main(int argc, char const *argv[]) {

  printf("Enter Value of x1 and x2: ");
  float x1, x2;
  scanf(" %f %f", &x1, &x2);
  if(f(x1)*f(x2)>=0)
  {
    printf("Invalid bound\nEnter valid bound\n0");
    exit(0);
  }

  int i = 0;
  float x0;
  if((fabs(q_diff(x1)<1)) && (fabs(q_diff(x2))<1))
  {
    printf("Enter Allowed Error: " );
    float allo_err;
    scanf(" %f", &allo_err);


    while(1)
    {

    if(fabs(f(x1))<fabs(f(x2)))
      x0 = x1;
    else
      x0 = x2;

    if (fabs(q(x0)) <= allo_err)
      break;

    i++;

    }
  }

  else
  {
    printf("This Equation does not satisfy the Condition for Iteration Method\n");
    exit(0);
  }

  printf("No of Iterations: %d\n", i);
  printf("Root of the Equation: %f\n", x0);
  return 0;
}
