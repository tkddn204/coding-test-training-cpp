#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  queue<int> q;
  int n;

  cin >> n;
  for (int i = 1; i <= n; i++) q.push(i);

  while (q.size() > 1) {
    q.pop();
    q.push(q.front());
    q.pop();
  }
  cout << q.front();
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