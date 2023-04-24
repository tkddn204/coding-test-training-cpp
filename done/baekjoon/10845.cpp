#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int len = 10001;
int q[len];
int head = 0, tail = 0;

void solve() {
  int n, v;
  string s;

  cin >> n;
  while (n--) {
    cin >> s;
    if (s == "push") {
      cin >> v;
      if (tail < len)
        q[tail++] = v;
    } else if (s == "pop") {
      if (head < tail) {
        cout << q[head++] << endl;
      } else {
        cout << -1 << endl;
      }
    } else if (s == "size") {
      cout << tail - head << endl;
    } else if (s == "empty") {
      if (head == tail) {
        cout << 1 << endl;
      } else {
        cout << 0 << endl;
      }
    } else if (s == "front") {
      if (head == tail) {
        cout << -1 << endl;
      } else {
        cout << q[head] << endl;
      }
    } else if (s == "back") {
      if (head == tail) {
        cout << -1 << endl;
      } else {
        cout << q[tail - 1] << endl;
      }
    }
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