#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int n, m;
int arr[1001][1001];
int dis[1001][1001];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
  cin >> n >> m;
  pair<int, int> start;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 2) start = make_pair(i, j);
    }
  }

  queue<pair<int, int>> Q;
  Q.push(start);
  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();

    for (int i = 0; i < 4; i++) {
      int nx = cur.X + dx[i];
      int ny = cur.Y + dy[i];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (arr[nx][ny] == 0 || arr[nx][ny] == 2) continue;
      if (dis[nx][ny]) continue;
      dis[nx][ny] = dis[cur.X][cur.Y] + 1;
      Q.push({nx, ny});
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int o;
      if (arr[i][j] == 1 && dis[i][j] == 0) {
        o = -1;
      } else {
        o = dis[i][j];
      }
      cout << o << ' ';
    }
    cout << endl;
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