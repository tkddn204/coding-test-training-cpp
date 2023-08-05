#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<string> friends;

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    friends.push_back(s);
  }


  // 기본 풀이
  // 보고 배움
  // 2-friends 라는 말을 일찍이 봤으면 문제 이해가 빨랐을듯
  int maxFriend = 0;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      if (friends[i][j] == 'Y') cnt++;
      else {
        for (int k = 0; k < n; k++) {
          if (friends[j][k] == 'Y' and friends[k][j] == 'Y') {
            cnt++;
            break;
          }
        }
      }
    }
    maxFriend = max(maxFriend, cnt);
  }
  cout << maxFriend;
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