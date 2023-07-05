#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

#define endl "\n"
#define dbgl(x) \
    if constexpr (!ndebug) cout << #x << endl
#define dbg(x) \
    if constexpr (!ndebug) cout << x
#define dbge(x, e) \
    if constexpr (!ndebug) cout << x << e

vector<pair<int, int>> piece;
string board[6];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int minCnt = 25;

bool isCon() {
  bool chk[6][6];
  for (int i = 0; i < 5; i++)
    fill(chk[i], chk[i] + 5, false);
  queue<pair<int, int>> Q;

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (board[i][j] != '*') continue;
      Q.push({i, j});
      chk[i][j] = true;
      int cnt = 0;
      while(!Q.empty()) {
        int x, y;
        tie(x, y) = Q.front(); Q.pop();
        cnt++;
        for (int d = 0; d < 4; d++) {
          int nx = x + dx[d];
          int ny = y + dy[d];
          if (nx < 0 or nx >= 5 or ny < 0 or ny >= 5) continue;
          if (chk[nx][ny] or board[nx][ny] != '*') continue;
          Q.push({nx, ny});
          chk[nx][ny] = true;
        }
      }
      //dbge(cnt, endl);
      return cnt == piece.size();
    }
  }
  // dbge(cnt, endl);
}

void bt(int idx, int cnt) {
  if (minCnt < cnt) return;
  if (idx == piece.size()) {
    if (isCon()) minCnt = min(minCnt, cnt);
    return;
  }
  int x, y;
  tie(x, y) = piece[idx];

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (board[i][j] == '*') continue;
      board[i][j] = '*';
      int nxt = abs(x - i) + abs(y - j);
      bt(idx + 1, cnt + nxt);
      board[i][j] = '.';
    }
  }
}

void solve() {
  for (int i = 0; i < 5; i++) {
    cin >> board[i];
    for (int j = 0; j < 5; j++) {
      if (board[i][j] == '*') {
        piece.push_back({i, j});
        board[i][j] = '.';
      }
    }
  }
  bt(0, 0);
  cout << minCnt;
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