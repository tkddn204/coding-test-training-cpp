#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m;
int par[51];
vector<int> party[51];

int findp(int x) {
  return
    x != par[x]
      ? par[x] = findp(par[x])
      : par[x];
}

void unionp(int a, int b) {
  int pa = findp(par[a]);
  int pb = findp(par[b]);
  if (pa == pb) return;
  if (pa < pb) par[pb] = pa;
  else par[pa] = pb;
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) par[i] = i;
  int t, a;
  cin >> t;
  while (t--) {
    cin >> a;
    par[a] = 0;
  }

  for (int p = 0; p < m; p++) {
    cin >> t;
    for (int i = 0; i < t; i++) {
      cin >> a;
      party[p].push_back(a);
    }
    for (int i = 0; i < t - 1; i++) {
      unionp(party[p][i], party[p][i + 1]);
    }
  }
  int cnt = m;

  for (int p = 0; p < m; p++) {
    for (auto k : party[p]) {
      if (findp(par[k]) == 0) {
        cnt--;
        break;
      }
    }
  }

  cout << cnt;
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