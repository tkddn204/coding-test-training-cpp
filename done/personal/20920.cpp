#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

vector<string> words;
map<string, int> cnt;

bool cmp(string& a, string& b) {
  if (cnt[a] != cnt[b]) return cnt[a] > cnt[b];
  if (a.size() != b.size()) return a.size() > b.size();
  return a < b;
}

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    if (cnt.find(s) == cnt.end())
      words.push_back(s);
    cnt[s]++;
  }
  sort(words.begin(), words.end(), cmp);
  for (auto w: words) {
    if (w.size() >= m) {
      cout << w << endl;
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