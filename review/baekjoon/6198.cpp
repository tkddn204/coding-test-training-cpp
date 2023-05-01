#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int b[80001];

void solve() {
  stack<int> s;
  int n, h;
  long long r = 0LL;
  cin >> n;
  while(n--) {
    cin >> h;
    while(!s.empty() && h >= s.top()) {
      s.pop();
    }
    r += s.size();
    s.push(h);
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