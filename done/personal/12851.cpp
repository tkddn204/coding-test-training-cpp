#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool vst[100002];

void solve() {
  int n, k;
  cin >> n >> k;

  queue<pair<int, int>> Q;
  Q.push({n, 0});
  int mint = INT_MAX, cnt = 0;
  while (!Q.empty()) {
    int idx, t;
    tie(idx, t) = Q.front(); Q.pop();
    vst[idx] = idx != k;

    if (mint < t) break;
    if (idx == k) {
      mint = t;
      cnt++;
      continue;
    }

    int nxt[3] = {idx + 1, idx - 1, idx * 2};
    for (int i = 0; i < 3; i++) {
      if (nxt[i] < 0 || nxt[i] > 100000) continue;
      if (vst[nxt[i]]) continue;
      Q.push({nxt[i], t + 1});
    }
  }
  cout << mint << endl;
  cout << cnt << endl;
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