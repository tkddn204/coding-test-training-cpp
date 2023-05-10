#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second

int n;
int board[22][22];
int temp[22][22];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};


void print() {
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < n ; j++) {
      cout << temp[i][j] << " ";
    }
    cout << endl;
  }
  cout << "---------------" << endl;
}

/*
  0 : left, 1 : up, 2 : right, 3 : down
*/
void move(int dir) {
  for (int i = 0 ; i < n; i++) {
    int t[22] = {}, p = 0;
    pair<int, int> cur;
    int nx, ny;

    if (dir == 0) cur = {i, 0};
    else if (dir == 1) cur = {0, i};
    else if (dir == 2) cur = {i, n - 1};
    else cur = {n - 1, i};
    nx = cur.x;
    ny = cur.y;
    for (int j = 0 ; j < n; j++) {
      if (temp[nx][ny]) {
        if (t[p] == 0) {
          t[p] = temp[nx][ny];
        } else if (t[p] == temp[nx][ny]) {
          t[p++] *= 2;
        } else {
          t[++p] = temp[nx][ny];
        }
      }
      nx += dx[dir];
      ny += dy[dir];
    }

    nx = cur.x;
    ny = cur.y;
    for (int j = 0 ; j < n ; j++) {
      temp[nx][ny] = t[j];
      nx += dx[dir];
      ny += dy[dir];
    }
  }
}

void solve() {
  int mx = 0;
  cin >> n;
  for (int i = 0 ; i < n ; i++) {
    for (int j = 0 ; j < n ; j++) {
      cin >> board[i][j];
    }
  }
  for (int t = 0 ; t < 1<<(2*5); t++) {
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < n ; j++) {
        temp[i][j] = board[i][j];
      }
    }
    int b = t;
    for (int i = 0 ; i < 5; i++) {
      int dir = b % 4;
      b /= 4;
      move(dir);
    }
    for (int i = 0 ; i < n ; i++) {
      for (int j = 0 ; j < n ; j++) {
        mx = max(mx, temp[i][j]);
      }
    }
  }
  cout << mx;
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