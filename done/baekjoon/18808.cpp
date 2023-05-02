#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

const int MX = 41;
int n, m, k;
int r, c, a;
int monun[MX][MX];
int shape[12][12];

class Sticker {
public:
  Sticker(int width, int height) {
    r = width;
    c = height;
  }

  void set(int x, int y, int val) {
    shape[x][y] = val;
  }

  int get(int x, int y) {
    return shape[x][y];
  }

  void rotate() {
    int tp[12][12];
    for (int i = 0; i < r; i++) {
      for (int j = 0 ; j < c; j++) {
        tp[j][r - i - 1] = shape[i][j];
      }
    }
    swap(r, c);
    for (int i = 0; i < r; i++) {
      for (int j = 0 ; j < c; j++) {
        shape[i][j] = tp[i][j];
      }
    }
  }

  bool isPastable(int x, int y) {
    //this->print();
    for (int i = 0 ; i < r; i++) {
      for (int j = 0 ; j < c; j++) {
        if (shape[i][j] && monun[x + i][y + j]) {
          return false;
        }
      }
    }
    return true;
  }

  void print() {
    for (int i = 0; i < r; i++) {
      for (int j = 0 ; j < c; j++) {
        cout << shape[i][j] << " ";
      }
      cout << endl;
    }
    cout << "----------------" << endl;
  }
};

void solve() {
  cin >> n >> m >> k;
  while(k--) {
    cin >> r >> c;
    Sticker st(r, c);
    for (int i = 0 ; i < r; i++) {
      for (int j = 0 ; j < c; j++) {
        cin >> a;
        st.set(i, j, a);
      }
    }

    for (int t = 0; t < 4; t++) {
      bool isPaste = false;
      for (int x = 0 ; x <= n - r; x++) {
        for (int y = 0 ; y <= m - c; y++) {
          if (st.isPastable(x, y)) {
            for (int i = 0 ; i < r; i++) {
              for (int j = 0 ; j < c; j++) {
                if (st.get(i, j)) {
                  monun[x + i][y + j] = 1;
                }
              }
            }
            isPaste = true;
            break;
          }
        }
        if (isPaste) break;
      }
      if (isPaste) break;
      st.rotate();
    }
  }

  int count = 0;
  for (int i = 0 ; i < n; i++) {
    for (int j = 0 ; j < m; j++) {
      count += monun[i][j];
    }
  }
  cout << count;
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