#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define pdd pair<long double, long double>
#define X first
#define Y second

int n;
pdd points[10001];

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    long double x, y;
    cin >> x >> y;
    points[i] = {x, y};
  }

  pdd s = points[0];
  long double ret = 0;

  // |↘↘↘ - ↙↙↙| / 2
  for (int i = 1; i < n - 1; i++) {
    pdd a = points[i], b = points[i + 1];
    ret += (((s.X * a.Y) + (a.X * b.Y) + (b.X * s.Y))
          - ((a.X * s.Y) + (b.X * a.Y) + (s.X * b.Y)));
  }

  cout.precision(1);
  cout << fixed << abs(ret) / 2;
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