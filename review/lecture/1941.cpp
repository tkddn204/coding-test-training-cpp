#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

string ban[5];
bool comb[25];

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void solve() {
  for (int i = 0; i < 5; i++) {
    cin >> ban[i];
  }
  fill(comb + 7, comb + 25, true);

  int res = 0;
  do {
    queue<pair<int, int> > Q;
    bool chk[5][5] = {}, vst[5][5] = {};
    for (int i = 0; i < 25; i++) {
      if (!comb[i]) {
        int x = i / 5;
        int y = i % 5;
        chk[x][y] = true;
        if (Q.empty()) {
          Q.push({x, y});
          vst[x][y] = true;
        }
      }
    }

    int sum = 0, s = 0;
    while (!Q.empty()) {
      pair<int, int> cur = Q.front();
      Q.pop();
      sum++;
      s += ban[cur.X][cur.Y] == 'S';

      for (int i = 0; i < 4; i++) {
        pair<int, int> nxt = {cur.X + dx[i], cur.Y + dy[i]};
        if (nxt.X < 0 || nxt.X >= 5 || nxt.Y < 0 || nxt.Y >= 5) continue;
        if (vst[nxt.X][nxt.Y] || !chk[nxt.X][nxt.Y]) continue;
        Q.push(nxt);
        vst[nxt.X][nxt.Y] = true;
      }
    }

    res += (sum >= 7 && s >= 4);
  } while (next_permutation(comb, comb + 25));
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