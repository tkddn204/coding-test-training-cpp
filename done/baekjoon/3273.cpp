#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int)1e9

int n, x, a[100001];
int r, c[1000001];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> x;

  for (int i = 0 ; i < n; i++) {
    if (x > a[i] && x - a[i] <= 1000000 && c[x - a[i]]) r++;
    ++c[a[i]];
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