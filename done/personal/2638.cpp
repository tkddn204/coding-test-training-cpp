#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int paper[101][101];
int chk[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

bool isEmpty() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (paper[i][j]) {
        return false;
      }
    }
  }
  return true;
}

void dbg() {
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cout << chk[i][j] << ' ';
      }
      cout << endl;
    }
    cout << "-------------------" << endl;
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> paper[i][j];
    }
  }
  int time = 0;
  while (!isEmpty()) {
    time++;

    // 외부공기 찾기
    for (int i = 0; i < n; i++) {
      fill(chk[i], chk[i] + m, 0);
    }
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    chk[0][0] = -1;
    while (!Q.empty()) {
      int x, y;
      tie(x, y) = Q.front(); Q.pop();
      
      for (int k = 0; k < 4; k++) {
        int nx = x + dx[k];
        int ny = y + dy[k];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        if (chk[nx][ny] || paper[nx][ny]) continue;
        Q.push({nx, ny});
        chk[nx][ny] = -1;
      }
    }

    // 외부공기에 2면 이상 닿으면 체크(1)
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        if (!paper[i][j]) continue;
        int c = 0;
        for (int k = 0; k < 4; k++) {
          int nx = i + dx[k];
          int ny = j + dy[k];
          c += chk[nx][ny] == -1;
        }
        if (c >= 2) chk[i][j] = 1;
      }
    }
    
    //dbg();

    // 체크(1)된 부분 제거
    for (int i = 1; i < n - 1; i++) {
      for (int j = 1; j < m - 1; j++) {
        if (chk[i][j] == 1) paper[i][j] = 0;
      }
    }
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