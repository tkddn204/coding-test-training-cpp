#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define INF (int)1e9

// 쭉 지나가면서 체크 배열에 x가 만들어지는지를
// 체크해놓는 방법. O(n)
int n, x, a[100001];
int r, c[2000001];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  cin >> x;

  for (int i = 0 ; i < n; i++) {
    if (x > a[i] && x - a[i] <= 1000000 && c[x - a[i]]) r++;
    ++c[a[i]];
  }
  cout << r;
}

// 주어진 수의 반 이하만이 더해진다는 이론을
// 사용한 방법. O(n+x)
int arr[2000001];
void solve2() {
  int n, x, r = 0;
  cin >> n;
  while(n--) {
    cin >> x;
    arr[x] = true;
  }
  cin >> x;

  for (int i = 1 ; i < (x+1)/2 ; i++) {
    if (arr[i] && arr[x-i]) r++;
  }
  cout << r;
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