#include "digamma.h"
#include "beta.h"
#include <stdio.h>

int main(int argc, char *argv[]){
  printf("start test -- digamma \n");

  printf("100: %.8f \n", digamma(100));
  printf("10: %.8f \n", digamma(10));
  printf("1: %.8f \n", digamma(1));
  printf("0.1: %.8f \n", digamma(0.1));
  printf("0.000000435: %.8f \n", digamma(0.000000435));

  printf("\n start test -- betainc \n");

  printf("1.5,  11.0,  0.001: %.10e \n", betainc(0.001, 1.5, 11.0, 100));
  printf("1.5,  11.0,  0.500: %.10e \n", betainc(0.500, 1.5, 11.0, 100));
  printf("1000, 1000,  0.500: %.10e \n", betainc(0.500, 1e3, 1e3, 100));
  printf("1000, 1000,  0.550: %.10e \n", betainc(0.550, 1e3, 1e3, 100));

  return 0;
}
