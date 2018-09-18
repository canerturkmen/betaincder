#include "digamma.h"
#include <stdio.h>

int main(int argc, char *argv[]){
  printf("start test \n");

  printf("100: %.8f \n", digamma(100));
  printf("10: %.8f \n", digamma(10));
  printf("1: %.8f \n", digamma(1));
  printf("0.1: %.8f \n", digamma(0.1));
  printf("0.000000435: %.8f \n", digamma(0.000000435));

  return 0;
}
