#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int gp[101][101];
int vst[101];
int ck[101][101];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> gp[i][j];
    }
  }

  for (int cur = 0; cur < n; cur++) {
    fill(vst, vst + 101, -1);
    queue<int> Q;
    Q.push(cur);
    while (!Q.empty()) {
      int u = Q.front();
      Q.pop();

      for (int v = 0; v < n; v++) {
        if (vst[v] != -1 || !gp[u][v]) continue;
        if (v != cur) Q.push(v);
        vst[v] = vst[u] + 1;
      }
    }

    for (int i = 0; i < n; i++) {
      ck[cur][i] = vst[i] != -1;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << ck[i][j] << ' ';
    }
    cout << endl;
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