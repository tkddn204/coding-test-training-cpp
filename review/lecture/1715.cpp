#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  priority_queue<int, vector<int>, greater<int>> pq;
  int n, x;
  cin >> n;
  while (n--) {
    cin >> x;
    pq.push(x);
  }
  int sum = 0;
  while (pq.size() > 1) {
    int a = pq.top(); pq.pop();
    int b = pq.top(); pq.pop();
    sum += a + b;
    pq.push(a + b);
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