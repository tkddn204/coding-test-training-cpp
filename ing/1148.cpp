#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<string> dic;
vector<string> pan;
string minStr[200001], maxStr[200001];

void solve() {
  while (true) {
    string s;
    cin >> s;
    if (s[0] == '-') break;
    dic.push_back(s);
  }
  while (true) {
    string s;
    cin >> s;
    if (s[0] == '#') break;
    pan.push_back(s);
  }

  for (auto p : pan) {
    set<string> sel;

    for (auto d : dic) {
      int vst[10] = {}, len = 0;
      for (int i = 0; i < p.size(); i++) {
        for (auto c : d) {
          if (vst[i]) continue;
          if (c == p[i]) {
            vst[i] = true;
            len++;
          }
        }
        if (d.size() == len) {
          sel.insert(d);
        }
      }
    }
    // for (auto s : sel) cout << s << endl;
    
    int minCnt = 200001, maxCnt = -1;
    for (int i = 0; i < 200001; i++) {
      minStr[i].clear();
      maxStr[i].clear();
    }
    for (auto mid : p) {
      int cnt = 0;
      for (auto s: sel) {
        bool isMid = false;
        for (auto c : s) {
          if (c == mid) {
            isMid = true;
            break;
          }
        }
        cnt += isMid;
      }
      
      if (cnt <= minCnt) {
        minCnt = cnt;
        minStr[minCnt] += mid;
      }

      if (cnt >= maxCnt) {
        maxCnt = cnt;
        maxStr[maxCnt] += mid;
      }
    }
    string minRes;
    for (auto c : minStr[minCnt]) {
      if (minRes.find(c) == -1) minRes += c;
    }
    string maxRes;
    for (auto c : maxStr[maxCnt]) {
      if (maxRes.find(c) == -1) maxRes += c;
    }
    sort(minRes.begin(), minRes.end());
    sort(maxRes.begin(), maxRes.end());
    cout << minRes << ' ' << minCnt << ' ';
    cout << maxRes << ' ' << maxCnt << endl;
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