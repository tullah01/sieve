#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int sieve(int n){
  int upper_bound = (int) n * log(n) + n*log(log(n));
  printf("DEAD %d\n", upper_bound);
  short * sv;
  sv = malloc(upper_bound * sizeof(short));

  int x, i;

  int up = (int) sqrt(upper_bound);

  for(x = 2; x < up + 1; x++){
    if(sv[x])
      continue;
    sv[x] = 0;

    for(i = 2*x; i < upper_bound; i += x){
      sv[i] = 1;
    }
  }

  int counter = 0;
  for(x = 2; x < upper_bound; x++){
    if (!sv[x])
      counter++;
    if(counter == n)
      return x;
  }

  free(sv);
  return upper_bound;
}

int main(){
  int target = 1000000;

  printf("\n%dth prime is: %d\n\n", target, sieve(target));
}