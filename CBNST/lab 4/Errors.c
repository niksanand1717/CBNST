#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int main(int argc, char const *argv[]) {

  float result, absolute_error, relative_error, percentage_error;

  printf("Enter True value: ");
  float true_value;
  scanf(" %f", &true_value);

  printf("Enter approximate value: ");
  float approx_value;
  scanf(" %f", &approx_value);

  printf("Absolute Error: ");
  absolute_error = fabs(true_value - approx_value);
  printf("%f\n\n", absolute_error);

  printf("Relative Error: ");
  relative_error = fabs(absolute_error/true_value);
  printf("%f\n\n", relative_error);

  printf("Percentage Error: ");
  //relative_error(absolute_error(true_value, approx_value), true_value);
  percentage_error = fabs(relative_error*100);
  printf("%f\n\n", percentage_error);
  return 0;
}
