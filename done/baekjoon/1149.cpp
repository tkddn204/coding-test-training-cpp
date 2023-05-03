#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int mx = 1001;
int dp[mx][3];
int arr[mx][3];
void solve() {
  int n;
  cin >> n;
  
  for (int i = 1 ; i <= n ; i++) {
    cin >> arr[i][0] >> arr[i][1] >> arr[i][2];    
  }

  for (int i = 0 ; i < 3 ; i++) dp[1][i] = arr[1][i];

  for (int i = 2; i <= n; i++) {
    dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + arr[i][0];
    dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + arr[i][1];
    dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + arr[i][2];
    // cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
  }
  cout << min(min(dp[n][0], dp[n][1]), dp[n][2]);
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