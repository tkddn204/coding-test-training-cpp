#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

struct cmp {
  bool operator()(int a, int b) {
    int absA = abs(a), absB = abs(b);
    if (absA == absB) return a > b;
    return absA >= absB;

    //if (absA != absB) return absA > absB;
    //return a > 0 && b < 0;
  }
};

void solve() {
  priority_queue<int, vector<int>, cmp> pq;
  int n, x;
  cin >> n;
  while(n--) {
    cin >> x;
    if (x != 0) {
      pq.push(x);
    } else {
      if (pq.empty()) {
        cout << 0 << endl;
        continue;
      }
      cout << pq.top() << endl;
      pq.pop();
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