#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

pair<int, int> room[100001];

void solve() {
  int n, x, y;
  cin >> n;
  for (int i = 0 ; i < n; i++) {
    cin >> x >> y;
    room[i].X = y; room[i].Y = x;
  }

  sort(room, room + n);
  
  int res = 0, t = 0;
  for (int i = 0 ; i < n; i++) {
    if (t > room[i].Y) continue;
    res++;
    t = room[i].X;
  }

  cout << res;
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