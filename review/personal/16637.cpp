#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int n;
string inp;
ll maxVal = LLONG_MIN;

ll oper(ll a, char op, ll b) {
  ll res = 0;
  if (op == '+') res = a + b;
  else if (op == '-') res = a - b;
  else if (op == '*') res = a * b;
  return res;
}

void go(int idx, ll val) {
  if (idx >= n) {
    maxVal = max(maxVal, val);
    return;
  }
  char op = idx == 0 ? '+' : inp[idx - 1];

  ll a = inp[idx] - '0';
  if (idx + 2 < n) {
    ll b = inp[idx + 2] - '0';
    ll brop = inp[idx + 1];

    ll br = oper(a, brop, b);
    go(idx + 4, oper(val, op, br));
  }
  
  go(idx + 2, oper(val, op, a));
}

void solve() {
  cin >> n;
  cin >> inp;

  go(0, 0);

  cout << maxVal;
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