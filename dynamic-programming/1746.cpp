#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5 + 5, M = 1e2 + 2, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int A[N];

int mem[N][M];
int solve(int i, int last) {
  if (i == n) return 1;

  int& ret = mem[i][last];
  if (~ret) return ret;

  if (A[i] != 0 && abs(A[i] - last) > 1)  return ret = 0;
  if (A[i] != 0)  return ret = solve(i + 1, A[i]) % MOD;

  ret = solve(i + 1, last) % MOD;
  if (last + 1 <= m)  ret = (ret + solve(i + 1, last + 1)) % MOD;
  if (last - 1 >= 1)  ret = (ret + solve(i + 1, last - 1)) % MOD;

  return ret;
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++)   scanf("%d", A + i);

  memset(mem, -1, sizeof mem);

  int ans = 0;
  if (A[0] == 0) {
    for (int init = 1; init <= m; init++) ans = (ans + solve(1, init)) % MOD;
  } else {
    ans = solve(1, A[0]);
  }

  printf("%d\n", ans);
  return 0;
}