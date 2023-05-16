#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int graph[1001][1001];
bool v[1001];


void solve() {
  int a, b;
  cin >> n >> m;
  for (int i = 0 ; i < m; i++) {
    cin >> a >> b;
    graph[a][b] = 1;
    graph[b][a] = 1;
  }
  
  int count = 0;
  for (int i = 1 ; i <= n; i++) {
    if (v[i]) continue;
    count++;
    queue<int> q;
    q.push(i);
    v[i] = true;
    while (!q.empty()) {
      int cur = q.front(); q.pop();
      for (int nxt = 0 ; nxt < 1001; nxt++) {
        if (!graph[cur][nxt]) continue;
        if (v[nxt]) continue;
        q.push(nxt);
        v[nxt] = true;
      }
    }
  }
  cout << count;
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