#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define x first
#define y second

bool v[502][502];
int dx[4] = {1, 0 , -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
  int n, m;
  queue<pair<int, int>> q;
  int p[502][502];

  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> p[i][j];
    }
  }

  int num = 0, ma = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (v[i][j] || !p[i][j]) continue;
      
      int area = 0;
      v[i][j] = true;
      q.push({i, j});
      while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();
        if (!p[cur.x][cur.y]) continue;
        ++area;
        for (int nxt = 0; nxt < 4; ++nxt) {
          int nx = cur.x + dx[nxt];
          int ny = cur.y + dy[nxt];
          if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
          if (v[nx][ny] || !p[nx][ny]) continue;
          v[nx][ny] = true;
          q.push({nx, ny});
        }
      }
      ma = max(ma, area);
      if (area) num++;
    }
  }
  cout << num << endl << ma;
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