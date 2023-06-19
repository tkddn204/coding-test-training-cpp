#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int len = 1005000;
bool prime[len];

bool isPal(int x) {
  vector<int> t;
  while (x > 0) {
    t.push_back(x % 10);
    x /= 10;
  }
  int s = t.size();
  for (int i = 0; i < s / 2; i++) {
    if (t[i] != t[s - 1 - i]) return false;
  }
  return true;
}

void solve() {
  int n;
  cin >> n;
  fill(prime + 2, prime + len, true);
  for (int i = 2; i * i <= len; i++) {
    if (!prime[i]) continue;
    for (int j = i * i; j <= len; j += i) {
      prime[j] = false;
    }
  }
  for (int i = n; i <= len; i++) {
    if (prime[i] && isPal(i)) {
      cout << i;
      break;
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