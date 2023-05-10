#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int n, k, r = 0;
  int arr[11];  
  cin >> n >> k;
  for (int i = 0 ; i < n; i++) cin >> arr[i];
  while (k > 0) {
    for (int i = n - 1 ; i >= 0 ; i--) {
      if (k >= arr[i]) {
        k -= arr[i];
        r++;
        break;
      }
    }
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