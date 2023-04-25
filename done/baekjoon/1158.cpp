#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int pre[5001], nxt[5001];

void solve() {
  int n, k;
  cin >> n >> k;
  
  nxt[0] = 1;
  for (int i = 1 ; i <= n; i++) {
    pre[i] = (i == 1) ? n : i - 1;
    nxt[i] = (i == n) ? 1 : i + 1;
  }

  int idx = 0;
  cout << "<";
  while (n--) {
    // k번째 사람 뽑고 출력
    int kk = k;
    while (kk--) idx = nxt[idx];
    cout << idx;
    if (n != 0) {
      cout << ',' << " ";
    }
    
    // k번째 사람 삭제
    nxt[pre[idx]] = nxt[idx];
    pre[nxt[idx]] = pre[idx];
  }
  cout << ">";
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