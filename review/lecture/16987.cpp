#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define S first
#define W second

int n;
pair<int, int> e[10];
int maxCnt = 0, cnt = 0;

void bt(int x) {
  if (x == n) {
    maxCnt = max(maxCnt, cnt);
    return;
  }

  if (e[x].S <= 0 || cnt == n - 1) {
    bt(x + 1);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (i == x || e[i].S <= 0) continue;
    e[x].S -= e[i].W;
    e[i].S -= e[x].W;
    cnt += e[x].S <= 0;
    cnt += e[i].S <= 0;
    bt(x + 1);
    cnt -= e[x].S <= 0;
    cnt -= e[i].S <= 0;
    e[x].S += e[i].W;
    e[i].S += e[x].W;
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    int s, w;
    cin >> s >> w;
    e[i] = {s, w};
  }

  bt(0);
  cout << maxCnt;
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