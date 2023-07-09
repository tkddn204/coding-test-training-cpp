#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

vector<pair<int, int>> p;

void solve() {
  int x, y;
  for (int i = 0; i < 3; i++) {
    cin >> x >> y;
    p.push_back({x, y});
  }

  int dxab = p[1].X - p[0].X;
  int dyab = p[1].Y - p[0].Y;
  int dxac = p[2].X - p[0].X;
  int dyac = p[2].Y - p[0].Y;

  int k = dxab * dyac - dxac * dyab;

  if (k > 0) cout << 1;
  else if (k < 0) cout << -1;
  else cout << 0;
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