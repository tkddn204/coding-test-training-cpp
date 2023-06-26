#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

char op[10];
int num[10];
void solve() {
  int n;
  cin >> n;

  for (int i = 0; i < n; i++) cin >> op[i];
  for (int i = 0; i <= 9; i++) num[i] = i;

  string minRes = "10000000000", maxRes = "0";
  do {
    bool isGood = true;
    for (int i = 0; i < n; i++) {
      if (op[i] == '<') {
        if (num[i] > num[i + 1]) {
          isGood = false;
          break;
        }
      } else {
        if (num[i] < num[i + 1]) {
          isGood = false;
          break;
        }
      }
    }
    if (!isGood) continue;
    
    long cur = 0;
    for (int i = 0; i <= n; i++) {
      cur *= 10;
      cur += num[i];
    }
    string res;
    for (int i = 0; i <= n; i++) {
      res += num[i] + '0';
    }

    long maxNum = stol(maxRes);
    long minNum = stol(minRes);
    if (maxNum < cur) maxRes = res;
    if (minNum > cur) minRes = res;
  } while (next_permutation(num, num + 10));
  cout << maxRes << endl;
  cout << minRes;
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