#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  deque<int> dq;
  int arr[51];
  int n, m, op = 0;

  cin >> n >> m;
  for (int i = 0 ; i < m; ++i) cin >> arr[i];

  for (int i = 1 ; i <= n; ++i) dq.push_back(i);
  for (int i = 0 ; i < m ; ++i ) {
    if (dq[0] == arr[i]) {
      dq.pop_front();
    } else {
      int j = 0;
      while (dq[j] != arr[i] && j < dq.size()) j++;

      if (j > dq.size() / 2) {
        while (dq[0] != arr[i]) {
          dq.push_front(dq.back());
          dq.pop_back();
          op++;
        }
        dq.pop_front();
      } else {
        while (dq[0] != arr[i]) {
          dq.push_back(dq.front());
          dq.pop_front();
          op++;
        }
        dq.pop_front();
      }
    }
  }
  cout << op;
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