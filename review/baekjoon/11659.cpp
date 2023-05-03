#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int mx = 1000001;
int dp[mx];
int cnt[mx];
void solve() {
  int n;
  cin >> n;

  dp[1] = 0;
  cnt[1] = 0;
  for (int i = 2; i <= n; i++) {
    dp[i] = dp[i - 1] + 1;
    cnt[i] = i - 1;
    if (i % 2 == 0 && dp[i] > dp[i / 2] + 1) {
      dp[i] = dp[i / 2] + 1;
      cnt[i] = i / 2;
    }
    if (i % 3 == 0 && dp[i] > dp[i / 3] + 1) {
      dp[i] = dp[i / 3] + 1;
      cnt[i] = i / 3;
    }
  }
  cout << dp[n] << endl;
  
  int cur = n;
  while (cur >= 1) {
    cout << cur << " ";
    cur = cnt[cur];
  }
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