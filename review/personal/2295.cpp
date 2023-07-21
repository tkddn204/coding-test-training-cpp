#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int nums[1001];
vector<int> two;

bool existNum(int st, int en, int num) {

  while (st <= en) {
    int mid = (st + en) / 2;
    if (two[mid] == num) return true;
    if (two[mid] < num) st = mid + 1;
    else en = mid - 1;
  }

  return false;
}

void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> nums[i];    
  }
  sort(nums, nums + n);

  for(int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      two.push_back(nums[i] + nums[j]);
    }
  }
  sort(two.begin(), two.end());
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      int sum = nums[i] - nums[j];
      if (existNum(0, two.size(), sum)) {
        cout << nums[i];
        return;
      }
    }
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