#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int)1e9

void solve() {
  int n;
  cin >> n;
  string str[1001][2];
  for (int i = 0 ; i < n; i++) {
    cin >> str[i][0] >> str[i][1];

    int chk[26] = {0};
    int flag = 0;
    for (auto c: str[i][0]) chk[c - 'a']++;
    for (auto c: str[i][1]) chk[c - 'a']--;
    for (int i = 0; i < 26; i++) {
      if (chk[i]) {
        flag = 1;
        break;
      }
    }
    if (flag) cout << "Impossible" << endl;
    else  cout << "Possible" << endl;
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