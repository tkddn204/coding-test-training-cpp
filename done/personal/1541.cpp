#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  string s;
  cin >> s;

  string b;
  int sum = 0;
  bool isMinus = false;
  for (auto c : s) {
    if (c == '+' || c == '-') {
      if (isMinus) sum -= stoi(b);
      else sum += stoi(b);
      b.clear();
      if (c == '-') isMinus = true;
    } else {
      b += c;
    }
  }
  if (b.length() > 0) {
    if (isMinus) sum -= stoi(b);
    else sum += stoi(b);
  }

  cout << sum;  
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