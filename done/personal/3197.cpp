#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int r, c;
string pan[1501];
bool vst[1501][1501];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
queue<pair<int, int>> birdQ, birdNQ, waterQ, waterNQ;
pair<int, int> endBird;

void printPan() {
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < c; j++) {
      cout << pan[i][j];
    }
    cout << endl;
  }
  cout << "-----------------" << endl;
}

bool canMeet() {
  auto [ex, ey] = endBird;
  while (!birdQ.empty()) {
    auto [x, y] = birdQ.front(); birdQ.pop();

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];

      if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
      if (vst[nx][ny]) continue;
      vst[nx][ny] = true;
      if (pan[nx][ny] == '.') birdQ.push({nx, ny});
      else if (pan[nx][ny] == 'X') birdNQ.push({nx, ny});
      else if (nx == ex and ny == ey) {
        return true;
      }
    }
  }
  return false;
}

void melt() {
  while (!waterQ.empty()) {
    auto [x, y] = waterQ.front(); waterQ.pop();

    for (int d = 0; d < 4; d++) {
      int nx = x + dx[d];
      int ny = y + dy[d];
      if (nx < 0 or nx >= r or ny < 0 or ny >= c) continue;
      if (pan[nx][ny] != 'X') continue;
      pan[nx][ny] = '.';
      waterNQ.push({nx, ny});
    }
  }
}

void solve() {
  cin >> r >> c;

  vector<pair<int, int>> bird;
  for (int i = 0; i < r; i++) {
    cin >> pan[i];
    for (int j = 0; j < c; j++) {
      if (pan[i][j] != 'X') waterQ.push({i, j});
      if (pan[i][j] == 'L') bird.push_back({i, j});
    }
  }

  auto [sx, sy] = bird[0];
  endBird = bird[1];
  birdQ.push(bird[0]);
  vst[sx][sy] = true;
  int time = 0;
  while (!canMeet()) {
    melt();
    birdQ = birdNQ;
    waterQ = waterNQ;
    birdNQ = queue<pair<int, int>>();
    waterNQ = queue<pair<int, int>>();
    time++;
    // printPan();
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