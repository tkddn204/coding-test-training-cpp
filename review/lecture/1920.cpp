#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, m, k;
int a[100001];

int isExisted(int k) {
  int st = 0;
  int en = n - 1;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (a[mid] < k) st = mid + 1;
    else if (a[mid] > k) en = mid - 1;
    else return 1;
  }
  return 0;
}

void solve() {
  cin >> n;
  for (int i = 0 ; i < n; i++) cin >> a[i];
  sort(a, a+n);
  cin >> m;
  for (int i = 0 ; i < m; i++) {
    cin >> k;
    cout << isExisted(k) << endl;
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