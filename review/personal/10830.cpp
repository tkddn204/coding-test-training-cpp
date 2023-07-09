#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long
#define MOD 1000

int n;
ll b;

typedef vector<vector<int>> matrix;
matrix operator * (matrix& a, matrix& b) {
  matrix m(n, vector<int>(n));
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        m[i][j] += a[i][k] * b[k][j];
      }
      m[i][j] %= MOD;
    }
  }
  return m;
}

matrix mat, res;

void printMat(matrix& k) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << k[i][j] << ' ';
    }
    cout << endl;
  }
}

void solve() {
  cin >> n >> b;

  for (int i = 0; i < n; i++) {
    vector<int> t, r;
    for (int j = 0; j < n; j++) {
      int k;
      cin >> k;
      t.push_back(k);
      if (i == j) r.push_back(1);
      else r.push_back(0);
    }
    mat.push_back(t);
    res.push_back(r);
  }

  while (b > 0) {
    if (b % 2 == 1) res = res * mat;
    mat = mat * mat;
    b /= 2;
  }

  printMat(res);
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