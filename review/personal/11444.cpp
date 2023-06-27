#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define MOD 1000000007

typedef vector<vector<ll> > matrix;

matrix operator * (matrix& a, matrix& b) {
  matrix m(2, vector<ll>(2));
  
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 2; k++) {
        m[i][j] += a[i][k] * b[k][j];
      }
      m[i][j] %= MOD;
    }
  }
  return m;
}

void solve() {
  ll n;
  cin >> n;
  matrix res = {{1, 0}, {0, 1}};
  matrix a = {{1, 1}, {1, 0}};

  while (n > 0) {
    if (n % 2) res = res * a;
    a = a *a;
    n /= 2;
  }
  cout << res[0][1];
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