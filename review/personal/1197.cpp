#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int v, e;
vector<tuple<int, int, int>> edges;
int parent[10001];

int find(int x) {
  if (parent[x] == x) return x;
  return parent[x] = find(parent[x]);
}

void uni(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) parent[y] = x; 
}

void solve() {
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    edges.push_back({c, a, b});
    edges.push_back({c, b, a});
  }
  sort(edges.begin(), edges.end());
  for (int i = 1; i <= v; i++) parent[i] = i;

  int res = 0;
  for (auto [w, a, b] : edges) {
    if (find(a) != find(b)) {
      uni(a, b);
      res += w;
    }
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