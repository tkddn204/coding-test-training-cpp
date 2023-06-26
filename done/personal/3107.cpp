#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  string s;
  cin >> s;
  
  vector<string> inpVt;
  int inpSize = s.size();
  for (int i = 0; i < inpSize; i++) {
    string t;
    while (i < inpSize && s[i] != ':') {
      t += s[i++];
    }
    if (t.size() > 0) inpVt.push_back(t);
    if (i < inpSize - 1 && s[i] == ':' && s[i + 1] == ':') {
      inpVt.push_back("::");
      i++;
    }
  }
  vector<string> res;
  int inpVtSize = inpVt.size();
  for (int i = 0; i < inpVtSize; i++) {
    if (inpVt[i] == "::") {
      int tp = 8 - inpVtSize + 1;
      while (tp--) res.push_back("0000");
    } else {
      string t;
      int otSize = inpVt[i].size();
      if (otSize < 4) {
        for (int j = 0; j < 4 - otSize; j++) t += '0';
        for (int j = 0; j < otSize; j++) t += inpVt[i][j];
      } else {
        t = inpVt[i];
      }
      res.push_back(t);
    }
  }
  int resSize = res.size();
  for (int i = 0; i < resSize; i++) {
    cout << res[i];
    if (i < resSize - 1) cout << ':';
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