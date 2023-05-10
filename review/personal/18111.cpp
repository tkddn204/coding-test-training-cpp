#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> arr;
int n, m, b;

void solve() {
  cin >> n >> m >> b;
  int size = n * m;
  int t;
  for (int i = 0 ; i < size ; i++) {
    cin >> t;
    arr.push_back(t);
  }

  int minT = INT_MAX;
  int maxH = 0;
  for (int h = 0; h <= 256; h++) {
    int add = 0;
    int del = 0;
    for (int i = 0 ; i < size ; i++) {
      int rest = arr[i] - h;
      if (rest < 0) add -= rest;
      if (rest > 0) del += rest;
    }
    if (del + b >= add) {
      int t = del * 2 + add;
      if (minT >= t) {
        minT = t;
        maxH = h;
      }
    }
  }

  cout << minT << " " << maxH;
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