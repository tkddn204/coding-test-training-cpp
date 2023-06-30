// 그래프 배열을 벡터로 풀면 틀리는데
// 일반 배열이나 pair로 풀면 맞음
// 이유가 뭘까..

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, w;
pair<pair<int,int>, int> graph[5555];

bool BF() {
  int dis[501];
  fill(dis + 1, dis + n + 1, 1e8);
  dis[1] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      pair<int, int> k;
      int a, b, d;
      tie(k, d) = graph[j];
      tie(a, b) = k;
      if (dis[b] > dis[a] + d) {
        if (i == n) return true;
        dis[b] = dis[a] + d;
      }
    }
  }
  return false;
}

void solve() {
  int tc;
  cin >> tc;
  while (tc--) {
    cin >> n >> m >> w;

    int idx = 0;
    int s, e, t;
    while(m--) {
      cin >> s >> e >> t;
      graph[idx++] = {{s, e}, t};
      graph[idx++] = {{e, s}, t};
    }
    while (w--) {
      cin >> s >> e >> t;
      graph[idx++] = {{s, e}, -t};
    }
    m = idx;
    if (BF()) cout << "YES" << endl;
    else cout << "NO" << endl;
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