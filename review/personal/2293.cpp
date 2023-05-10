#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int dp[100001];

void solve() {
  int n, k;
  int arr[101] = {};
  cin >> n >> k;
  for (int i = 0; i < n; i++) cin >> arr[i];

  dp[0] = 1;
  for (int i = 0; i < n; i++) {
    for (int j = arr[i]; j <= k; j++) {
      dp[j] += dp[j - arr[i]];
    }
  }
  cout << dp[k];
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