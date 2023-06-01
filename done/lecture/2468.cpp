#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int n;
int arr[102][102];
bool vst[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
  int ml = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      ml = max(ml, arr[i][j]);
    }
  }

  int res = 0;
  for (int l = 0; l <= ml; l++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        vst[i][j] = arr[i][j] <= l;
      }
    }
    int h = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (vst[i][j]) continue;
        queue<pair<int, int>> Q;
        Q.push({i, j});
        vst[i][j] = true;

        while (!Q.empty()) {
          pair<int, int> cur = Q.front();
          Q.pop();

          for (int d = 0; d < 4; d++) {
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];
            if (nx < 0 || nx > n || ny < 0 || ny > n) continue;
            if (vst[nx][ny]) continue;
            Q.push({nx, ny});
            vst[nx][ny] = true;
          }
        }
        h++;
      }
    }
    res = max(res, h);
  }
  cout << res;
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