#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int mx = 301;
int dp[mx][3];
int arr[mx];
void solve() {
  int n;
  cin >> n;
  for (int i = 1 ; i <= n; i++) cin >> arr[i];
  
  dp[1][1] = arr[1], dp[1][2] = 0;
  dp[2][1] = arr[2], dp[2][2] = arr[1] + arr[2];
  for (int i = 3; i <= n; i++) {
    dp[i][1] = max(dp[i-2][1], dp[i-2][2]) + arr[i];
    dp[i][2] = dp[i-1][1] + arr[i];
  }
  cout << max(dp[n][1], dp[n][2]);
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