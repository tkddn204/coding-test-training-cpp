#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

deque<pair<int, int>> dq;

void solve() {
  int n, l, e;
  cin >> n >> l;

  for (int i = 0 ; i < n; i++) {
    cin >> e;

    while (!dq.empty() && dq.back().second >= e) dq.pop_back();
    dq.push_back({i, e});
    if (dq.front().first <= i - l) dq.pop_front();

    cout << dq.front().second << " ";
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