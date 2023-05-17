#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int v, e;
tuple<int, int, int> edge[100001];
// (비용, 정점 1, 정점 2)
vector<int> p(10001, -1);

int find(int x) {
  if (p[x] < 0) return x;
  return p[x] = find(p[x]);
}

bool isDiffGroup(int u, int v) {
  u = find(u);
  v = find(v);
  if (u == v) return false;
  if (p[u] == p[v]) p[u]--;
  if (p[u] < p[v]) p[v] = u;
  else p[u] = v;
  return true;
}


void solve() {
  int cost, a, b;
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    cin >> a >> b >> cost;
    edge[i] = {cost, a, b};
  }
  sort(edge, edge + e);
  int cnt = 0, res = 0;
  for (int i = 0 ; i < e; i++) {
    tie(cost, a, b) = edge[i];
    if (!isDiffGroup(a, b)) continue;
    cnt++;
    res += cost;
    if (cnt == v - 1) break;
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