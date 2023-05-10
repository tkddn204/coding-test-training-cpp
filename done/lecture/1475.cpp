#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int)1e9

void solve() {
  int n, ans = 1, arr[10] = {0};

  cin >> n;
  while(n) {
    ++arr[n % 10];
    n /= 10;
  }
  for (int i = 0 ; i < 10; ++i ) {
    if (i == 6 || i == 9) continue;
    ans = max(ans, arr[i]);
  }
  ans = max(ans, (arr[6] + arr[9] + 1) / 2);

  cout << ans;
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