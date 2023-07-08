#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[1002];
int dp[2][1002];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> arr[i];
  }
  fill(dp[0] + 1, dp[0] + n + 1, 1);
  fill(dp[1] + 1, dp[1] + n + 1, 1);

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j < i; j++) {
      if (arr[j] < arr[i]) {
        dp[0][i] = max(dp[0][i], dp[0][j] + 1);
      }
    }
  }
  for (int i = n; i >= 0; i--) {
    for (int j = n; j > i; j--) {
      if (arr[j] < arr[i]) {
        dp[1][i] = max(dp[1][i], dp[1][j] + 1);
      }
    }
  }

  int maxVal = 0;
  for (int i = 1; i <= n; i++) {
    maxVal = max(maxVal, dp[0][i] + dp[1][i] - 1);
  }
  cout << maxVal;
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