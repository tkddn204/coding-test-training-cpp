#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int n;
int arr[1001];
vector<int> two;

void solve() {
  cin >> n;
  for (int i = 0 ; i < n; i++) cin >> arr[i];
  sort(arr, arr+n);
  for (int i = 0 ; i < n ; i++) {
    for (int j = i + 1 ; j < n; j++) {
      two.push_back(arr[i] + arr[j]);      
    }
  }
  sort(two.begin(), two.end());
  for (auto t : two) {
    cout << t << " ";
  }
  cout << endl;
  for (int i = n - 1; i > 0; i--) {
    for (int j = 0; j < i; j++) {
      if (binary_search(two.begin(), two.end(), arr[i] - arr[j])) {
        cout << arr[i];
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