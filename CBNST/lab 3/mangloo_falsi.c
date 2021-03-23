#include<stdio.h>
#include<math.h>
#include<stdlib.h>
float f(float x)
{
  return(x*x*x-x-1);
}
void rflsi(float a,float b)
{
  float ctr,aerr,f2;
  int itr=1;
  printf("Enter the value of allowed error:");
  scanf("%f",&aerr);
  while(1)
{
  ctr=a-((b-a)/f(b)-f(a))*f(a);
  f2=f(ctr);
  printf("After iteration number%d x is %f and function is %f \n",itr,ctr,f(ctr));
  if(fabs(f(ctr)) <= aerr)
  break;
  if(f(a)*f(ctr)<0)
  {
      b=ctr;
  }
  else{
    a=ctr;
  }
  itr=itr+1;
}
  printf("the root of the equation is %3f \n",ctr);
}
int main()
{
float a,b;
printf("Enter your guess:");
scanf("%f%f",&a,&b);
if(f(a)*f(b)<0)
{
printf("The range of root is between %1f and %1f \n",a,b);
rflsi(a,b);
}
else
{
printf("You have enter wrong guess");
}
return 0;
}
