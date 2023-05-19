#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int check[301][301];
int dx[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int l;
    pair<int, int> c, m;

    cin >> l;
    for (int i = 0 ; i < l; i++)
      fill(check[i], check[i] + l, -1);

    cin >> c.X >> c.Y;
    cin >> m.X >> m.Y;
    
    queue<pair<int, int>> Q;
    Q.push(c);
    check[c.X][c.Y] = 0;

    while (!Q.empty()) {
      pair<int, int> cur = Q.front(); Q.pop();
      for (int i = 0 ; i < 8; i++) {
        int nx = cur.X + dx[i];
        int ny = cur.Y + dy[i];
        if (nx < 0 || nx >= l || ny < 0 || ny >= l) continue;
        if (check[nx][ny] >= 0) continue;
        Q.push({nx, ny});
        check[nx][ny] = check[cur.X][cur.Y] + 1;
      }
    }
    cout << check[m.X][m.Y] << endl;
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