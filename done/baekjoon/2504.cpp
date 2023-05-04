#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

void solve() {
  stack<char> s;
  string str;
  int sum = 0, n = 1, t;
  bool isGood = true;
  cin >> str;
  for (int i = 0 ; i < str.length(); ++i) {
    if (str[i] == '(') {
      s.push(str[i]);
      n *= 2;
    } else if (str[i] == '[') {
      s.push(str[i]);
      n *= 3;
    } else if (str[i] == ')') {
      if (s.empty() || s.top() != '(') {
        isGood = false;
        break;
      }

      if (str[i-1] == '(') sum += n;
      s.pop();
      n /= 2;
    } else {
      if (s.empty() || s.top() != '[') {
        isGood = false;
        break;
      }

      if (str[i-1] == '[') sum += n;
      s.pop();
      n /= 3;
    }
    if (!isGood) break;
  }

  if (s.empty() && isGood) cout << sum;
  else cout << 0;
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