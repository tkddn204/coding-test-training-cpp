#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  stack<pair<int, int>> s;
  int n, e;
  cin >> n;
  s.push({0, 1000000001});
  for (int i = 1; i <= n; i++) {
    cin >> e;
    while (s.top().second < e) s.pop();
    cout << s.top().first << " ";
    s.push({i, e});
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