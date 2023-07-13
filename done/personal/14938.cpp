#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int, int>> graph[102];
int vst[102];
int dist[102];
int item[102];

void solve() {
  int n, m, r;
  cin >> n >> m >> r;
  for (int i = 1; i <= n; i++) {
    cin >> item[i];        
  }
  
  for (int i = 0; i < r; i++) {
    int a, b, l;
    cin >> a >> b >> l;
    graph[a].push_back({l, b});
    graph[b].push_back({l, a});
  }

  int maxCnt = 0;
  for (int i = 1; i <= n; i++) {
    fill(vst, vst + n + 1, 0);
    fill(dist, dist + n + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, i});
    dist[i] = 0;
    while (!pq.empty()) {
      auto [w, x] = pq.top(); pq.pop();

      if (vst[x]) continue;
      vst[x] = true;

      for (auto [nw, nx] : graph[x]) {
        if (nw + w > dist[nx]) continue;
        dist[nx] = nw + w;
        pq.push({dist[nx], nx});
      }
    }
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (dist[j] <= m) cnt += item[j];
    }
    maxCnt = max(maxCnt, cnt);
  }
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