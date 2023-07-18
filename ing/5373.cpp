#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

map<char, int> plane = {
  {'U', 0}, {'D', 1}, {'F', 2},
  {'B', 3}, {'L', 4}, {'R', 5}
};
char color[6] = {'w', 'y', 'r', 'o', 'g', 'b'};
char cube[6][3][3];

void printCube(int p) {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cout << cube[p][i][j] << ' ';
    }
    cout << endl;
  }
  cout << "-------------" << endl;
}

void initCube() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 3; j++) {
      fill(cube[i][j], cube[i][j] + 3, color[i]);
    }
  }
}

void shiftSide(int p) {
  // 옆면 회전
  vector<int> pi;
  int pj;
  if (p <= 1) {
    pi = {3, 5, 2, 4};
    pj = p % 2 == 0 ? 0 : 2;
  } else if (p <= 3) {
    pi = {0, 5, 1, 4};

  } else {
    pi = {0, 3, 1, 2};
  }
  
  char tmp[4][3][3];
  cout << p << endl;
  for (int i = 0; i < 4; i++) {
    int ci = pi[i];
    cout << ci << ' ';
    int ni = (i + 1) % 4;
    for (int k = 0; k < 3; k++) {
      tmp[ni][pj][k] = cube[ci][pj][k];
    }
  }
  cout << endl;

  for (int i = 0; i < 4; i++) {
    int ci = pi[i];
    for (int k = 0; k < 3; k++) {
      cube[ci][pj][k] = tmp[i][pj][k];
    }
  }
}

void rotateAndShift(int p, char d) {
  // 앞면 회전
  char tmp[3][3];
  if (d == '+') { // 시계
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        tmp[i][j] = cube[p][3 - j - 1][i];
      }
    }
  } else { // 반시계
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < 3; j++) {
        tmp[i][j] = cube[p][j][3 - i - 1];
      }
    }
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cube[p][i][j] = tmp[i][j];
    }
  }

  // 옆면 회전
  if (d == '+') shiftSide(p);
  else {
    for (int i = 0; i < 3; i++) shiftSide(p);
  }
}

void solve() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;
    initCube();
    for (int i = 0; i < n; i++) {
      string s;
      cin >> s;
      char p = plane[s[0]];
      char d = s[1];
      rotateAndShift(p, d);
    }
    printCube(0);
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