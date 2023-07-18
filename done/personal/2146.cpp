#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int mp[101][101];
int vst[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
int minLen = INT_MAX;

void printMap() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      char k;
      if (vst[i][j] == -1) k = '-';
      else k = vst[i][j] + '0';
      cout << k << ' ';
    }
    cout << endl;
  }
  cout << "---------------------" << endl;
}

void checkBridge(int i, int j) {
  int num = mp[i][j];
  queue<pair<int, int>> Q;
  Q.push({i, j});
  vst[i][j] = 0;
  while (!Q.empty()) {
    auto [x, y] = Q.front(); Q.pop();
    
    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
      if (mp[nx][ny] == num or vst[nx][ny] >= 0) continue;
      if (mp[nx][ny] != 0) {
        minLen = min(minLen, vst[x][y]);
        printMap();
        return;
      }
      Q.push({nx, ny});
      vst[nx][ny] = vst[x][y] + 1;
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mp[i][j];
    }
  }

  // 대륙마다 숫자로 표시해주기
  int num = 1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (vst[i][j] > 0 or mp[i][j] == 0) continue;
      queue<pair<int, int>> Q;
      Q.push({i, j});
      vst[i][j] = num;
      while(!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();

        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];
          if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
          if (vst[nx][ny] or mp[nx][ny] == 0) continue;
          Q.push({nx, ny});
          vst[nx][ny] = num;
        }
      }
      num++;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mp[i][j] = vst[i][j];
    }
  }

  // 다리길이 재기
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (mp[i][j] == 0) continue;
      for (int k = 0; k < n; k++)
        fill(vst[k], vst[k] + n, -1);
      checkBridge(i, j);
    }
  }
  cout << minLen;
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