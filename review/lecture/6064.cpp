#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int gcd(int a, int b) {
  if (a == 0) return b;
  return gcd(b % a, a);
}

int lcm(int a, int b) {
  return a / gcd(a, b) * b;
}

void solve() {
  int t, m, n, x, y;
  cin >> t;
  while (t--) {
    cin >> m >> n >> x >> y;
    if (x == m) x = 0;
    if (y == n) y = 0;
    int l = lcm(m, n);
    int res = -1;
    for (int i = x; i <= l; i += m) {
      if (i == 0) continue;
      if (i % n == y) {
        res = i;
        break;
      }
    }
    cout << res << endl;
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