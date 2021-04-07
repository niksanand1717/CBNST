#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
  printf("Enter the number of x: ");
  int x_size;
  scanf("%d", &x_size);
  // y_size = x_size;
  printf("Enter the elements of x column wise: ");
  int i, j;
  float arr[x_size][x_size + 1];
  for(j = 0; j < x_size; j++)
    scanf("%f", &arr[j][0]);
  printf("Enter the elements of y column wise: ");
  for(j = 0; j < x_size; j++)
    scanf("%f", &arr[j][1]);

  for(j = 2 ; j<x_size+1 ; j++)
        for(i = 0 ; i<x_size-j+1 ; i++)
            arr[i][j] = arr[i+1][j-1] - arr[i][j-1];

  printf("The Difference Table is as follows:\n");
  for(i=0 ; i<x_size ; i++)
  {
   for(j=0 ; j<=x_size-i ; j++)
    printf("%f ", arr[i][j]);
   printf("\n");
  }

  printf("Enter the value of X to find value of Y: ");
  float x, x0, p, p1, y;
  scanf("%f", &x);

  x0 = arr[x_size - 1][0];
  y = arr[x_size - 1 ][1];
  p = (x - x0)/(arr[1][0] - arr[0][0]);
  p1 = p;
  float factorial = 1;
  for(j = 2; j <= x_size; j++)
  {
    y = y + (p1 * (arr[0][j]))/factorial;
    p1 = (p * (p - (j + 1)));
    factorial = factorial * j;
  }

  printf("Value of Y at X = %f is : %f\n", x, y);

  return 0;
}
