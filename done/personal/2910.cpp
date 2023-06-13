#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define IDX first
#define VAL second

map<ll, int> ck;
vector<pair<int, ll> > msg;

void solve() {
  int n, c;
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    if (!ck[k]) msg.push_back(make_pair(i, k));
    ck[k]++;
  }

  sort(msg.begin(), msg.end(), [](pair<int, ll>& a, pair<int, ll>& b) {
    return ck[a.VAL] == ck[b.VAL] ? a.IDX < b.IDX : ck[a.VAL] > ck[b.VAL];
  });

  for (auto e : msg) {
    int val = e.VAL;
    while (ck[val] > 0) {
      cout << val << ' ';
      ck[val]--;
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