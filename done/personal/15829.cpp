#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

const ll mod = 1234567891;
ll r = 31;

void solve() {
  int L;
  string str;
  cin >> L >> str;

  ll res = 0;
  ll rs = 1;
  for (auto c: str) {
    ll v = c - 'a' + 1;
    res = (res + v * rs) % mod;
    rs = (rs * r) % mod;
  }
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