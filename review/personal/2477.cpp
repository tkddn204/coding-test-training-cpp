#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define D first
#define M second

vector<pair<int ,int>> line;

void solve() {
  int k;
  cin >> k;
  for (int i = 0; i < 6; i++) {
    int d, m;
    cin >> d >> m;
    line.push_back({d, m});
  }

  int big = 0, s = 0;
  for (int i = 0; i < 6; i++) {
    int t = line[i].M * line [(i + 1) % 6].M;
    if (big < t) big = t, s = i;
  }
  big -= line[(s + 3) % 6].M * line[(s + 4) % 6].M;
  cout << big * k;
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