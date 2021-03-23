#include <stdio.h>
#include <stdlib.h>

float f(float x)
{
    float result;
    result = (x*x - 2*x - 8);
    return result;
}

float falsi(float x0, float x1)
{
    float x2;
    x2 = x0 - ((x1-x0)/(f(x1)-f(x0))*f(x0));
    return x2;
}

int main(int argc, char const *argv[]) {

  float x0, x1, x2;
  int i, max_iteration;


    printf("Enter value of x0: ");
    scanf(" %f",&x0);
    printf("Enter value of x1: ");
    scanf(" %f",&x1);
    if(f(x0)*f(x1)>0)
    {
      printf("Invalid value of x0 and x1\n");
      exit(0);
    }
    printf("Enter number of Iteration: ");
    scanf(" %d",&max_iteration);



  for(i = 1; i <= max_iteration; i++)
  {

    x2 = falsi(x0, x1);
    if (f(x0) * f(x2) < 0)
      x1 = x2;
    else
      x0 = x2;

    printf("Iteration: %d\tx: %f\n", i, x2 );
  }

  return 0;
}
