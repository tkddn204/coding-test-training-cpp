#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<string> fst;
vector<string> scd;

void solve() {
  int n;
  cin >> n;
  string s;
  for (int i = 0; i < n; i++) {
    cin >> s;
    fst.push_back(s);
  }
  for (int i = 0; i < n; i++) {
    cin >> s;
    scd.push_back(s);
  }

  // 기본 풀이
  // int res = 0;
  // for (int i = 0; i < fst.size(); i++) {
  //   int f = 0, s = 0;
  //   for (int j = 0; j < fst.size(); j++) {
  //     if (fst[i] == fst[j]) f++;
  //     if (fst[i] == scd[j]) f++;
  //     if (scd[i] == fst[j]) s++;
  //     if (scd[i] == scd[j]) s++;
  //   }
  //   res = max(res, f);
  //   res = max(res, s);
  // }
  // cout << res;
  
  // 응용 기술 1
  // 내가 푼 방식
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    mp[fst[i]]++;
    mp[scd[i]]++;    
  }
  int maxVal = 0;
  for (auto e: mp) {
    maxVal = max(maxVal, e.second);
  }
  cout << maxVal;
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