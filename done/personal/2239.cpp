#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int sdk[10][10];
vector<pair<int, int>> V;

bool isValid(int x, int y) {
  // 가로세로
  for (int i = 0; i < 9; i++) {
    if (sdk[x][y] == sdk[x][i] && i != y) return false;
    if (sdk[x][y] == sdk[i][y] && i != x) return false;
  }
  
  // 3*3
  int k = (x / 3) * 3;
  int t = (y / 3) * 3;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (x == k + i && y == t + j) continue;
      if (sdk[k + i][t + j] == sdk[x][y]) return false;
    }
  }
  return true;
}

void printSdk() {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      cout << sdk[i][j];
    }
    cout << endl;
  } 
}

void bt(int idx) {
  if (idx >= V.size()) {
    printSdk();
    exit(0);
  }
  int x, y;
  tie(x, y) = V[idx];
  for (int k = 1; k <= 9; k++) {
    sdk[x][y] = k;
    if (isValid(x, y)) {
      bt(idx + 1);
    }
  }
  sdk[x][y] = 0;
}

void solve() {
  string s;
  for (int i = 0; i < 9; i++) {
    cin >> s;
    for (int j = 0; j < 9; j++) {
      sdk[i][j] = s[j] - '0';
      if (sdk[i][j] == 0) {
        V.push_back({i, j});
      }
    }
  }
  bt(0);
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