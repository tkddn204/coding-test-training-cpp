#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

vector<int> numbers;
void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    numbers.push_back(k);
  }

  // 기본 풀이
  // ll ans = 0;
  // for (int i = 0; i < numbers.size(); i++) {
  //   ll tmp = 1;
  //   for (int j = 0; j < numbers.size(); j++) {
  //     if (i == j) {
  //       tmp *= (numbers[j] + 1);
  //     } else {
  //       tmp *= (numbers[j]);
  //     }
  //   }
  //   ans = max(ans, tmp);
  // }
  // cout << ans;

  // 응용 기술
  // 가장 작은 숫자에 + 1하면 됨
  ll ret = 1;
  sort(numbers.begin(), numbers.end());
  numbers[0]++;
  for (auto num : numbers) ret *= num;
  cout << ret;
  
  // 내가 푼 방식
  // 다 곱한거에서 하나씩 나누고 1 더하고 곱한걸 계속 비교
  // int mul = 1;
  // int res = 0;
  // for (auto num : numbers) mul *= num;
  // for (auto num : numbers) {
  //   res = max(res, (mul / num) * (num + 1));
  // }
  // cout << res;
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