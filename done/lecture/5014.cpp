#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int f, s, g, u, d;
int vst[1000001];

void solve() {
  cin >> f >> s >> g >> u >> d;

  int res = -1;

  fill(vst, vst + f + 1, -1);
  queue<pair<int, int>> Q;
  Q.push({s, 0});
  vst[s] = 0;
  while (!Q.empty()) {    
    int cur = Q.front().X;
    int dis = Q.front().Y;
    Q.pop();

    if (cur == g) {
      res = dis;
      break;
    }

    int nu = cur + u;
    if (nu > 0 && nu <= f && vst[nu] == -1) {
      Q.push({nu, dis + 1});
      vst[nu] = true;
    }

    int nd = cur - d;
    if(nd > 0 && nd <= f && vst[nd] == -1) {
      Q.push({nd, dis + 1});
      vst[nd] = true;
    }
  }

  if (res == -1) {
    cout << "use the stairs";
  } else {
    cout << res;
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