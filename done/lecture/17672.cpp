#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int b[102][102];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

char t[10001];

void solve() {
  int n, k, l;
  cin >> n >> k;
  while (k--) {
    int x, y;
    cin >> x >> y;
    b[x][y] = 'a';
  }
  cin >> l;
  while (l--) {
    int x;
    char c;
    cin >> x >> c;
    t[x] = c;
  }
  int d = 1;
  deque<pair<int, int>> S;
  S.push_back({1, 1});
  int time = 0;
  while (true) {
    time++;
    pair<int, int> h = S.front();
    b[h.X][h.Y] = 1;
    int nx = h.X + dx[d];
    int ny = h.Y + dy[d];
    if (nx < 1 || nx > n || ny < 1 || ny > n) break;
    if (b[nx][ny] == 1) break;
    if (b[nx][ny] != 'a') {
      pair<int, int> bs = S.back();
      b[bs.X][bs.Y] = 0;
      S.pop_back();
    }
    if (t[time] == 'D') {
      d = (d + 3) % 4;
    } else if (t[time] == 'L') {
      d = (d + 1) % 4;
    }
    S.push_front({nx, ny});
  }
  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {
  //     if (b[i][j] == 'a') {
  //       cout << 'a' << ' ';
  //     } else {
  //       cout << b[i][j] << ' ';
  //     }
  //   }
  //   cout << endl;
  // }
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