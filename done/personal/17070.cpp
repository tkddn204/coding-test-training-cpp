#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int home[17][17];
bool vst[17][17];
int cnt = 0;

void go(int x, int y, int d) {
  if (x == n - 1 and y == n - 1) {
    cnt++;
    return;
  }
  vector<tuple<int, int, int>> nxt;
  if (d == 0) { // 가로
    nxt.push_back({0, 1, 0});
  } else if (d == 1) { // 세로
    nxt.push_back({1, 0, 1});
  } else {
    nxt.push_back({0, 1, 0});
    nxt.push_back({1, 0, 1});
  }
  nxt.push_back({1, 1, 2});
  for (auto dk: nxt) {
    int dx, dy, nd;
    tie(dx, dy, nd) = dk;
    int nx = x + dx;
    int ny = y + dy;
    if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
    if (dx == 1 && dy == 1) { // 대각선
      if (home[nx][y] || vst[x][ny] || vst[nx][ny]) continue;
      if (home[nx][y] || home[x][ny] || home[nx][ny]) continue;
    } else {
      if (vst[nx][ny] || home[nx][ny]) continue;
    }
    vst[nx][ny] = true;
    go(nx, ny, nd);
    vst[nx][ny] = false;
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> home[i][j];
    }
  }

  if (home[n - 1][n - 1] == 1) {
    cout << 0;
    return;
  }
  vst[0][0] = vst[0][1] = true;
  go(0, 1, 0);
  cout << cnt;

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