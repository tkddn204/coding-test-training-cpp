#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n, m;
  vector<int> c;

  cin >> n >> m;
  for (int i = 0 ; i < n; i++) {
    if (i < m) c.push_back(0);
    else c.push_back(1);
  }

  do {
    for (int i = 0; i < n; i++) {
      if (c[i] == 0) cout << i + 1 << " ";
    }
    cout << endl;
  } while(next_permutation(c.begin(), c.end()));
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