#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, x;
int town[2][1001][1001];
int dist[2][1001];

void dstra(int v) {
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  fill(dist[v] + 1, dist[v] + n + 1, INT_MAX);
  pq.push({x, 0});
  dist[v][x] = 0;

  while (!pq.empty()) {
    int t, d;
    tie(t, d) = pq.top(); pq.pop();

    if (dist[v][t] < d) continue;
    for (int k = 1; k <= n; k++) {
      if (!town[v][t][k]) continue;
      int nd = d + town[v][t][k];
      if (dist[v][k] < nd) continue;
      pq.push({k, nd});
      dist[v][k] = nd;
    }
  }
}

void solve() {
  cin >> n >> m >> x;
  for (int i = 0; i < m; i++) {
    int a, b, t;
    cin >> a >> b >> t;
    town[0][a][b] = t;
    town[1][b][a] = t;
  }
  dstra(0);
  dstra(1);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    res = max(res, dist[0][i] + dist[1][i]);
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