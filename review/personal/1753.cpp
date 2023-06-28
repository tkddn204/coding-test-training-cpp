#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int, int>> graph[20001];
int dist[20001];

void wCheck(int a, int b, int w) {
  for (pair<int, int>& e : graph[a]) {
    int ex, ew;
    tie (ex, ew) = e;
    if (ex == b and ew > w) {
      e = {b, w};
      return;
    }
  }
}

void solve() {
  int v, e, k;
  cin >> v >> e >> k;
  for (int i = 0; i < e; i++) {
    int a, b, w;
    cin >> a >> b >> w;
    //wCheck(a, b, w);
    graph[a].push_back({w, b});
  }

  fill (dist + 1, dist + v + 1, INT_MAX);

  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
  pq.push({0, k});
  dist[k] = 0;
  while (!pq.empty()) {
    int d, x;
    tie(d, x) = pq.top(); pq.pop();

    if (dist[x] < d) continue;
    for (auto k : graph[x]) {
      int nd, nx;
      tie(nd, nx) = k;
      int sd = nd + d;
      if (dist[nx] < sd) continue;
      pq.push({sd, nx});
      dist[nx] = sd;
    }
  }
  for (int i = 1; i <= v; i++) {
    if (dist[i] == INT_MAX) {
      cout << "INF" << endl;
    } else {
      cout << dist[i] << endl;
    }
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