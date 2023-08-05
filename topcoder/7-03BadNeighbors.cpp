#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[51];

void solve() {
  vector<int> donations;
  int k;
  while (cin >> k) donations.push_back(k);
  
  int n = donations.size();
  int res;
  for (int i = 0; i < n - 1; i++) {
    dp[i] = donations[i];
    if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    if (i > 1) dp[i] = max(dp[i], dp[i - 2] + donations[i]);
    res = max(res, dp[i]);
  }

  for (int i = 1; i < n - 1; i++) {
    dp[i] = donations[i + 1];
    if (i > 0) dp[i] = max(dp[i], dp[i - 1]);
    if (i > 1) dp[i] = max(dp[i], dp[i - 2] + donations[i + 1]);
    res = max(res, dp[i]);
  }
  cout << res << endl;
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