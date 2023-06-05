#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[1002][1002], dp[1002][1002];

void solve() {
  int n, m;
  cin >> n >> m;
  string s;
  for (int i = 1; i <= n; i++) {
    cin >> s;
    for (int j = 1; j <= m; j++) {
      arr[i][j] = s[j - 1] - '0';
    }
  }

  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (!arr[i][j]) continue;
      dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
      res = max(dp[i][j], res);
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cout << dp[i][j];
    }
    cout << endl;
  }

  cout << res * res << endl;
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