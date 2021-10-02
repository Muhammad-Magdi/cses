#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 5e3 + 3;

typedef long long ll;

int n, A[N];

ll mem[N][N][2];

ll solve(int l, int r, bool isMaximizing) {
  if (r < l)  return 0;

  ll& ret = mem[l][r][isMaximizing];
  if (~ret) return ret;

  if (isMaximizing)
    return ret = max(solve(l + 1, r, false) + A[l], solve(l, r - 1, false) + A[r]);
  else
    return ret = min(solve(l + 1, r, true), solve(l, r - 1, true));
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", A + i);

  memset(mem, -1, sizeof mem);

  printf("%lld\n", solve(0, n - 1, true));
  return 0;
}