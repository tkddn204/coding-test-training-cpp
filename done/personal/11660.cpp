#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int table[1026][1026];
int dp[1026][1026];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> table[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = dp[i - 1][j] + dp[i][j - 1]
          - dp[i - 1][j - 1] + table[i][j];
    }
  }

  while(m--) {
    int x, y, a, b;
    cin >> x >> y >> a >> b;
    if (x == a and y == b) {
      cout << table[x][y] << endl;
    } else {
      int res = dp[a][b] - dp[x - 1][b] - dp[a][y - 1] + dp[x - 1][y - 1];
      cout << res << endl;
    }
  }
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