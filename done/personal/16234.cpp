#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, l, r;
int a[51][51];
int gate[51][51];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool openGate() {
  bool open = false;

  int num = 1;
  for (int i = 0; i < n; i++)
    fill(gate[i], gate[i] + n, 0);

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (gate[i][j]) continue;
      queue<pair<int, int>> Q;

      Q.push({i, j});
      gate[i][j] = num;

      while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];
          if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
          if (gate[nx][ny]) continue;
          int diff = abs(a[x][y] - a[nx][ny]);
          if (diff < l || diff > r) continue;
          
          open = true;
          Q.push({nx, ny});
          gate[nx][ny] = num;
        }
      }
      num++;
    }
  }

  return open;
}

void move() {
  int nums[2501] = {};
  int cnts[2501] = {};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int g = gate[i][j];
      nums[g] += a[i][j];
      cnts[g]++;
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int g = gate[i][j];
      a[i][j] = nums[g] / cnts[g];
    }
  }  
}

void solve() {
  cin >> n >> l >> r;
  for (int i = 0; i < n; i++) { 
    for (int j = 0 ; j < n; j++) {
      cin >> a[i][j];      
    }
  }

  int time = 0;
  while (openGate()) {
    move();
    time++;
  }

  cout << time;
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