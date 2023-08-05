#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define ll long long

vector<string> relations;
ll dp[50];

ll getSalary(int i) {
  if (dp[i] != 0) return dp[i];
  ll salary = 0;
  string relation = relations[i];

  for (int j = 0; j < relation.size(); j++) {
    if (relation[j] == 'Y') {
      salary += getSalary(j);
    }
  }
  if (salary == 0) salary = 1;
  return dp[i] = salary;
}

void solve() {
  string s;
  while (cin >> s) relations.push_back(s);
  
  ll sum = 0;
  for (int i = 0; i < relations.size(); i++) {
    sum += getSalary(i);
  }
  cout << sum;
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