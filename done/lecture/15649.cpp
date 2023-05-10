#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n,m;
int arr[10];
bool vst[10];

void rec(int k) {
  if (k == m) {
    for (int i = 0 ; i < m; i++) {
      cout << arr[i] << ' ';
    }
    cout << '\n';
    return;
  }

  for (int i = 1 ; i <= n; i++) {
    if (!vst[i]) {
      arr[k] = i;
      vst[i] = 1;
      rec(k + 1);
      vst[i] = 0;
    }
  }
}

void solve() {
  cin >> n >> m;
  rec(0);
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