#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n, r = 0;
  string s;
  cin >> n;
  while (n--) {
    stack<char> st;
    cin >> s;
    for (auto c : s) {
      if (st.empty()) {
        st.push(c);
      } else if (st.top() == c) {
        st.pop();
      } else {
        st.push(c);
      }
    }
    if (st.empty()) r++;
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