#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, s;
int arr[100001];
bool vst[100001];
int cnt = 0;

void rec(int cur, int sum) {
  if (cur == n) {
    if (sum == s) cnt++;
    return;
  }

  rec(cur + 1, sum + arr[cur]);
  rec(cur + 1, sum);
}

void solve() {
  cin >> n >> s;
  for (int i = 0 ; i < n; i++) cin >> arr[i];
  rec(0, 0);
  if (s == 0) cnt--;
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