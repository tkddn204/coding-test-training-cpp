#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MX = 1000001;
int n, m;
int a[MX], b[MX], c[MX + MX];

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < m; i++) cin >> b[i];

  int ai = 0, bi = 0;
  for (int i = 0 ; i < n+m; i++) {
    if (ai == n) c[i] = b[bi++];
    else if (bi == m) c[i] = a[ai++];
    else if (a[ai] <= b[bi]) c[i] = a[ai++];
    else c[i] = b[bi++];
  }
  for (int i = 0; i < n + m; i++) {
    cout << c[i] << " ";
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