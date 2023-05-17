#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int paper[130][130];
int vst[130][130];
int w = 0, b = 0;

void check(int x, int y, int dv) {
  int count = 0;
  for (int i = x ; i < x + dv; i++) {
    for (int j = y ; j < y + dv; j++) {
      if (paper[i][j]) count++;
    }
  }

  if (!count) w++;
  else if (count == dv * dv) b++;
  else {
    check(x, y, dv / 2);
    check(x, y + dv / 2, dv / 2);
    check(x + dv / 2, y, dv / 2);
    check(x + dv / 2, y + dv / 2, dv / 2);
  }
}

void solve() {
  cin >> n;
  for (int i = 0 ; i < n; i++) {
    for (int j = 0 ; j < n; j++) {
      cin >> paper[i][j];
    }
  }
  check(0, 0, n);
  cout << w << endl;
  cout << b << endl;
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