#include <stdio.h>
#include <math.h>

int isApplicable(int order, float arr[][order+1])
{
  int i, j, sum_nd=0, element_d;
  for(i = 0; i < order; i++)
  {
    for(j = 0; j < order; j++)
    {
      if(i!=j)
      {
        sum_nd += fabs(arr[i][j]);
      }
      else
        element_d = fabs(arr[i][j]);
    }
    if(sum_nd>element_d)
      return 0;
  }
  return 1;
}

void applyJacobi(int order, float arr[][order+1], int maxIteration, float allo_err)
{
  float old_value[order], new_value[order];
  for(int l = 0; l < order; l++)
    old_value[l] = 0.0;
  int i, j, iteration, flag=0;
  float sum = 0;
  for(iteration = 1; iteration <= maxIteration; iteration++)
  {
    for(i = 0; i < order; i++)
    {
      sum=0;
      for(j = 0; j< order; j++)
      {
        if(i!=j)
        {
          sum += (arr[i][j]*old_value[j]);
        }
      }
      new_value[i] = (arr[i][order] - sum) / arr[i][i];
    }

    for(int k = 0; k < order; k++)
    {
      if(fabs(old_value[k]-new_value[k])<allo_err)
      {
        continue;
      }
      else
      {
        flag++;
        break;
      }

    }
    if(flag == 0)
    {
      printf("\nIteration: %d\t", iteration);
      printf("Values of unknowns are: -");
      for(int l = 0; l < order; l++)
        printf("%f\t", new_value[l]);
      printf("\n");
      return ;
    }
    else
    {
      flag=0;
      printf("\nIteration: %d\t", iteration);
      printf("Values of unknowns are: -");
      for(int l = 0; l < order; l++)
      {
        printf("%f\t", new_value[l]);
        old_value[l] = new_value[l];
      }
    }
  }
}

int main()
{
  int order, row, column, check;
  printf("Enter the order of the matrix: ");
  scanf(" %d", &order);
  row = order;
  column = order + 1;
  int i, j;
  float arr[row][column];
  for(i = 0; i < row; i++)
  {
    for(j = 0; j < column; j++)
    {
      printf("Enter the element at A[%d][%d]: ", i, j);
      scanf(" %f", &arr[i][j]);
    }
  }

  printf("Entered Matrix:-\n");
  for(i = 0; i < row; i++)
  {
    for(j = 0; j < column; j++)
    {
      printf("%f\t", arr[i][j]);
    }
    printf("\n");
  }

  check = isApplicable(order, arr);
  if (check==1)
  {
    printf("Method is applicable\n");
    int maxIteration;
    printf("Enter maximum iteration: ");
    scanf(" %d", &maxIteration);
    float allo_err;
    printf("Enter allowed error: ");
    scanf(" %f", &allo_err);
    applyJacobi(order, arr, maxIteration, allo_err);
  }
  else
    printf("Jacobi method can't be applied\n");

  return 0;
}
