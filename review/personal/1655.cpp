#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n;
  cin >> n;
  
  priority_queue<int> maxpq;
  priority_queue<int, vector<int>, greater<>> minpq;
  
  while (n--) {
    int k;
    cin >> k;
    if (minpq.size() == maxpq.size()) maxpq.push(k);
    else minpq.push(k);

    if (!maxpq.empty() && !minpq.empty()
                && maxpq.top() > minpq.top()) {
      int a = maxpq.top(); maxpq.pop();
      int b = minpq.top(); minpq.pop();
      maxpq.push(b);
      minpq.push(a);
    }

    cout << maxpq.top() << endl;
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