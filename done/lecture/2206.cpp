#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int mp[1001][1001];
int vst[2][1001][1001];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < m; j++) {
      mp[i][j] = s[j] - '0';
    }
  }
  
  for (int k = 0; k < n; k++) {
    fill(vst[0][k], vst[0][k] + m, -1);
    fill(vst[1][k], vst[1][k] + m, -1);
  }
  
  queue<tuple<int, int, int>> Q;
  Q.push({0, 0, 0});
  vst[0][0][0] = 1;
  while (!Q.empty()) {
    int b, x, y;
    tie(b, x, y) = Q.front(); Q.pop();
    if (x == n - 1 && y == m - 1) break;
    for (int d = 0; d < 4; d++) {
      int nb = b;
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (vst[b][nx][ny] > -1) continue;
      if (b == 0 && mp[nx][ny]) nb = b + 1;
      else if (b == 1 && mp[nx][ny]) continue;
      Q.push({nb, nx, ny});
      vst[nb][nx][ny] = vst[b][x][y] + 1;
    }
  }

  // for (int f = 0; f < 2; f++) {
  //   for (int i = 0; i < n; i++) {
  //     for (int j = 0; j < m; j++) {
  //       cout << vst[f][i][j] << ' ';
  //     }
  //     cout << endl;
  //   }
  //   cout << "-----------------" << endl;
  // }

  
  int mxdis = max(vst[0][n - 1][m - 1], vst[1][n - 1][m - 1]);
  cout << mxdis;
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