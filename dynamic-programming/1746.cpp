#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e5 + 5, M = 1e2 + 2, OO = 0x3f3f3f3f, MOD = 1e9 + 7;

int n, m;
int A[N];

int dp[2][M]; // currentElement, lastValue
int solve() {
  fill(dp[n & 1], dp[n & 1] + m + 1, 1);
  for (int i = n - 1; ~i; i--) {
    
  }
}

int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", A + i);
  }
  printf("%d\n", solve());
  return 0;
}