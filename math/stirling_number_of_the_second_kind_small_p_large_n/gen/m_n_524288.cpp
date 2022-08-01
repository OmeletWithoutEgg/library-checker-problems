#include <iostream>

#include "../params.h"
#include "random.h"

// 524288 = 2^19
int main(int, char* argv[]) {
  long long seed = atoll(argv[1]);
  auto gen = Random(seed);

  int t = T_MAX;
  int m = 524288;
  printf("%d %d\n", t, m);

  while (t--) {
    long long n, k;
    do {
      n = gen.uniform<long long>(0, m);
      k = gen.uniform<long long>(0, m);
    } while (n < k);
    printf("%lld %lld\n", n, k);
  }

  return 0;
}
