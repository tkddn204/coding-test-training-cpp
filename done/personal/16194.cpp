#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int card[10001];
int dp[10001];

void solve() {
  int n;
  cin >> n;
  
  for (int i = 1; i <= n; i++) {
    cin >> card[i];
  }

  dp[1] = card[1];
  for (int i = 1; i <= n; i++) {
    dp[i] = card[i];
    for (int j = 1; j <= i; j++) {
      dp[i] = min(dp[i], dp[i - j] + card[j]);
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