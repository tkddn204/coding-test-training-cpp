#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  int base;
  cin >> base;

  // 기본 풀이
  // 내가 푼 방식
  // vector<int> res;
  // for (int n = 2; n < base; n++) {
  //   bool isGood = true;
  //   for (int i = 0; i < base; i++) {
  //     for (int j = 0; j < base; j++) {
  //       for (int k = 0; k < base; k++) {
  //         if ((i + j*base + k*base*base) % n == 0
  //               and (i + j + k) % n != 0) {
  //                 isGood = false;
  //                 break;
  //         }
  //       }
  //       if (!isGood) break;
  //     }
  //     if (!isGood) break;
  //   }
  //   if (isGood) res.push_back(n);
  // }
  // for (auto r: res) cout << r << ' ';

  // 응용 기술
  // 수학적인 방법으로 식을 변환하여 답을 알아내는 방법
  for (int i = 2; i < base; i++) {
    if ((base - 1) % i == 0) cout << i << ' ';
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