#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

#define x first
#define y second

#define FIRE 0
#define JIHUN 1

int vst[2][1002][1002];
int miro[1002][1002];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int r, c;

void print(int flag) {
  string s[101];

  for (int i = 0 ; i < r ; i++) {
    for (int j = 0 ; j < c ; j++) {
      s[i] += to_string(miro[i][j]) + " ";
    }
    s[i] += "\t||\t";
  }
  for (int i = 0 ; i < r ; i++) {
    for (int j = 0 ; j < c ; j++) {
      s[i] += to_string(vst[flag][i][j]) + " ";
    }
  }

  string t = (flag == FIRE) ? "fire--------" : "jihun--------";
  cout << t << endl;
  for (int i = 0 ; i < r ; i++) cout << s[i] << endl;
  cout << endl;
}

void solve() {
  queue<pair<int, int>> qf, qj;
  string inp;
  cin >> r >> c;
  for (int i = 0 ; i < r; i++) {
    cin >> inp;
    for (int j = 0 ; j < c; j++) {
      vst[FIRE][i][j] = -1;
      vst[JIHUN][i][j] = -1;

      if (inp[j] ==  '#') {
        miro[i][j] = -1;
      } else if (inp[j] == 'F') {
        vst[FIRE][i][j] = 0;
        qf.push({i, j});
      } else if (inp[j] == 'J') {
        vst[JIHUN][i][j] = 0;
        qj.push({i, j});
      }
    }
  }

  while (!qf.empty()) {
    pair<int, int> cur = qf.front(); qf.pop();
    int fireCur = vst[FIRE][cur.x][cur.y];
    
    for (int i = 0 ; i < 4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];

      if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;
      if (vst[FIRE][nx][ny] >= 0 || miro[nx][ny] == -1) continue;
      vst[FIRE][nx][ny] = fireCur + 1;
      qf.push({nx, ny});
    }
  }

  while (!qj.empty()) {
    pair<int, int> cur = qj.front(); qj.pop();
    int jihunCur = vst[JIHUN][cur.x][cur.y];

    for (int i = 0 ; i < 4; i++) {
      int nx = cur.x + dx[i];
      int ny = cur.y + dy[i];

      if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
        cout << jihunCur + 1;
        return;
      }
      if (vst[JIHUN][nx][ny] >= 0 || miro[nx][ny] == -1) continue;
      if (vst[FIRE][nx][ny] != -1 && vst[FIRE][nx][ny] <= jihunCur + 1) continue;
      vst[JIHUN][nx][ny] = jihunCur + 1;
      qj.push({nx, ny});
    }
  }

  cout << "IMPOSSIBLE";
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