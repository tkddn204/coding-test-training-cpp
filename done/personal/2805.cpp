#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll n, m, k;
vector<ll> tree;

void solve() {
  cin >> n >> m;
  ll st = 0, en = 0;
  for (int i = 0 ; i < n; i++) {
    cin >> k;
    tree.push_back(k);
    en = max(en, k);
  }
  sort(tree.begin(), tree.end());
  ll maxH = 0;
  while (st <= en) {
    ll mid = (st + en) / 2;
    ll sum = 0;
    for (auto t : tree) {
      if (t - mid > 0) sum += t - mid;
    }
    if (sum >= m) {
      st = mid + 1;
      maxH = max(mid, maxH);
    } else {
      en = mid - 1;
    }
  }
  cout << maxH;
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