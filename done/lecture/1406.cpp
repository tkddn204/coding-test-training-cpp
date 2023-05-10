#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  list<char> l;
  string inp;
  int n;
  list<char>::iterator cur = l.end();
  char com;

  cin >> inp;
  cin >> n;
  for (auto i : inp) {
    l.push_back(i);
  }
  while(n--) {
    cin >> com;
    if (com == 'L') {
      if(cur != l.begin()) cur--;
    } else if (com == 'D') {
      if(cur != l.end()) cur++;
    } else if (com == 'B') {
      if (cur != l.begin())
        cur = l.erase(--cur);
    } else if (com == 'P') {
      cin >> com;
      l.insert(cur, com);
    }
  }

  for (auto i: l) {
    cout << i;
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