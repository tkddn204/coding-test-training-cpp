#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  stack<int> s;
  int n, e, t = 1;
  string res;

  cin >> n;
  while (n--) {
    cin >> e;

    if (s.empty() || e > s.top()) {

      if (e < t) {
        res = "NO";
        break;
      }

      for (; t <= e; t++) {
        s.push(t);
        res += "+\n";
      }
    } else {
      while (!s.empty() && s.top() > e) {
        s.pop();
        res += "-\n";
      }
    }

    // 출력
    if (!s.empty()) {
      s.pop();
      res += "-\n";
    }
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