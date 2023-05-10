#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int dp[1002][1002];
  int mod = 10007;
  for (int i = 1; i <= 1000 ; i++) {
    dp[i][0] = dp[i][i] = 1;
    for (int j = 1; j < i; j++) {
      dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % mod;
    }
  }
  int n, m;
  cin >> n >> m;
  cout << dp[n][m];
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