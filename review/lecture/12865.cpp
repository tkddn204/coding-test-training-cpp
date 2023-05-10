#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

pair<int, int> arr[100001];
int dp[101][100001];

void solve() {
  int n, k, w, v;
  cin >> n >> k;
  
  for (int i = 1 ; i <= n; i++) {
    cin >> w >> v;
    arr[i].X = w; arr[i].Y = v;
  }

  for (int i = 1 ; i <= n; i++) {
    for (int j = 1 ; j <= k; j++) {
      if (j - arr[i].X >= 0) {
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - arr[i].X] + arr[i].Y);
      } else {
        dp[i][j] = dp[i - 1][j];
      }
    }
  }
  cout << dp[n][k];
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