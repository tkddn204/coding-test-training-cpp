#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

int arr[100001];
int c[100001];
void solve() {
  int n, h;
  while (true) {
    stack<pair<int, int>> s;
    cin >> n;
    if (n == 0) break;
    ll r = 0LL;
    for (int i = 0; i < n; i++) {
      cin >> h;
      int idx = i;
      while (!s.empty() && s.top().second >= h) {
        r = max(r, (ll)((i - s.top().first) * s.top().second));
        idx = s.top().first;
        s.pop();
      }
      s.push({idx, h});
    }
    while (!s.empty()) {
      r = max(r, (ll)((n - s.top().first) * s.top().second));
      s.pop();
    }

    cout << r << endl;
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