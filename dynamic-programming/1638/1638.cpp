#include <cstdio>

using namespace std;

const int N = 1e3 + 3, MOD = 1e9 + 7;

int n;
char A[N][N];
int dp[N][N];

int main() {
  scanf("%d", &n);
  for (int r = 0; r < n; r++) {
    scanf("%s", A[r]);
  }
  dp[n][n - 1] = 1;
  for (int r = n - 1; ~r; r--) {
    for (int c = n - 1; ~c; c--) {
      if (A[r][c] != '.') {
        continue;
      }
      dp[r][c] = (dp[r + 1][c] + dp[r][c + 1]) % MOD;
    }
  }
  printf("%d\n", dp[0][0]);
  return 0;
}