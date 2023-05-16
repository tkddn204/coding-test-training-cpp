#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, v;
int graph[1001][1001];
bool vst[1001];

void dfs(int cur) {
  vst[cur] = true;
  cout << cur << " ";
  for (int i = 1 ; i <= n ; i++) {
    if (!graph[cur][i]) continue;
    if (vst[i]) continue;
    dfs(i);
  }
}

void solve() {
  cin >> n >> m >> v;
  
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }

  dfs(v);
  cout << endl;
  
  fill(vst + 1, vst + n + 1, false);
  queue<int> q;
  q.push(v);
  vst[v] = true;
  while (!q.empty()) {
    int cur = q.front(); q.pop();
    vst[cur] = true;
    cout << cur << " ";
    for (int i = 1 ; i <= n; i++) {
      if (!graph[cur][i]) continue;
      if (vst[i]) continue;
      q.push(i);
      vst[i] = true;
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