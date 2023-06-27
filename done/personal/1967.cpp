#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<pair<int, int>> tree[100001];
int vst[100001];

int leaf = 1;
int range = 0;
void dfs(int x, int d) {
  if (range < d) {
    leaf = x;
    range = d;
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
  int n;
  cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int a, b, d;
    cin >> a >> b >> d;
    tree[a].push_back({b, d});
    tree[b].push_back({a, d});
  }

  dfs(1, 0);
  fill(vst + 1, vst + n + 1, false);
  dfs(leaf, 0);
  
  cout << range;
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