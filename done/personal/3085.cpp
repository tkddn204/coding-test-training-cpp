#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
string board[51];
string curboard[51];

int bomb(int x, int y, int a, int b) {
  for (int i = 0; i < n; i++) {
    curboard[i] = board[i];
  }
  int t = curboard[x][y];
  curboard[x][y] = curboard[a][b];
  curboard[a][b] = t;

  // for (int i = 0; i < n; i++) {
  //   cout << curboard[i] << endl;
  // }
  // cout << "-----------" << endl;

  int maxCnt = 0;
  // 가로
  for (int i = 0; i < n; i++) {
    int cnt = 1;
    char c = curboard[i][0];
    for (int j = 1; j < n; j++) {
      if (c != curboard[i][j]) {
        maxCnt = max(maxCnt, cnt);
        cnt = 1;
        c = curboard[i][j];
      } else {
        cnt++;
      }
    }
    maxCnt = max(maxCnt, cnt);
  }

  // 세로
  for (int j = 0; j < n; j++) {
    int cnt = 1;
    char c = curboard[0][j];
    for (int i = 1; i < n; i++) {
      if (c != curboard[i][j]) {
        maxCnt = max(maxCnt, cnt);
        cnt = 1;
        c = curboard[i][j];
      } else {
        cnt++;
      }
    }
    maxCnt = max(maxCnt, cnt);
  }
  return maxCnt;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> board[i];
  }
  int maxBomb = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - 1; j++) {
      maxBomb = max(maxBomb, bomb(i, j, i, j + 1));
    }
  }
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n; j++) {
      maxBomb = max(maxBomb, bomb(i, j, i + 1, j));
    }
  }
  cout << maxBomb;
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