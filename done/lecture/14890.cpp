#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int arr[12];
int op[11];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int opidx = 0;
  for (int i = 0; i < 4; i++) {
    int inp;
    cin >> inp;
    while(inp--) op[opidx++] = i;
  }

  int minRes = INT_MAX, maxRes = INT_MIN;
  do {
    int res = arr[0];
    for (int i = 0; i < n - 1; i++) {
      if (op[i] == 0) res += arr[i + 1];
      else if (op[i] == 1) res -= arr[i + 1];
      else if (op[i] == 2) res *= arr[i + 1];
      else res /= arr[i + 1];
    }
    minRes = min(minRes, res);
    maxRes = max(maxRes, res);
  } while(next_permutation(op, op + n - 1));
  cout << maxRes << endl;
  cout << minRes << endl;
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