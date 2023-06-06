#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int st[3][100002];
int dp[3][100002];

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;

    for (int i = 1; i <= 2; i++) {
      for (int j = 1; j <= n; j++) {
        cin >> st[i][j];
      }
    }

    dp[1][1] = st[1][1];
    dp[2][1] = st[2][1];
    for (int i = 2; i <= n; i++) {
      dp[1][i] = max(dp[2][i - 1], dp[2][i - 2]) + st[1][i];
      dp[2][i] = max(dp[1][i - 1], dp[1][i - 2]) + st[2][i];
    }

    cout << max(dp[1][n], dp[2][n]) << endl;
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