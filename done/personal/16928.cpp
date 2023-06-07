#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int ld[101];
int dis[101];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n + m; i++) {
    int x, y;
    cin >> x >> y;
    if (y > 100 || y < 1) continue;
    ld[x] = y;
  }
  queue<int> Q;
  fill(dis, dis + 101, -1);

  Q.push(1);
  dis[1] = 0;
  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    if (cur == 100) break;

    for (int k = 1; k <= 6; k++) {
      int nxt = cur + k;
      if (nxt > 100) continue;
      while (ld[nxt]) nxt = ld[nxt];
      if (dis[nxt] > -1) continue;
      Q.push(nxt);
      dis[nxt] = dis[cur] + 1;
    }
  }

  // for (int i = 1; i < 101; i++) {
  //   cout << dis[i] << " ";
  //   if (i % 10 == 0) cout << endl;
  // }
  cout << dis[100];
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