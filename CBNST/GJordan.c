#include <stdio.h>
#include <math.h>

void convertToDiagonal(int n, float a[][n+1])
{
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
         if(j!=i)
         {
             ratio=a[j][i]/a[i][i];
             for(k=0;k<n+1;k++)
                a[j][k]=a[j][k] -( ratio * a[i][k]);

             // //print the Matrix after changed row (Intermediate forms)
             // printf("Intermediate forms:\n");
             // for( x=0;x<n;x++)
             // {
             //   for(y=0;y<n+1;y++)
             //      printf("%f ",a[x][y]);
             //   printf("\n");
             // }
             // printf("\n");

         }
      }
     }
}


//prints the Value of Unknowns
void print(int n, float a[][n+1])
{
   int i;
   printf("Values of unknowns are:\n");
   for(i=0;i<n;i++)
      printf("Value of Variable %d=%f\n",i,a[i][n]/a[i][i]);

}

int main()
{
  int i, j, order, row, column;
  printf("Enter the number of unknown variables: ");
  scanf(" %d", &order);
  row = order;
  column = order + 1;
  float arr[row][column], value[order];
  for(i = 0; i < row; i++)
  {
    for(j = 0; j < column; j++)
    {
      printf("Enter the element of A[%d][%d]: ", i, j);
      scanf(" %f", &arr[i][j]);
    }
  }
  printf("Entered Augmented Matrix:-\n");
  for(i = 0; i < row; i++)
  {
    for(j = 0; j < column; j++)
    {
      printf("%f\t", arr[i][j]);
    }
    printf("\n");
  }

  convertToDiagonal(order, arr);
  print(order, arr);
  return 0;
}
