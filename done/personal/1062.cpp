#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, k;
string str[51];
bool chk[26];
char dft[5] = {'a', 'n', 't', 'i', 'c'};
int maxCnt = 0;

int cntToRead() {
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    bool canRead = true;
    for (auto c : str[i]) {
      if (!chk[c - 'a']) {
        canRead = false;
        break;
      }
    }
    if (canRead) cnt++;
  }
  return cnt;
}

void bt(int idx, int num) {
  if (num <= 0) {
    maxCnt = max(maxCnt, cntToRead());
    return;
  }

  for (int i = idx + 1; i < 26; i++) {
    if (chk[i]) continue;
    chk[i] = true;
    bt(i, num - 1);
    chk[i] = false;
  }
}

void solve() {
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    cin >> str[i];
  for (int i = 0; i < 5; i++)
    chk[dft[i] - 'a'] = true;

  if (k < 5) {
    cout << 0;
    return;
  }

  bt(0, k - 5);

  cout << maxCnt;
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