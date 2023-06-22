#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int pp[5][5];
bool vst[5][5];
int maxSum;

void bt(int cur, int sum) {
  if (cur >= n*m) {
    maxSum = max(maxSum, sum);
    return;
  }

  int x = cur / m;
  int y = cur % m;

  if (vst[x][y]) {
    bt(cur + 1, sum);
    return;
  }

  int num = pp[x][y];
  vst[x][y] = true;
  bt(cur + 1, sum + num);
  vst[x][y] = false;

  // 세로
  num = pp[x][y];
  for (int k = 1; k < n - x; k++) {
    num *= 10;
    num += pp[x + k][y];
    for (int i = 1; i <= k; i++) {
      vst[x + i][y] = true;
    }
    bt(cur + 1, sum + num);
    for (int i = 1; i <= k; i++) {
      vst[x + i][y] = false;
    }
  }
  // 가로
  num = pp[x][y];
  for (int k = 1; k < m - y; k++) {
    if (vst[x][y + k]) break;
    num *= 10;
    num += pp[x][y + k];
    for (int i = 1; i <= k; i++) {
      vst[x][y + i] = true;
    }
    bt(cur + 1, sum + num);
    for (int i = 1; i <= k; i++) {
      vst[x][y + i] = false;
    }
  }
}

void solve() {
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      pp[i][j] = s[j] - '0';
    }
  }
  bt(0, 0);
  cout << maxSum;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#endif
  solve();
  return 0;
}