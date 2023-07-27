#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int k;
int tree[3001];
vector<int> res[11];

void search(int st, int en, int level) {
  if (level > k or st > en) return;

  int mid = (st + en) / 2;
  search(st, mid - 1, level + 1);
  res[level].push_back(mid);
  search(mid + 1, en, level + 1);
}

void solve() {
  cin >> k;
  
  int n = (1 << k) - 1;
  for (int i = 0; i < n; i++) {
    cin >> tree[i];
  }
  
  search(0, n, 1);

  for (int l = 1; l <= k; l++) {
    for (auto e : res[l]) {
      cout << tree[e] << ' ';
    }
    cout << endl;
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