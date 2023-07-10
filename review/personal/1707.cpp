#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> graph[20001];
int vst[20001];

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int v, e;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
      int u, v;
      cin >> u >> v;
      graph[u].push_back(v);
      graph[v].push_back(u);
    }

    for (int i = 1; i <= v; i++) {
      if (vst[i]) continue;

      queue<int> Q;
      Q.push(i);
      vst[i] = 1;
      while (!Q.empty()) {
        int cur = Q.front(); Q.pop();
        int color = vst[cur] == 1 ? 2 : 1;
        for (auto nxt : graph[cur]) {
          if (vst[nxt]) continue;
          vst[nxt] = color;
          Q.push(nxt);
        }
      }
    }

    bool isBi = true;
    for (int i = 1; i <= v; i++) {
      for (auto nxt: graph[i]) {
        if (vst[i] == vst[nxt]) {
          isBi = false;
          break;
        }
      }
    }
    
    if (isBi) cout << "YES" << endl;
    else cout << "NO" << endl;

    for (int i = 0; i <= v; i++) {
      graph[i].shrink_to_fit();
      graph[i].clear();
      vst[i] = 0;
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