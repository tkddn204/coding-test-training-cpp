#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[50001];

void solve() {
  int n;
  cin >> n;

  dp[1] = 1;

  for (int i = 1; i <= n; i++) {
    dp[i] = dp[1] + dp[i - 1];
    for (int j = 2; j * j <= i; j++) {
      dp[i] = min(dp[i], dp[i - j * j] + 1);
    }
  }
  cout << dp[n];
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