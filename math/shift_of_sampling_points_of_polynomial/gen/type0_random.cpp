#include <cstdlib>
#include <cstdio>

#include "../params.h"
#include "random.h"

int main(int, char* argv[]) {
  long long seed = std::atoll(argv[1]);
  auto gen = Random(seed);

  int n = gen.uniform<int>(2, N_MAX);
  int c = gen.uniform<int>(0, n - 1);
  int m = gen.uniform<int>(1, n - c);

  // generate case for sampling points like
  // f(0), …, f(c), …, f(c + m - 1), …, f(n - 1)
  // c >= 0 and c + m - 1 <= n - 1

  std::printf("%d %d %d\n", n, m, c);

  for (int i = 0; i < n; ++i) {
    std::printf("%d", gen.uniform<int>(0, MOD - 1));
    if (i != n - 1) std::printf(" ");
  }
  std::printf("\n");

  return 0;
}