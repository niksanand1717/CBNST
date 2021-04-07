#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  int i, j, size;
  printf("Enter the number of elements: ");
  scanf("%d", &size);
  float X[size], Y[size], x;
  printf("Enter the elements of X: ");
  for(i = 0 ; i<size ; i++)
    scanf("%f", &X[i]);
  printf("Enter the elements of Y: ");
  for(i = 0 ; i<size ; i++)
    scanf("%f", &Y[i]);
  printf("Enter the value of x at which you need y: ");
  scanf("%f", &x);

  float sum, term;
  for(i = 0; i<size; i++)
  {
    term=1;
    for(j = 0; j<size; j++)
    {
      if(i!=j)
        term *= (x - X[j])/(X[i] - X[j]);
    }
    sum += term*Y[i];
  }

  printf("Answer for x = %f is : %f\n", x, sum);

  return 0;
}
