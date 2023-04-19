#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int)1e9

void solve() {
  int arr[26];
  fill(arr, arr+26, 0);
  string inp;
  cin >> inp;
  for (char i : inp) {
    arr[i-'a']++;
  }
  for (int i = 0 ; i < 26; i++) {
    cout << arr[i] << ' ';
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