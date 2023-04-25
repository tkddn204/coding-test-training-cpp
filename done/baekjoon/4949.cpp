#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  
  string str;
  while(getline(cin, str)) {
    if (str == ".") break;

    stack<int> s;
    bool isGood = true;

    for (auto c: str) {
      if (c == '(' || c == '[') {
        s.push(c);
      } else if (c == ')') {
        if (!s.empty() && s.top() == '(') s.pop();
        else isGood = false;
      } else if (c == ']') {
        if (!s.empty() && s.top() == '[') s.pop();
        else isGood = false;
      }
      if (!isGood) break;
    }

    if (isGood && s.empty()) cout << "yes" << endl;
    else cout << "no" << endl;
  };
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