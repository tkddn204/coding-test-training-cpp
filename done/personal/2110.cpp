#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, c;
int home[200001];

int search(int st, int en) {
  int md;
  int maxCnt = 0;
  while (st <= en) {
    md = (st + en) / 2;
    
    int router = 1;
    int k = home[0];
    for (int i = 1; i < n; i++) {
      if (home[i] - k >= md) {
        router++;
        k = home[i];
      }
    }

    if (router >= c) {
      maxCnt = max(maxCnt, md);      
      st = md + 1;
    } else en = md - 1;
  }

  return maxCnt;
}

void solve() {
  cin >> n >> c;
  for (int i = 0; i < n; i++) {
    cin >> home[i];
  }
  sort(home, home + n);
  int res = search(1, home[n - 1] - home[0]);
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