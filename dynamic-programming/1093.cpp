#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e2 + 2, MOD = 1e9 + 7, MOD_INVERSE = 5e9 + 4;

int n, target;

int mem[N][N * N];
int solve(int i, int sum) {
  if (i == n) return 4 * sum == (n * (n + 1));

  int& ret = mem[i][sum];
  if (~ret) return ret;

  return ret = (solve(i + 1, sum + i) + solve(i + 1, sum)) % MOD;
}

int main() {
  scanf("%d", &n);

  memset(mem, -1, sizeof mem);

  printf("%d\n", (1ll * solve(0, 0) * MOD_INVERSE) % MOD);
  return 0;
}