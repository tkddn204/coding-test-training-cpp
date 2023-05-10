#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[1000001], ans[1000001];
int s[1000001], p;

void solve() {
int k;
  cin >> k;
  for (int i = 0 ; i < k; i++) cin >> arr[i];

  for (int i = k - 1 ; i >= 0; i--) {
    while(p && s[p] <= arr[i]) p--;
    if (!p) {
      ans[i] = -1;
    } else {
      ans[i] = s[p];
    }
    s[++p] = arr[i];
  }
  for (int i = 0 ; i < k; i++) cout << ans[i] << " ";
}

void solveStack() {
  stack<int> s;
  int n;
  cin >> n;
  for (int i = 0 ; i < n; i++) cin >> arr[i];

  for (int i = n - 1; i >= 0; i--) {
    while (!s.empty() && arr[i] >= s.top()) {
      s.pop();
    }
    if (!s.empty()) {
      ans[i] = s.top();
    } else {
      ans[i] = -1;
    }
    s.push(arr[i]);
  }

  for (int i = 0; i < n; i++) {
    cout << ans[i] << " ";
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