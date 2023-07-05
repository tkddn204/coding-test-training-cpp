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

int n, m;
vector<int> pp[2001];
bool vst[2001];

void dfs(int k, int d) {
  dbge(d, endl);
  if (d >= 4) {
    cout << 1;
    exit(0);
  }
  vst[k] = true;
  for (auto p : pp[k]) {
    if (vst[p]) continue;
    dfs(p, d + 1);
  }
  vst[k] = false;
}

void solve() {
  cin >> n >> m;
  
  while(m--) {
    int a, b;
    cin >> a >> b;
    pp[a].push_back(b);
    pp[b].push_back(a);
  }

  for (int i = 0; i < n; i++) {
    dfs(i, 0);
  }

  cout << 0;  
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