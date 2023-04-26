#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

#define x first
#define y second

#define FIRE 0
#define JIHUN 1

const int len = 100001;
int p[len];
void solve() {
  queue<int> q;
  int n, k;
  cin >> n >> k;
  fill(p, p+100001, -1);

  p[n] = 0;
  q.push(n);
  while (!q.empty()) {
    int cur = q.front(); q.pop();

    if (cur == k){
      cout << p[cur];
      break;
    }

    int nx[3] = {cur + 1, cur - 1, 2 * cur};

    for (int i = 0 ; i < 3; i++) {
      if (nx[i] < 0 || nx[i] >= len) continue;
      if (p[nx[i]] != -1) continue;
      p[nx[i]] = p[cur] + 1;
      q.push(nx[i]);    
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