#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int parent[1000001];

int get(int x) {
  if (parent[x] == x) return x;
  return parent[x] = get(parent[x]);
}

void uni(int a, int b) {
  a = get(a);
  b = get(b);
  if (a != b) parent[a] = b;
}
void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) parent[i] = i;
  while (m--) {
    int op, a, b;
    cin >> op >> a >> b;
    if (op) {
      if (get(a) == get(b)) cout << "YES" << endl;
      else cout << "NO" << endl;
    } else {
      uni(a, b);
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