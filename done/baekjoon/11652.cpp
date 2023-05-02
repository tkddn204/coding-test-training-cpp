#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second

long long arr[100001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) cin >> arr[i];
  
  sort(arr, arr+n);

  long long mx = -(1ll << 62) - 1;
  int num = 0;
  int mxNum = 0;
  for (int i = 0 ; i < n; i++) {
    if (i == 0 || arr[i - 1] == arr[i]) num++;
    else {
      if (mxNum < num) {
        mxNum = num;
        mx = arr[i-1];
      }
      num = 1;
    }
  }
  if (num > mxNum) mx = arr[n-1];
  cout << mx;
}

void solveMap() {
  int n, mx = 0;
  long long a, res = 0;
  map<long long, int> m;
  
  cin >> n;
  for (int i = 0 ; i < n ; i++) {
    cin >> a;
    if (!m[a]) m[a] = 1;
    else m[a]++;
  }

  for (auto e : m) {
    if (mx < e.y) {
      mx = max(mx, e.y);
      res = e.x;
    }
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