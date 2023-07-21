#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int minVal = INT_MAX, maxVal = 0;
int arr[101][101];
bool vst[101][101];
int dx[] = {0, -1, 0, 1};
int dy[] = {1, 0, -1, 0};

bool BFS(int diff) {
  for (int v = minVal; v <= maxVal; v++) {
    for (int k = 0; k < n; k++)
      fill(vst[k], vst[k] + n, true);
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (v <= arr[i][j] and v + diff >= arr[i][j]) {
          vst[i][j] = false;
        }
      }
    }
    // for (int i = 0; i < n; i++) {
    //   for (int j = 0; j < n; j++) {
    //     cout << vst[i][j] << ' ';
    //   }
    //   cout << endl;
    // }
    // cout << "----------------" << endl;
    queue<pair<int, int>> Q;
    Q.push({0, 0});
    vst[0][0] = true;
    while (!Q.empty()) {
      auto [x, y] = Q.front(); Q.pop();
      
      for (int d = 0; d < 4; d++) {
        int nx = x + dx[d];
        int ny = y + dy[d];

        if (nx < 0 or nx >= n or ny < 0 or ny >= n) continue;
        if (vst[nx][ny]) continue;
        if (nx == n - 1 and ny == n - 1) return true;
        if (arr[nx][ny] < v) continue;
        Q.push({nx, ny});
        vst[nx][ny] = true;
      }
    }
  }
  return false;
}

int search() {
  int st = 0;
  int en = maxVal - minVal;
  int md;

  while (st <= en) {
    md = ((st + en) / 2) + 1;
    if (BFS(md)) en = md - 1;
    else st = md + 1;
    cout << md << endl;
  }
  return md;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      minVal = min(minVal, arr[i][j]);
      maxVal = max(maxVal, arr[i][j]);
    }
  }
  int res = search();
  cout << res;
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