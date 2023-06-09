#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second

int a[500001];
stack<pair<int, int>> st;

void solve1() {
  stack<pair<int, int>> s;
  int n, e;
  cin >> n;
  s.push({0, 1000000001});
  for (int i = 1; i <= n; i++) {
    cin >> e;
    while (s.top().second < e) s.pop();
    cout << s.top().first << " ";
    s.push({i, e});
  }
}

void solve2() {
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) cin >> a[i];

  for (int i = 0 ; i < n ; i++) {
    while (!st.empty() && st.top().y < a[i]) st.pop();

    if (!st.empty()) cout << st.top().x + 1 << " ";
    else cout << "0 ";
    
    st.push({i, a[i]});
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