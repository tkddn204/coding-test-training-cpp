#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[100001];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0 ; i < n; i++) cin >> arr[i];
  sort(arr, arr+n);

  int res = INT_MAX, en = 0;
  for (int st = 0 ; st < n; st++) {
    while (en < n && arr[en] - arr[st] < m) en++;
    if (en == n) break;
    res = min(res, arr[en] - arr[st]);
  }
  cout << res;
  
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