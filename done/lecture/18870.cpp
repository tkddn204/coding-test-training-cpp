#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int a[1000001];
int b[1000001];
int c[1000001];

void solve() {
  int n;
  cin >> n;
  for (int i = 0 ; i < n ; i++) {
    cin >> a[i];
    b[i] = a[i];
  }
  sort(b, b+n);

  int idx = 0;
  for (int i = 0 ; i < n; i++) {
    if (i == 0) c[idx++] = b[i];
    else if (b[i - 1] != b[i]) c[idx++] = b[i];
  }
  
  for (int i = 0 ; i < n; i++) {
    cout << std::lower_bound(c, c+idx, a[i]) - c << " ";
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