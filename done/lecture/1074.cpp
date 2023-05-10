#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int rec(int n, int r, int c) {
  if (n == 0) return 0;
  int next = n - 1;
  int half = pow(2, next);
  if (r < half && c < half) return rec(next, r, c);
  if (r < half && c >= half) return half*half + rec(next, r, c-half);
  if (r >= half && c < half) return 2*half*half + rec(next, r-half, c);
  return 3*half*half + rec(next, r-half, c-half);
}

void solve() {
  int n, r, c;
  cin >> n >> r >> c;
  cout << rec(n, r, c);
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