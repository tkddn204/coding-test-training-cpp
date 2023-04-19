#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int)1e9

void solve() {
  int r = 0, arrA[26] = {}, arrB[26] = {};
  string a, b;
  cin >> a >> b;

  for (char c: a) ++arrA[c - 'a'];
  for (char c: b) ++arrB[c - 'a'];
  
  for (int i = 0 ; i < 26; ++i)
    r += abs(arrA[i] - arrB[i]);

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