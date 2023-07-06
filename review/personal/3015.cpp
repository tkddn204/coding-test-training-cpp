#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ll long long
#define H first
#define P second

void printSt(stack<pair<ll, int>> st) {
  while (!st.empty()) {
    cout << st.top().H << ',' <<st.top().P << ' ';
    st.pop();
  }
  cout << endl;
  cout << "-------------------" << endl;
}

void solve() {
  int n;
  cin >> n;

  stack<pair<ll, int>> st;
  int cnt = 0;
  while (n--) {
    ll h;
    cin >> h;
    while (!st.empty() and st.top().H < h) {
      cnt += st.top().P;
      st.pop();
    }

    cout << h << " -> ";
    if (!st.empty()) {
      if (st.top().H == h) {
        cnt += st.top().P++ + (st.size() > 1);
        cout << cnt << endl;
        continue;
      } else cnt++;
    }
    cout << cnt << endl;
    st.push({h, 1});
    printSt(st);
  }
  cout << cnt;
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