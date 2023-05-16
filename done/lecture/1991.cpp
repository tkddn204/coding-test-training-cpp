#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int lc[50], rc[50];

void preorder(int cur) {
  cout << (char)(cur + 'A' - 1);
  if (lc[cur] != 0) preorder(lc[cur]);
  if (rc[cur] != 0) preorder(rc[cur]);
}

void inorder(int cur) {
  if (lc[cur] != 0) inorder(lc[cur]);
  cout << (char)(cur + 'A' - 1);
  if (rc[cur] != 0) inorder(rc[cur]);
}

void postorder(int cur) {
  if (lc[cur] != 0) postorder(lc[cur]);
  if (rc[cur] != 0) postorder(rc[cur]);
  cout << (char)(cur + 'A' - 1);
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    char c, l, r;
    cin >> c >> l >> r;
    if (l != '.') lc[c - 'A' + 1] = l - 'A' + 1;
    if (r != '.') rc[c - 'A' + 1] = r - 'A' + 1;
  }
  preorder(1);
  cout << endl;
  inorder(1);   
  cout << endl;
  postorder(1);
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