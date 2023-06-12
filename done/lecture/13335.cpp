#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, w, l;
int car[1001];
int bg[101];

int bgSum() {
  int s = 0;
  for (int i = 0; i < w; i++) {
    s += bg[i];
  }
  return s;
}

void shift(int nxt) {
  for (int i = 0; i < w; i++) {
    bg[i] = bg[i + 1];
  }
  bg[w - 1] = nxt;
}

void solve() {
  cin >> n >> w >> l;

  for (int i = 0; i < n; i++) cin >> car[i];

  int t = 0, c = 0;
  while (c < n) {
    int nxt = 0;
    if (bgSum() + car[c] <= l) {
      nxt = car[c++];
    }
    shift(nxt);
    if (nxt == 0 && c < n && bgSum() + car[c] <= l) {
      bg[w - 1] = car[c++];
    }
    t++;
  }
  while (bgSum() > 0) shift(0), t++;
  cout << t << endl;
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