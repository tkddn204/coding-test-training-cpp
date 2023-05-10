#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second

int n, m;
int arr[55][55];
vector<pair<int,int>> home;
vector<pair<int,int>> store;


void solve() {
  cin >> n >> m;
  for (int i = 0 ; i < n; i++) {
    for (int j = 0 ; j < n; j++) {
      cin >> arr[i][j];
      if (arr[i][j] == 1) home.push_back({i, j});
      if (arr[i][j] == 2) store.push_back({i, j});
    }
  }

  vector<int> track(store.size(), 1);
  fill(track.begin(), track.begin() + store.size() - m, 0);

  int m = INT_MAX;

  do {
    int d = 0;
    for (auto h : home) {
      int t = INT_MAX;
      for (int i = 0 ; i < store.size(); i++) {
        if (track[i] == 0) continue;
        t = min(t, abs(store[i].x - h.x) + abs(store[i].y - h.y));
      }
      d += t;
    }
    m = min(m, d);
  } while(next_permutation(track.begin(), track.end()));

  cout << m;
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