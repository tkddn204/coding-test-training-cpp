#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  string s;
  cin >> s;

  // 기본 풀이
  // 보고 배웠음
  // 회문을 맞추기 위해 일부러 길이를 늘리지 않고,
  // 원래 있던 문자열을 최대한 이용해서 찾아가는 방법
  // int len = s.size();
  // bool isPal;
  // do {
  //   isPal = true;
  //   for (int j = 0; j < s.size(); j++) {
  //     if ((len - j - 1) < s.size() and s[j] != s[len - j - 1]) {
  //       isPal = false;
  //       break;
  //     }
  //   }
  // } while (!isPal && len++);
  // cout << len;
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