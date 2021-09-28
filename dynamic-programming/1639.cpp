#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 5e3 + 3, OO = 0x3f3f3f3f;

char s1[N], s2[N];

int mem[N][N];
int solve(int len1, int len2) {
  if (len1 == 0 || len2 == 0) return len1 ? len1 : len2;

  int& ret = mem[len1][len2];
  if (~ret) return ret;

  ret = OO;
  if (s1[len1 - 1] == s2[len2 - 1]) ret = solve(len1 - 1, len2 - 1);

  // Edits
  ret = min(ret, 1 + solve(len1 - 1, len2 - 1));
  ret = min(ret, 1 + solve(len1 - 1, len2));
  ret = min(ret, 1 + solve(len1, len2 - 1));

  return ret;
}

int main() {
  scanf("%s %s", s1, s2);
  memset(mem, -1, sizeof mem);

  printf("%d\n", solve(strlen(s1), strlen(s2)));
  return 0;
}
