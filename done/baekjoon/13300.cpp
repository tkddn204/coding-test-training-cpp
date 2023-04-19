#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int)1e9

void solve() {
  int n, k, s, y, arr[7][2];
  int res = 0;
  for (int i = 0 ; i < 7; ++i)
    fill(arr[i], arr[i]+2, 0);
  cin >> n >> k;
  for (int i = 0 ; i < n; i++) {
    cin >> s >> y;
    ++arr[y][s];
    if (arr[y][s] % k == 0) {
      res++;
      arr[y][s] = 0;
    }
  }

  for (int i = 1 ; i < 7; ++i) {
    if (arr[i][0]) ++res;
    if (arr[i][1]) ++res;
  }
  cout << res;
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