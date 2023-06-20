#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

bool vst[100002];

void solve() {
  int n, k;
  cin >> n >> k;

  deque<pair<int, int>> Q;
  Q.push_back({n, 0});
  int mint = INT_MAX;
  while (!Q.empty()) {
    int idx, t;
    tie(idx, t) = Q.back(); Q.pop_back();
    vst[idx] = true;

    if (idx == k) {
      mint = min(mint, t);
      break;
    }

    int nxt[3] = {idx + 1, idx - 1, idx * 2};
    for (int i = 0; i < 2; i++) {
      if (nxt[i] < 0 || nxt[i] > 100000) continue;
      if (vst[nxt[i]]) continue;
      Q.push_front({nxt[i], t + 1});
    }
    if (nxt[2] < 0 || nxt[2] > 100000) continue;
    if (vst[nxt[2]]) continue;
    Q.push_back({nxt[2], t});

  }
  cout << mint << endl;
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