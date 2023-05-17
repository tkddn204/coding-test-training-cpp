#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int INF = 100000000;
int dist[101][101];
int nxt[101][101];

void solve() {
  int n, m, a, b, c;
  cin >> n >> m;
  for (int i = 1 ; i <= n; i++) {
    fill(dist[i] + 1, dist[i] + n + 1, INF);
    dist[i][i] = 0;
  }
  for (int i = 0; i < m + 2; i++) {
    cin >> a >> b >> c;
    dist[a][b] = min(dist[a][b], c);
    nxt[a][b] = b;
  }
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dist[i][j] > dist[i][k] + dist[k][j]) {
          dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] == INF) cout << '0' << " ";
      else cout << dist[i][j] << " ";
    }
    cout << endl;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      if (dist[i][j] == 0 || dist[i][j] == INF) {
        cout << '0' << endl;
        continue;
      }
      vector<int> path;
      int st = i;
      while(st != j) {
        path.push_back(st);
        st = nxt[st][j];
      }
      path.push_back(j);
      cout << path.size() << " ";
      for (auto x : path) cout << x << " ";
      cout << endl;
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