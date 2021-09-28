#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

const int N = 1e6 + 6, MOD = 1e9 + 7;

const int TOP_LEFT_WALL = 0b100;
const int TOP_RIGHT_WALL = 0b001;
const int TOP_WALL = TOP_LEFT_WALL | TOP_RIGHT_WALL;

vector<int> validOptions[8] = {
  { 0b000, 0b101 },
  {},
  { 0b010, 0b011, 0b110, 0b111},
  { 0b010, 0b011, 0b110, 0b111},
  {},
  { 0b000, 0b010, 0b011, 0b101, 0b110, 0b111 },
  { 0b010, 0b011, 0b110, 0b111 },
  { 0b000, 0b010, 0b011, 0b101, 0b110, 0b111 },
};

int t, n;

int mem[N][8];
int solve(int i, int last) {
  if (i == 0) return (last & TOP_WALL) == TOP_WALL;

  int& ret = mem[i][last];
  if (~ret) return ret;

  ret = 0;
  for (int validOption : validOptions[last]) {
    ret = (ret + solve(i - 1, validOption)) % MOD;
  }
  return ret;
}

int main() {
  scanf("%d", &t);
  memset(mem, -1, sizeof mem);
  while (t--) {
    scanf("%d", &n);
    printf("%d\n", solve(n, TOP_WALL));
  }
  return 0;
}