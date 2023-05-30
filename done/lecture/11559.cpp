#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

char field[13][7];
int check[13][7];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
  for (int i = 0 ; i < 12; i++) {
    for (int j = 0 ; j < 6; j++) {
      cin >> field[i][j];
    }
  }

  int res = 0;
  bool isPuyo = true;
  while (isPuyo) {
    isPuyo = false;

    for (int k = 0; k < 6; k++) {
      for (int l = 10; l >= 0; --l) {
        int t = l;       
        while (t < 11 && field[t + 1][k] == '.') {
          swap(field[t][k], field[t + 1][k]);
          ++t;
        }
      }
    }

    for (int i = 0 ; i < 12; i++) {
      for (int j = 0 ; j < 6; j++) {
        int color = field[i][j];
        if (color == '.') continue;
        
        for (int k = 0 ; k < 12; k++)
          fill(check[k], check[k] + 6, false);
        queue<pair<int, int>> q;
        vector<pair<int, int>> v;
        q.push({i, j});
        v.push_back({i, j});
        int cnt = 0;
        while (!q.empty()) {
          pair<int, int> cur = q.front(); q.pop();
          check[cur.X][cur.Y] = true;
          cnt++;
          for (int d = 0 ; d < 4; d++) {
            int nx = cur.X + dx[d];
            int ny = cur.Y + dy[d];

            if (nx < 0 || nx > 12 || ny < 0 || ny > 6) continue;
            if (check[nx][ny] || field[nx][ny] != color) continue;
            q.push({nx, ny});
            v.push_back({nx, ny});
          }
        }

        if (cnt < 4) continue;
        isPuyo = true;
        for (auto k : v) field[k.X][k.Y] = '.';
      }
    }
    
    // for (int a = 0 ; a < 12; a++) {
    //   for (int b = 0; b < 6; b++) {
    //     cout << field[a][b];
    //   }
    //   cout << endl;
    // }
    // cout << "---------------------" << endl;
    if (isPuyo) res++;
  }
  cout << res;
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