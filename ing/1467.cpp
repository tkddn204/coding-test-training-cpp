#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int sn[10];
int rn[10];
int tn[10];
string s, r;

bool isPoss() {
  for (int i = 0; i < 10; i++) {
    if (tn[i] > rn[i]) return false;
  }
  return true;
}

void solve() {
  cin >> s >> r;
  for (auto c : s) sn[c - '0']++;
  for (auto c : r) sn[c - '0']--, rn[c - '0']++;

  string res;
  int size = s.size() - r.size();
  int p = 0;
  // for (int i = 0; i < 10; i++) cout << sn[i] << ' ';
  cout << endl;
  for (int i = 0; i < size; i++) {
    for (int j = 9; j >= 0; j--) {
      if (!sn[j]) continue;

      fill(tn, tn + 10, 0);

      int k = p;
      do {
        tn[s[k++] - '0']++;
      } while ((s[k] - '0') != j);
      // for (int k = 0; k < 10; k++) cout << tn[k] << ' ';
      // cout << endl;
      if (!isPoss()) {
        while ((s[p] - '0') != j) rn[s[p++] - '0']--;
        res += (j + '0');
        sn[j]--;
        p++;
        break;
      }
    }
  }

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