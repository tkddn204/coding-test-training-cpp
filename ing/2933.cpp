#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int r, c;
string cave[101];
int vst[101][101];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void initvst() {
  for (int i = 0; i < r ; i++) {
    fill(vst[i], vst[i] + c, 0);
  }
}
void rearrange() {
  initvst();

  // 내리지 않아도 되는 곳 찾기  
  queue<pair<int, int>> Q;
  for (int j = 0; j < c; j++) {
    if (cave[r - 1][j] == 'x') {
      Q.push({r - 1, j});
      vst[r - 1][j] = 1;
    }
  }
  while (!Q.empty()) {
    auto [x, y] = Q.front(); Q.pop();

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
      if (vst[nx][ny] != 0 or cave[nx][ny] == '.') continue;
      Q.push({nx, ny});
      vst[nx][ny] = 1;
    }
  }

  // 내려야할 곳 찾아서 내리기
  int k = 2;
  for (int i = r - 1; i >= 0; i--) {
    for (int j = 0; j < c; j++) {
      if (vst[i][j] != 0 or cave[i][j] == '.') continue;

      // 찾기
      vector<pair<int, int>> piece;
      queue<pair<int, int>> Q;
      Q.push({i, j});
      vst[i][j] = k;
      piece.push_back({i, j});
      while (!Q.empty()) {
        auto [x, y] = Q.front(); Q.pop();

        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];
          if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
          if (vst[nx][ny] != 0 or cave[nx][ny] == '.') continue;
          Q.push({nx, ny});
          vst[nx][ny] = k;
          piece.push_back({nx, ny});
        }
      }

      // 얼마나 이동할 수 있는지 검사
      bool possible = true;
      int sft = 0;
      while (true) {
        for (auto [x, y] : piece) {
          int nx = x + sft + 1;
          int ny = y;
          if (nx < 0 or nx >= r or ny < 0 or ny >= c) {
            possible = false;
            break;
          }
          if (vst[nx][ny] != k and cave[nx][ny] == 'x') {
            possible = false;
            break;
          }
          if(!possible) break;
          sft++;
        }
      }
      // 내리기
      for (auto [x, y]: piece) {
        vst[x][y] = 0;
        vst[x + sft][y] = k;
        cave[x][y] = '.';
        cave[x + sft][y] = 'x';
      }

      k++;
    }
  }
}

void go(int col, int dr) {
  // 던지기
  if (dr == 0) { // 왼쪽 -> 오른쪽
    for (int j = 0; j < c; j++) {
      if (cave[col][j] == 'x') {
        cave[col][j] = '.';
        break;
      }
    }
  } else { // 오른쪽 -> 왼쪽
    for (int j = c - 1; j >= 0; j--) {
      if (cave[col][j] == 'x') {
        cave[col][j] = '.';
        break;
      }
    }
  }
}

void solve() {
  cin >> r >> c;
  for (int i = 0; i < r; i++) cin >> cave[i];
  
  int n, turn = 0;
  cin >> n;
  while (n--) {
    int h;
    cin >> h;
    go(r - h, turn++ % 2);
    rearrange();
  }

  for (int i = 0; i < r; i++) {
    cout << cave[i] << endl;
  }
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