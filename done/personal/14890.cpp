#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n, l;
int mp[101][101];
int chk[101];
int cnt = 0;

// 왼쪽 90도 돌리기
void rotate() {
  int tmp[101][101];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      tmp[i][j] = mp[j][n - 1 - i];
    }
  }
  
  for(int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      mp[i][j] = tmp[i][j];
      // cout << mp[i][j] << ' ';
    }
    // cout << endl;
  }
  // cout << "----------------" << endl;
}

void go() {
  for (int i = 0; i < n; i++) {
    fill(chk, chk + n, 0);
    bool possible = true;
    for (int j = 0; j < n - 1; j++) {
      int diff = mp[i][j] - mp[i][j + 1];
      // cout << diff << ' ';
      bool isFlat = true;
      if (diff == 1) { // []↘
        if (j + l >= n) {
          possible = false;
          break;
        }
        // 3 2
        int cur = mp[i][j + 1];
        for (int k = 1; k <= l; k++) {
          if (chk[j + k] || mp[i][j + k] != cur) {
            isFlat = false;
            break;
          }
        }
        if (!isFlat) {
          possible = false;
          break;
        } else {
          for (int k = 1; k <= l; k++) {
            chk[j + k] = 1;
          }
        }
      } else if (diff == -1) { // ↙[]
        if (j - l + 1 < 0) {
          possible = false;
          break;
        }
        // 2 3
        int cur = mp[i][j];
        for (int k = 0; k < l; k++) {
          if (chk[j - k] || mp[i][j - k] != cur) {
            isFlat = false;
            break;
          }
        }
        if (!isFlat) {
          possible = false;
          break;
        } else {
          for (int k = 0; k < l; k++) {
            chk[j - k] = 1;
          }
        }
      } else if (diff > 1 || diff < -1) {
        possible = false;
        break;
      }
    }
    if (possible) {
      // cout << "GOOD";
      cnt++;
    }

    // cout << endl;
    // for (int k = 0; k < n; k++) {
    //   cout << chk[k] << ' ';
    // }
    // cout << endl << "------------" << endl;
  }

}

void solve() {
  cin >> n >> l;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> mp[i][j];      
    }
  }

  go();
  rotate();
  go();

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