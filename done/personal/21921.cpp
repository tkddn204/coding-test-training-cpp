#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[250001];
map<int, int> cnt;

void solve() {
  int n, x;
  cin >> n >> x;
  int sum = 0, maxSum = 0;
  int s = 0;
  for (int e = 1; e <= n; e++) {
    cin >> arr[e];
    sum += arr[e];
    if (x > e - s) continue;
    sum -= arr[s++];
    cnt[sum]++;
    maxSum = max(maxSum, sum);
  }
  if (maxSum == 0) {
    cout << "SAD";
  } else {
    cout << maxSum << endl;
    cout << cnt[maxSum];
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