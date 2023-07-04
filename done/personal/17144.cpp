#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int r, c;
int mp[51][51];
vector<pair<int, int>> air;
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1 ,0};

void printMap(string label) {
  if (!label.empty()) cout << label << endl;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << mp[i][j] << ' ';
    }
    cout << endl;
  }
  cout << "-------------------" << endl;
}

void spread() {
  int nxt[51][51];
  for (int i = 0; i < r; i++) {
    fill(nxt[i], nxt[i] + c, 0);
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      if (mp[i][j] <= 0) continue;
      int val = mp[i][j];
      for (int k = 0; k < 4; k++) {
        int nx = i + dx[k];
        int ny = j + dy[k];
        if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
        if (mp[nx][ny] == -1) continue;
        nxt[nx][ny] += val / 5;
        mp[i][j] -= val / 5;
      }
    }
  }
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      mp[i][j] += nxt[i][j];
    }
  }
}

void fresh() {
  int ax, ay;

  // 위쪽
  tie(ax, ay) = air[0];
  int cx = ax, cy = ay, d = 0;
  int nv = 0;
  while (true) {
    int nx = cx + dx[d];
    int ny = cy + dy[d];
    if (nx == ax and ny == ay) break;
    if (nx < 0 or nx > ax or ny < 0 or ny >= c) {
      d++;
      continue;
    }
    int nxt = mp[nx][ny];
    mp[nx][ny] = nv;
    nv = nxt;
    cx = nx, cy = ny;
  }
  // printMap("위쪽");
  // 아래쪽
  tie(ax, ay) = air[1];
  cx = ax, cy = ay, d = 0;
  nv = 0;
  while (true) {
    int nx = cx + dx[d];
    int ny = cy + dy[d];
    if (nx == ax and ny == ay) break;
    if (nx < ax or nx >= r or ny < 0 or ny >= c) {
      d = d == 0 ? 3 : d - 1;
      continue;
    }
    int nxt = mp[nx][ny];
    mp[nx][ny] = nv;
    nv = nxt;
    cx = nx, cy = ny;
  }
  // printMap("아래쪽");
}

void solve() {
  int t;
  cin >> r >> c >> t;

  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == -1) air.push_back({i, j});
    }
  }

  while (t--) {
    spread();
    fresh();
  }
  int sum = 0;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      sum += mp[i][j] > 0 ? mp[i][j] : 0;
    }
  }
  cout << sum;
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