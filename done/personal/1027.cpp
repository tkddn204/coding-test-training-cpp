#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

ll b[51];
int cnt[51];

void solve() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }

  for (int i = 1; i < n; i++) {
    for (int j = i + 1; j <= n; j++) {
      bool isView = true;
      for (int k = i + 1; k < j; k++) {
        isView = (b[j] - b[i]) * (k - i) > (j - i) * (b[k] - b[i]);
        if (!isView) break;
      }
      if (isView) cnt[i]++, cnt[j]++;
    }
  }
  cout << *max_element(cnt, cnt + 51);
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