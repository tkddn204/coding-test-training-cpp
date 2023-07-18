#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define H first
#define S second

ll hist[100005];

void solve() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    fill(hist, hist + n + 2, 0);
    for (int i = 1; i <= n; i++) cin >> hist[i];

    stack<int> st;
    st.push(0);
    ll maxSize = 0;
    for (int i = 1; i <= n + 1; i++) {
      while (!st.empty() && hist[st.top()] > hist[i]) {
        int h = st.top(); st.pop();
        ll cnt = i - st.top() - 1;
        maxSize = max(maxSize, hist[h] * cnt);
      }
      st.push(i);
    }
    cout << maxSize << endl;
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