#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<int> gear[5];
int vst[5];

void shift(int n, int dis) {
  if (dis == 1) {  // 시계
    rotate(gear[n].begin(), gear[n].end() - 1, gear[n].end());
  } else if (dis == -1) {  // 반시계
    rotate(gear[n].begin(), gear[n].begin() + 1, gear[n].end());
  }
}

void check(int n, int dis) {
  vst[n] = dis;
  while (n < 4 && gear[n].at(2) != gear[n + 1].at(6)) {
    vst[n + 1] = -vst[n];
    n++;
  }

  while (n > 1 && gear[n].at(6) != gear[n - 1].at(2)) {
    vst[n - 1] = -vst[n];
    n--;
  }

  for (int i = 1; i <= 4; i++) {
    shift(i, vst[i]);
  }
}

void solve() {
  string t;
  for (int i = 1; i <= 4; i++) {
    cin >> t;
    for (auto c : t) {
      gear[i].push_back(c - '0');
    }
  }
  int k, n, d;
  cin >> k;
  for (int i = 0; i < k; i++) {
    cin >> n >> d;
    fill(vst, vst + 5, 0);
    check(n, d);
  }

  int res = 0;
  for (int i = 1; i <= 4; i++) {
    if (gear[i].front()) res += 1 << (i - 1);
  }
  cout << res << endl;
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