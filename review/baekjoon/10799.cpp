#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  stack<char> s;
  string str;
  int r = 0;
  cin >> str;
  for (int i = 0 ; i < str.length(); ++i) {
    if (str[i] == '(') {
      s.push(str[i]);
    } else {
      if (!s.empty()) {
        s.pop();
        if (str[i - 1] == '(') r += s.size();
        else r++;
      }
    }
  }
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