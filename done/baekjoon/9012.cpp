#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n;
  string s;
  cin >> n;
  while (n--) {
    int p = 0;
    bool isGood = true;
    cin >> s;
    for (auto c: s) {
      if (c == '(') p++;
      else if (c == ')') {
        if (p > 0) p--;
        else {
          isGood = false;
          break;
        }
      }
    }
    if (p > 0 || !isGood) cout << "NO" << endl;
    else cout << "YES" << endl;
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