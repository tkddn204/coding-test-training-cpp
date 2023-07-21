// 참고 : https://imnotabear.tistory.com/467
#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, p;
string pan[1001];
int go[10];

queue<pair<int, int>> Q[10];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void solve() {
  cin >> n >> m >> p;
  for (int i = 1; i <= p; i++) cin >> go[i];
  for (int i = 0; i < n; i++) {
    cin >> pan[i];
    for (int j = 0; j < m; j++) {
      if (pan[i][j] >= '1' && pan[i][j] <= '9') {
        Q[pan[i][j] - '0'].push({i, j});
      }
    }
  }

  bool isProceed = true;
  while (isProceed) {
    for (int turn = 1; turn <= p; turn++) {
      int dist = go[turn];
      while (!Q[turn].empty() && dist--) {
        int qSize = Q[turn].size();
        for (int i = 0; i < qSize; i++) {
          auto [x, y] = Q[turn].front(); Q[turn].pop();
          
          for (int d = 0; d < 4; d++) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx < 0 or nx >= n or ny < 0 or ny >= m) continue;
            if (pan[nx][ny] != '.') continue;
            pan[nx][ny] = '0' + turn;
            Q[turn].push({nx, ny});
          }
        }
      }
    }
    isProceed = false;
    for (int i = 1; i <= p; i++) {
      if(!Q[i].empty()) {
        isProceed = true;
        break;
      }
    }
    // for (int i = 0; i < n; i++) cout << pan[i] << endl;
    // cout << "-------" << endl;
  }

  int cnt[10] = {};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (pan[i][j] >= '0' and pan[i][j] <= '9')
        cnt[pan[i][j] - '0']++;
    }
  }
  for (int i = 1; i <= p; i++) {
    cout << cnt[i] << ' ';
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