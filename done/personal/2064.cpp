#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

string str;
int netAddr[4] = {255, 255, 255, 255};
int netMask[4] = {255, 255, 255, 255};
int ip[1001][4];

void printIp(int* arr) {
  for (int i = 0; i < 4; i++) {
    cout << arr[i];
    if (i != 3) cout << '.';
  }
}

void ipTointArr(int o) {
  string s;
  int ipIdx = 0;
  for (auto c: str) {
    if (c == '.') {
      ip[o][ipIdx++] = stoi(s);
      s.clear();
    } else {
      s += c;
    }
  }
  ip[o][ipIdx] = stoi(s);
}

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> str;
    ipTointArr(i);
  }
  long mask = (1L << 32) - 1;
  int idx = 0;
  for (int j = 0; j < 4; j++) {
    bool isDiff = false;
    for (int d = 7; d >= 0; d--, idx++) {
      int t = (ip[0][j] & (1L << d)) >> d;
      for (int i = 1; i < n; i++) {
        int cur = (ip[i][j] & (1L << d)) >> d;
        if (t != cur) {
          isDiff = true;
          break;
        }
      }
      if (isDiff) break;
    }
    if (isDiff) {
      mask = ((1L << idx) - 1L) << (32-idx);
      break;
    }
  }
  for (int i = 3; i >= 0; i--) {
    long cur = mask >> (8 * i);
    netMask[3 - i] = (int)cur;
    mask -= cur << (8 * i);
  }
  for (int i = 0; i < 4; i++) {
    netAddr[i] = ip[0][i] & netMask[i];
  }
  printIp(netAddr);
  cout << endl;
  printIp(netMask);
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