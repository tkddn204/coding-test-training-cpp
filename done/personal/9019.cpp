#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

string vst[10001];
string com = "DSLR";

int D(int n) { return (n * 2) % 10000; }
int S(int n) { return n == 0 ? 9999 : --n; }
int L(int n) { return (n % 1000) * 10 + (n / 1000); }
int R(int n) { return (n / 10) + (n % 10) * 1000; }

void solve() {
  int t;
  cin >> t;
  while (t--) {
    fill(vst, vst + 10001, "");
    int a, b;
    cin >> a >> b;

    queue<int> Q;
    Q.push(a);
    while (!Q.empty()) {
      int cur = Q.front();
      Q.pop();
      if (cur == b) break;

      for (int i = 0; i < 4; i++) {
        int nxt;
        if (i == 0) {
          if (cur == 0) continue;
          nxt = D(cur);
        } else if (i == 1)
          nxt = S(cur);
        else if (i == 2)
          nxt = L(cur);
        else
          nxt = R(cur);

        if (nxt == a || !vst[nxt].empty()) continue;
        Q.push(nxt);
        vst[nxt] = vst[cur] + com[i];
      }
    }
    cout << vst[b] << endl;
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