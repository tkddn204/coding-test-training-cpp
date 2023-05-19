#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

// H, n, m
int box[102][102][102];
int vst[102][102][102];
int dh[2] = {-1, 1};
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<tuple<int, int, int>> Q;

void solve() {
  int m, n, h;
  cin >> m >> n >> h;

  for (int i = 0 ; i < h; i++) {
    for (int j = 0 ; j < n; j++) {
      for (int k = 0 ; k < m; k++) {
        cin >> box[i][j][k];
        if (box[i][j][k] == 1) {
          Q.push({i, j, k});
        } else if (box[i][j][k] == 0) {
          vst[i][j][k] = -1;
        }
      }
    }
  }

  while(!Q.empty()) {
    tuple<int, int, int> cur = Q.front(); Q.pop();
    
    for (int i = 0 ; i < 2; i++) {
      int nh = get<0>(cur) + dh[i];
      int nx = get<1>(cur);
      int ny = get<2>(cur);
      if (nh < 0 || nh > h) continue;
      if (vst[nh][nx][ny] >= 0 || box[nh][nx][ny] == -1) continue;
      vst[nh][nx][ny] = vst[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
      Q.push({nh, nx, ny});
    }
    for (int j = 0 ; j < 4; j++) {
      int nh = get<0>(cur);
      int nx = get<1>(cur) + dx[j];
      int ny = get<2>(cur) + dy[j];
      if (nx < 0 || nx > n || ny < 0 || ny > m) continue;
      if (vst[nh][nx][ny] >= 0 || box[nh][nx][ny] == -1) continue;
      vst[nh][nx][ny] = vst[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
      Q.push({nh, nx, ny});
    }
  }

  int mDay = 0;
  bool notRipe = false;
  for (int i = 0 ; i < h; i++) {
    for (int j = 0 ; j < n; j++) {
      for (int k = 0 ; k < m; k++) { 
        if (vst[i][j][k] == -1) notRipe = true;
        else mDay = max(mDay, vst[i][j][k]);
      }
    }
  }
  if (notRipe) cout << -1;
  else cout << mDay;
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