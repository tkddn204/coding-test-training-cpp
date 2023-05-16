#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
vector<int> tree[100001];
int p[100001];

void dfs(int cur) {
  for (int nxt : tree[cur]) {
    if (p[cur] == nxt) continue;
    p[nxt] = cur;
    dfs(nxt);
  }
}

void solve() {
  cin >> n;

  for (int i = 0 ; i < n - 1; i++) {
    int a, b;
    cin >> a >> b;
    tree[a].push_back(b);
    tree[b].push_back(a);
  }
  dfs(1);
  for (int i = 2; i <= n; i++) cout << p[i] << endl;
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