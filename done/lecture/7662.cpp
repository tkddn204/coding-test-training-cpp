#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int t;
  cin >> t;
  while (t--) {
    multiset<int> s;
    char cmd;
    int k, n;
    cin >> k;
    while (k--) {
      cin >> cmd >> n;
      if (cmd == 'I') s.insert(n);
      else if (cmd == 'D') {
        if (s.empty()) continue;
        if (n == 1) s.erase(prev(s.end()));
        else if (n == -1) s.erase(s.begin());
        else s.erase(n);
      }
    }
    if (s.empty()) cout << "EMPTY" << endl;
    else cout << *prev(s.end()) << ' ' << *s.begin() << endl;
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