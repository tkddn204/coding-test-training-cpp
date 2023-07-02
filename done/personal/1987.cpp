#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int r, c;
string board[21];
bool vst[21][21];
bool ap[27];
int maxdist = 0;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void go(int x, int y, int dist) {
  if (dist > maxdist) maxdist = dist;

  for (int d = 0; d < 4; d++) {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
    int na = board[nx][ny] - 'A';
    if (vst[nx][ny] || ap[na]) continue;
    vst[nx][ny] = true;
    ap[na] = true;
    go(nx, ny, dist + 1);
    vst[nx][ny] = false;
    ap[na] = false;
  }
}

void solve() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) {
    cin >> board[i];
  }
  vst[0][0] = true;
  ap[board[0][0] - 'A'] = true;
  go(0, 0, 1);
  cout << maxdist;
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