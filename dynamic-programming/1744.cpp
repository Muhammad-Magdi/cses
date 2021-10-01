#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 5e2 + 2, OO = 0x3f3f3f3f;

int a, b;

int mem[N][N];
int solve(int a, int b) {
  if (a == b) return 0;

  if (a > b)  swap(a, b);

  int& ret = mem[a][b];
  if (~ret) return ret;

  ret = OO;
  for (int d = 1; d < b; d++) {
    ret = min(ret, solve(a, d) + solve(a, b - d) + 1);
    if (a > d)  ret = min(ret, solve(d, b) + solve(a - d, b) + 1);
  }
  return ret;
}

int main() {
  scanf("%d %d", &a, &b);
  memset(mem, -1, sizeof mem);

  printf("%d\n", solve(a, b));
  return 0;
}
