#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int, int>> tree[100001];
bool vst[100001];

int maxNode = 1;
int maxRange = 0;
void dfs(int x, int d) {
  if (vst[x]) return;
  
  if (maxRange < d) {
    maxNode = x;
    maxRange = d;
  }
  vst[x] = true;
  
  for (auto k : tree[x]) {
    int nx, nd;
    tie(nx, nd) = k;
    if (vst[nx]) continue;
    dfs(nx, d + nd);
  }
}

void solve() {
  int v;
  cin >> v;
  for (int i = 0; i < v; i++) {
    int n, a, d;
    cin >> n;
    while (true) {
      cin >> a;
      if (a == -1) break;
      cin >> d;
      tree[n].push_back({a, d});
    }
  }

  dfs(1, 0);
  fill(vst + 1, vst + v + 1, false);
  dfs(maxNode, 0);

  cout << maxRange;
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