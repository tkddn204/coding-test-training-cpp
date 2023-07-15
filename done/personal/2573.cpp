#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int mp[301][301];
int vst[301][301];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isMelted() {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cnt += mp[i][j];
    }
  }
  return cnt > 0;
}

void meltIce() {
  int tmp[301][301];
  for (int i = 0; i < n; i++)
    fill(tmp[i], tmp[i] + m, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mp[i][j] == 0) continue;
      for (int d = 0; d < 4; d++) {
        int nx = i + dx[d];
        int ny = j + dy[d];
        if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
        tmp[i][j] += mp[nx][ny] == 0;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      mp[i][j] -= tmp[i][j];
      if (mp[i][j] < 0) mp[i][j] = 0;
      // cout << mp[i][j] << ' ';
    }
    // cout << endl;
  }
  // cout << "----------------" << endl;
}

int countIce() {
  for (int i = 0; i < n; i++)
    fill(vst[i], vst[i] + m, 0);

  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (vst[i][j] > 0 or mp[i][j] == 0) continue;
      queue<pair<int, int>> Q;

      cnt++;
      Q.push({i, j});
      vst[i][j] = cnt;
      while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();

        for(int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];
          
          if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
          if (vst[nx][ny] > 0 or mp[nx][ny] == 0) continue;
          Q.push({nx, ny});
          vst[nx][ny] = cnt;
        }
      }
    }
  }
  return cnt;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mp[i][j];
    }
  }

  int time = 1;
  while (isMelted()) {
    meltIce();
    int cnt = countIce();
    if (cnt >= 2) {
      cout << time;
      return;
    }
    time++;
  }
  cout << 0;
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