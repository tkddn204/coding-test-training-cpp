#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

map<ll, int> m;

void solve() {
  ll a, b;
  cin >> a >> b;

  if (a > b) {
    cout << -1;
    return;
  }

  queue<ll> Q;
  Q.push(a);
  while (!Q.empty()) {
    ll x = Q.front(); Q.pop();

    if (x == b) break;

    ll nxt[2] = {x * 2, (x * 10) + 1};
    for (int i = 0; i < 2; i++) {
      ll nx = nxt[i];
      if (nx > b || m.find(nx) != m.end()) continue;

      Q.push(nx);
      m[nx] = m[x] + 1;
    }
  }
  if (m[b] > 0) cout << m[b] + 1;
  else cout << -1;
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