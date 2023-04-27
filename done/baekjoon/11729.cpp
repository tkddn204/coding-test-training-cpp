#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void rec(int a, int b, int n) {
  if (n == 1) {
    cout << a << ' ' << b << endl;
    return;
  }

  rec(a, 6 - a - b, n - 1);
  cout << a << ' ' << b << endl;
  rec(6 - a - b, b, n - 1);
}

void solve() {
  int k;
  cin >> k;
  cout << (1 << k) - 1 << endl;
  rec(1, 3, k);
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