#include<stdio.h>
#include<math.h>
#include<stdbool.h>
#define EPSILON 0.001

int n;

int isApplicable(int order, float arr[][n+1])
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


void applySeidel(float a[][n+1],int maxIterations,float values_old[n], float allo_err)
{
    int i,j,k,iteration;
    int flag=0;
    float ratio,sum=0;
    float values_new[n];
    for(int i=0;i<n;i++)
     values_new[i]=0;
    for(iteration=1;iteration<=maxIterations;iteration++)
    {
        for(i=0;i<n;i++)
        {
            sum=0;
            for(j=0;j<n;j++)
            {
                if(i!=j)
                sum+=a[i][j]*values_new[j];
            }
            values_new[i]=(a[i][n] - sum)/a[i][i];
        }

        for(k=0;k<n;k++)
        {
            if(fabs(values_old[k]-values_new[k])<allo_err)
                continue;
            else
               flag=1;
        }
        if(flag==0)
        {
          printf("\nIteration: %d\t", iteration);
          printf("Values of unknowns are: -");
          for(int l = 0; l < n; l++)
          {
            printf("%f\t", values_new[l]);
          }
          printf("\n");
            return ;
        }
        else
        {

          flag=0;
          printf("\nIteration: %d\t", iteration);
          printf("Values of unknowns are: -");
          for(int l = 0; l < n; l++)
          {
            printf("%f\t", values_new[l]);
            values_old[l] = values_new[l];
          }
        }
    }
}


int main()
{
    int i,j,k,x,y,maxIterations;
    printf("Enter no of Unknowns\n");
    scanf("%d",&n);

    float a[n][n+1];
    float values[n];;

    printf("Enter the Augmented Matrix\n");
    for(int i=0;i<n;i++)
    {
     for(int j=0;j<n+1;j++)
     {
       printf("Enter the element at A[%d][%d]: ", i, j);
       scanf("%f",&a[i][j]);
     }
    }

   if(!isApplicable(n, a))
   {
        printf("Gauss Seidel Method can't be applied");
        return 0;
   }
   printf("Gauss Seidel Method is applicable\n");
   printf("Enter no. of iterations\n");
   scanf("%d",&maxIterations);
   float allo_err;
   printf("Enter allowed error: ");
   scanf(" %f", &allo_err);
   for(int i=0;i<n;i++)
     values[i]=0;
   applySeidel(a,maxIterations,values, allo_err);
   return 0;
}
