#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int gp[101][101];
int vst[101];
int score[101];

void solve() {
  int n, m, a, b;
  cin >> n >> m;
  for (int j = 0; j < m; j++) {
    cin >> a >> b;
    gp[a][b] = gp[b][a] = 1;
  }

  int minScore = 10000;
  for (int i = 1; i <= n; i++) {
    queue<int> Q;
    fill(vst, vst + 101, -1);

    Q.push(i);
    vst[i] = 0;
    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();

      for (int k = 1; k <= n; k++) {
        if (gp[cur][k] == 0 || vst[k] >= 0) continue;
        Q.push(k);
        vst[k] = vst[cur] + 1;
      }
    }

    for (int t = 1; t <= n; t++) {
      score[i] += vst[t];
    }
    minScore = min(minScore, score[i]);
  }
  for (int t = 1; t <= n; t++) {
    if (score[t] == minScore) {
      cout << t << endl;
      break;
    }
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