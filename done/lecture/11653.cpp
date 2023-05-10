#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n;
  cin >> n;
  for (int i = 2 ; i*i <= n ; i++) {
    while (n % i == 0) {
      cout << i << endl;
      n /= i;
    }
  }
  if (n != 1) cout << n;
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