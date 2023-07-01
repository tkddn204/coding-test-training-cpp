#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int n, m;
string pan[51];
bool vst[51][51];
int sx, sy;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void existCycle(int x, int y, int d) {
  vst[x][y] = true;
  for (int k = 0; k < 4; k++) {
    int nx = x + dx[k];   
    int ny = y + dy[k];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
    if (pan[x][y] != pan[nx][ny]) continue;
    if (sx == nx && sy == ny && d >= 4) {
      cout << "Yes" << endl;
      exit(0);
    }
    if (vst[nx][ny]) continue;
    existCycle(nx, ny, d + 1);
  }
  vst[x][y] = false;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> pan[i];
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0 ; j < m; j++) {
      if (vst[i][j]) continue;
      sx = i, sy = j;
      existCycle(i, j, 1);
      vst[i][j] = true;
    }
  }
  cout << "No" << endl;
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