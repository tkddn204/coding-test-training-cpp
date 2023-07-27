#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int parent[1000001];

int get(int x) {
  if (parent[x] == x) return x;
  return parent[x] = get(parent[x]);
}

void unionp(int a, int b) {
  a = get(a);
  b = get(b);
  if (a > b) parent[a] = b;
  else parent[b] = a;
}
bool findp(int a, int b) {
  return get(a) == get(b);
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) parent[i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      int k;
      cin >> k;
      if (k == 1) unionp(i, j);
    }
  }
  int a, b;
  cin >> a;
  while (m--) {
    cin >> b;
    if (!findp(a, b)) {
      cout << "NO" << endl;
      return;
    }
  }
  cout << "YES" << endl;
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