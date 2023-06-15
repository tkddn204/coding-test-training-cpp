#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int pan[5][5][5];   // 처음판
int miro[5][5][5];  // 돌리는거
int vst[5][5][5];   // 방문
int order[5] = {0, 1, 2, 3, 4};
pair<int, int> sp[4] = {{0, 0}, {0, 4}, {4, 0}, {4, 4}};
pair<int, int> ep[4] = {{4, 4}, {4, 0}, {0, 4}, {0, 0}};

int dz[2] = {-1, 1};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

/*
  x번째 판을 돌리기
*/
void rotate(int x) {
  int t[6][6];
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      t[i][j] = miro[x][4 - j][i];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      miro[x][i][j] = t[i][j];
    }
  }
}

void initAndCopy() {
  for (int o = 0; o < 5; o++) {
    int i = order[o];
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        miro[o][j][k] = pan[i][j][k];
        vst[i][j][k] = -1;
      }
    }
  }
}

vector<int> getState(int s) {
  vector<int> res(5);
  fill(res.begin(), res.end(), 0);
  int i = 0;
  while (s > 0) {
    res[i++] = s % 4;
    s /= 4;
  }
  return res;
}

void solve() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      for (int k = 0; k < 5; k++) {
        cin >> pan[i][j][k];
      }
    }
  }

  int minCnt = INT_MAX;

  do {
    for (int t = 0; t < (1 << 10); t++) {
      initAndCopy();
      vector<int> state = getState(t);
      for (int st = 0; st < 5; st++) {
        while (state[st]--) rotate(st);
      }

      for (int s = 0; s < 4; s++) {
        bool canStart = miro[0][sp[s].X][sp[s].Y];
        bool canEnd = miro[4][ep[s].X][ep[s].Y];
        if (!(canStart && canEnd)) continue;

        queue<pair<int, pair<int, int> > > Q;
        Q.push({0, sp[s]});
        vst[0][sp[s].X][sp[s].Y] = 0;
        while (!Q.empty()) {
          pair<int, pair<int, int> > cur = Q.front();
          Q.pop();
          int z = cur.X;
          int x, y;
          tie(x, y) = cur.Y;
          if (z == 4 && x == ep[s].X && y == ep[s].Y) {
            minCnt = min(minCnt, vst[z][x][y]);
            break;
          }
          for (int i = 0; i < 2; i++) {
            int nz = z + dz[i];
            if (nz < 0 || nz >= 5) continue;
            if (!miro[nz][x][y] || vst[nz][x][y] > -1) continue;
            vst[nz][x][y] = vst[z][x][y] + 1;
            Q.push({nz, {x, y}});
          }
          for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            if (!miro[z][nx][ny] || vst[z][nx][ny] > -1) continue;
            vst[z][nx][ny] = vst[z][x][y] + 1;
            Q.push({z, {nx, ny}});
          }
        }
      }
    }
  } while (next_permutation(order, order + 5));
  if (minCnt == INT_MAX) {
    cout << -1;
  } else {
    cout << minCnt;
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