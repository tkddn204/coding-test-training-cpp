#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int mp[51][51];
int vst[51][51];
int dx[] = {0, -1, 0, 1};
int dy[] = {-1, 0, 1, 0};
vector<pair<int, int>> virus;
int empt;
bool perm[11];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mp[i][j];
      if (mp[i][j] == 0) empt++;
      if (mp[i][j] == 2) {
        virus.push_back({i, j});                
      }
    }
  }

  int bsize = virus.size();
  fill(perm + m, perm + bsize, true);

  int minTime = 1000000;
  bool impossible = false;
  do {
    for (int i = 0; i < n; i++) {
      for  (int j = 0; j < n; j++) {
        // 0 -> -1, 1 -> -2, 2 -> -3
        vst[i][j] = -1 - mp[i][j];
      }
    }

    queue<pair<int, int>> Q;
    for (int p = 0; p < bsize; p++) {
      if (!perm[p]) {
        int bx, by;
        tie(bx, by) = virus[p];
        vst[bx][by] = 0; // 활성
        Q.push({bx, by});
      }
    }

    int infect = 0;
    int time = 0;
    while (!Q.empty()) {
      int x, y;
      tie(x, y) = Q.front(); Q.pop();
      
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
        if (vst[nx][ny] == -2) continue;
        if (vst[nx][ny] >= 0) continue;
        vst[nx][ny] = vst[x][y] + 1;
        if (mp[nx][ny] == 0) {
          infect++;
          time = vst[nx][ny];
        }
        Q.push({nx, ny});
      }
    }

    if (empt == infect) {
      minTime = min(minTime, time);
    }
  } while (next_permutation(perm, perm + bsize));
  if (minTime >= 1000000) cout << -1;
  else cout << minTime;
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