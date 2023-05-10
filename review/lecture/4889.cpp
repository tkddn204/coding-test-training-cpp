#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  string s;
  int t = 0;
  while (++t) {
    int r = 0, n = 0;
    cin >> s;
    if (s[0] == '-') break;
    for (auto c : s) {
      if (c == '{') n++;
      else if (--n < 0) n = 1, r++;
    }
    r += n / 2;
    cout << t << ". " << r << endl;
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