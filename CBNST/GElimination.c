#include <stdio.h>
#include <math.h>

void upperTriangular(int n,float arr[][n+1])
{
    int i,j,x,y,k;
    float ratio;
    for( i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
         if(j>i)
         {
             ratio=arr[j][i]/arr[i][i];
             for(k=0;k<n+1;k++)
                arr[j][k]=arr[j][k] -( ratio * arr[i][k]);

             // printf("Intermediate forms:\n");
             // for( x=0;x<n;x++)
             // {
             //   for(y=0;y<n+1;y++)
             //      printf("%f ",arr[x][y]);
             //   printf("\n");
             // }
             // printf("\n");

         }
      }
     }
}

void backSubs(int n,float arr[][n+1],float value[])
{
    int i,j;
    float sum;
    value[n-1]=arr[n-1][n]/arr[n-1][n-1];

    for(i=n-2;i>=0;i--)
    {
        sum=0;
        for(j=i+1;j<n;j++)
            sum=sum+arr[i][j]*value[j];
        value[i] = (arr[i][n]-sum)/arr[i][i];
    }
}

void print(int n, float value[])
{
   int i;
   printf("Values of unknowns are:\n");
   for(i=0;i<n;i++)
      printf("Value[%d]=%f\n",i,value[i]);

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

  upperTriangular(order, arr);
  backSubs(order, arr, value);
  print(order, value);
  return 0;
}
