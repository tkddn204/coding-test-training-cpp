#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second

char arr[100][100];
bool vst[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
  int n, a = 0, b = 0;
  string s;
  queue<pair<int, int>> q;

  cin >> n;
  for (int i = 0 ; i < n; i++) {
    cin >> s;
    for (int j = 0 ; j < n; j++) {
      arr[i][j] = s[j];
    }
  }
  
  for (int i = 0 ; i < n; i++) {
    for (int j = 0 ; j < n; j++) {
      if (vst[i][j]) continue;

      q.push({i, j});
      vst[i][j] = true;
      while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0 ; i < 4; ++i) {
          int nx = cur.x + dx[i];
          int ny = cur.y + dy[i];
          
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (vst[nx][ny] || arr[cur.x][cur.y] != arr[nx][ny]) continue;
          q.push({nx, ny});
          vst[nx][ny] = true;
        }
      }
      a++;
    }
  }
  
  for (int i = 0 ; i < n; i++) {
    fill(vst[i], vst[i] + n, false);
  }

  for (int i = 0 ; i < n; i++) {
    for (int j = 0 ; j < n; j++) {
      if (vst[i][j]) continue;

      q.push({i, j});
      vst[i][j] = true;
      while (!q.empty()) {
        pair<int, int> cur = q.front(); q.pop();

        for (int i = 0 ; i < 4; ++i) {
          int nx = cur.x + dx[i];
          int ny = cur.y + dy[i];
          
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (vst[nx][ny]) continue;
          if ((arr[cur.x][cur.y] == 'R' || arr[cur.x][cur.y] == 'G')
            && arr[nx][ny] == 'B') continue;
          if (arr[cur.x][cur.y] == 'B' && (arr[nx][ny] == 'R' || arr[nx][ny] == 'G')) continue;
          q.push({nx, ny});
          vst[nx][ny] = true;
        }
      }
      b++;
    }
  }
  cout << a << " " << b;
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