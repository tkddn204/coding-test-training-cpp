#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define x first
#define y second

int vst[102][102];
int miro[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
  queue<pair<int, int>> q;
  int n, m;
  string inp;
  cin >> n >> m;
  
  for (int i = 0; i < n; i++) {
    cin >> inp;
    for (int j = 0; j < m; j++) {
      miro[i][j] = inp[j] - '0';
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vst[i][j] || !miro[i][j]) continue;

      vst[i][j] = 1;
      q.push({i, j});
      while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int k = 0 ; k < 4; k++) {
          int nx = cur.x + dx[k];
          int ny = cur.y + dy[k];

          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (vst[nx][ny] || !miro[nx][ny]) continue;
          vst[nx][ny] = vst[cur.x][cur.y] + 1;
          q.push({nx, ny});
        }
      }
    }
  }
  
  cout << vst[n - 1][m - 1];
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