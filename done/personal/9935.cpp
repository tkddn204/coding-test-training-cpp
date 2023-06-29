#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

stack<char> st;

void solve() {
  string s, b;
  cin >> s;
  cin >> b;

  for (auto c : s) {
    st.push(c);
    if (st.top() == b.back()) {
      if (st.size() < b.size()) continue;
      string t;
      for (int i = b.size() - 1; i >= 0; i--) {
        if (st.top() == b[i]) {
          t += st.top();
          st.pop();
        } else {
          for (int k = t.size() - 1; k >= 0; k--) {
            st.push(t[k]);
          }
          break;
        }
      }
    }
  }

  if (st.empty()) {
    cout << "FRULA";
  } else {
    string res;
    while(!st.empty()) {
      res += st.top();
      st.pop();
    }
    reverse(res.begin(), res.end());
    cout << res;
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