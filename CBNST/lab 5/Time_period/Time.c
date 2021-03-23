#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float time_period(float length) {
  return (2*3.14*(sqrt(length/9.8)));
}

int main() {
  float true_value_length, approx_value_length, true_value, approx_value, absolute_error, relative_error, percentage_error;
  printf("Enter the true value of length: ");
  scanf(" %f", &true_value_length);
  printf("Enter the approx value of length: ");
  scanf(" %f", &approx_value_length);

  true_value = time_period(true_value_length);
  approx_value = time_period(approx_value_length);

  absolute_error = fabs(true_value - approx_value);
  printf("\n\nAbsolute Error in Time Period: %f\n", absolute_error);
  relative_error = absolute_error/true_value;
  printf("Relative Error in Time Period: %f\n", relative_error);
  percentage_error = relative_error*100;
  printf("Percentage Error in Time Period: %f %\n", percentage_error);

  return 0;
}
