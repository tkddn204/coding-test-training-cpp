#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int capacities[51];
int bottles[51];
int fromId[51];
int toId[51];

void solve() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> capacities[i] >> bottles[i];
  }
  int m;
  cin >> m;
  for (int i = 0; i < m; i++) {
    int from, to;
    cin >> from >> to;

    
    // 기본 풀이
    // 내가 푼 방식
    // if (bottles[from] == 0) continue;
    // if (bottles[to] >= capacities[to]) continue;

    // if (bottles[from] + bottles[to] <= capacities[to]) {
    //   bottles[to] += bottles[from];
    //   bottles[from] -= bottles[from];
    // } else {
    //   bottles[from] -= capacities[to] - bottles[to];
    //   bottles[to] = capacities[to];
    // }

    // 응용 풀이 1
    // int vol = min(bottles[from], capacities[to] - bottles[to]);
    // bottles[from] -= vol;
    // bottles[to] += vol;

    // 응용 풀이 2
    int sum = bottles[from] + bottles[to];
    bottles[to] = min(sum, capacities[to]);
    bottles[from] = sum - bottles[to];
  }
  
  for (int i = 0; i < n; i++) {
    cout << bottles[i] << ' ';
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