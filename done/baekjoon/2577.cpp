#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int)1e9

void solve() {
  int a, b, c, k, arr[10] = {};
  cin >> a >> b >> c;
  k = a*b*c;
  while(k) {
    arr[k % 10]++;
    k /= 10;
  }
  for (int i = 0 ; i < 10; i++) cout << arr[i] << endl;
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