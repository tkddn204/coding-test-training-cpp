#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

#define ll long long

ll rec(ll a, ll b, ll c) {
  if (b == 1) return a % c;
  ll x = rec(a, b / 2, c);
  x = x * x % c;
  return b % 2 ? (x * a) % c : x;
}

void solve() {
  ll a, b, c;
  cin >> a >> b >> c;
  ll r = rec(a, b, c);
  cout << r;
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