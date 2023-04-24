#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int t, n;
  string s, as, res, stringBuffer;

  cin >> t;
  while(t--) {
    deque<int> dq;

    cin >> s;
    cin >> n;
    cin >> as;

    as.erase(as.begin());
    as.pop_back();
    istringstream ss(as);
    while(getline(ss, stringBuffer, ',')) {
      dq.push_back(stoi(stringBuffer));
    }

    bool rev = false;
    bool isError = false;
    for (auto c : s) {      
      if (c == 'R') {
        rev = !rev;
      } else { // 'D'
        if (dq.empty()) {
          isError = true;
          break;
        }
        if (rev) dq.pop_back();
        else dq.pop_front();
      }
    }

    if (isError) {
      cout << "error" << endl;
      continue;
    }

    cout << '[';
    if (rev) {
      for (int i = dq.size() - 1; i >= 0; i--) {
        cout << dq[i];
        if (i != 0) cout << ',';
      }
    } else {
      for (int i = 0 ; i < dq.size(); i++) {
        cout << dq[i];
        if (i != dq.size() - 1) cout << ',';
      }
    }
    cout << ']' << endl;
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