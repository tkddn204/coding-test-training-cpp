#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int arr[100001];

void solve() {
  int n;
  cin >> n;

  for (int i = 0 ; i < n; i++) cin >> arr[i];

  sort(arr, arr+n);

  int m = 0;
  for (int i = 1 ; i <= n; i++) {
    m = max(m, arr[n - i] * i);
  }

  cout << m;
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