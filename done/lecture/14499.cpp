#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, x, y, k;
int dice[7];
int mp[21][21];

// 0: 1 2 3 4 5 6
// 1(e): 4 2 1 6 5 3
// 2(w): 3 2 6 1 5 4
// 3(n): 5 1 3 4 6 2
// 4(s): 2 6 3 4 1 5
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int cmd[5][7] = {{0, 1, 2, 3, 4, 5, 6},
                 {0, 4, 2, 1, 6, 5, 3},
                 {0, 3, 2, 6, 1, 5, 4},
                 {0, 5, 1, 3, 4, 6, 2},
                 {0, 2, 6, 3, 4, 1, 5}};

void DBG() {
  cout << dice[1] << " [ ";
  for (int i = 1; i <= 6; i++) {
    cout << dice[i] << ' ';
  }
  cout << "] // " << x << ',' << y << endl;
}

void solve() {
  cin >> n >> m >> x >> y >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mp[i][j];
    }
  }
  while (k--) {
    int c;
    cin >> c;
    int nx = x + dx[c];
    int ny = y + dy[c];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    int ndice[7];
    for (int i = 1; i <= 6; i++) {
      ndice[i] = dice[cmd[c][i]];
    }
    for (int i = 1; i <= 6; i++) {
      dice[i] = ndice[i];
    }
    if (mp[nx][ny] == 0) {
      mp[nx][ny] = dice[6];
    } else {
      dice[6] = mp[nx][ny];
      mp[nx][ny] = 0;
    }
    x = nx, y = ny;
    cout << dice[1] << endl;
    // DBG();
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