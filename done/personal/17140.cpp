#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second
#define INIT(a) for(int i = 0; i < 101; i++) fill(a[i], a[i]+101, 0)


int r, c, k;
int arr[101][101];
int tmp[101][101];

void printArr(int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << arr[i][j] << ' ';
    }
    cout << endl;
  }
}

// 행 정렬
void R(int& row, int& col) {
  INIT(tmp);

  for (int i = 0; i < row; i++) {
    map<int, int> mp;
    vector<pair<int, int>> cnt;
    for (int j = 0; j < col; j++) {
      if (arr[i][j] == 0) continue;
      mp[arr[i][j]]++;
    }
    for (int k = 0; k < 101; k++) {
      if (mp[k] == 0) continue;
      cnt.push_back({mp[k], k});
    }
    sort(cnt.begin(), cnt.end());

    int k = 0;
    for (auto e : cnt) {
      if (k >= 100) break;
      tmp[i][k++] = e.Y;
      tmp[i][k++] = e.X;
    }
    col = max(col, k);
  }

  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      arr[i][j] = tmp[i][j];
    }
  }
}

// 열 정렬
void C(int& row, int& col) {
  INIT(tmp);

  for (int j = 0; j < col; j++) {
    map<int, int> mp;
    vector<pair<int, int>> cnt;
    for (int i = 0; i < row; i++) {
      if (arr[i][j] == 0) continue;
      mp[arr[i][j]]++;
    }

    for (int k = 0; k < 101; k++) {
      if (mp[k] == 0) continue;
      cnt.push_back({mp[k], k});
    }
    sort(cnt.begin(), cnt.end());

    int k = 0;
    for (auto e : cnt) {
      if (k >= 100) break;
      tmp[k++][j] = e.Y;
      tmp[k++][j] = e.X;
    }
    row = max(row, k);
  }

  for (int i = 0; i < 101; i++) {
    for (int j = 0; j < 101; j++) {
      arr[i][j] = tmp[i][j];
    }
  }
}

void solve() {
  cin >> r >> c >> k;
  r--, c--;

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> arr[i][j];
    }
  }

  if (arr[r][c] == k) {
    cout << 0;
    return;
  }
  
  int row = 3, col = 3;

  int t = -1;
  while (t++ <= 100) {
    if (arr[r][c] == k) break;
    if (row >= col) R(row, col);
    else C(row, col);
  }

  if (t > 100) cout << -1;
  else cout << t;
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