#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int freq[2000002];

void solve() {
  int n, a;
  cin >> n;
  while(n--) {
    cin >> a;
    freq[a+1000000]++;
  }

  for (int i = 0 ; i < 2000002; i++) {
    for (int j = freq[i]; j > 0; j--) {
      cout << i - 1000000 << endl;
    }
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