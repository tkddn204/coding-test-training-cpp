#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int midNum = 10000000;
int n, m, k;
int a[500001];
int c[20000001];

int countNum(int k) {
  int st = 0;
  int en = n - 1;
  while (st <= en) {
    int mid = (st + en) / 2;
    if (a[mid] < k) st = mid + 1;
    else if (a[mid] > k) en = mid - 1;
    else return c[a[mid] + midNum];
  }
  return 0;
}

void solve() {
  int t, idx = 0;
  cin >> n;
  while (n--) {
    cin >> t;
    if (c[t + midNum] == 0) a[idx++] = t;
    c[t + midNum]++;
  }
  n = idx;
  sort(a, a+n);
  cin >> m;
  for (int i = 0 ; i < m; i++) {
    cin >> k;
    cout << countNum(k) << " ";
  }
}

void solveSimple() {
  int t;
  cin >> n;

  for (int i = 0 ; i < n; i++) {
    cin >> t;
    ++a[midNum + t];
  }

  cin >> m;
  for (int i = 0 ; i < m; i++) {
    cin >> t;
    cout << a[midNum + t] << " ";
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