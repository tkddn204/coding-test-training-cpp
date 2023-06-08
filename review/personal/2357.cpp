#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define X first
#define Y second

int n, m, a, b;
vector<int> arr;
vector<int> minTree, maxTree;

void init(int node, int start, int end) {
  if (start == end)
    minTree[node] = maxTree[node] = arr[start];
  else {
    init(node * 2, start, (start + end) / 2);
    init(node * 2 + 1, (start + end) / 2 + 1, end);
    minTree[node] = min(minTree[node * 2], minTree[node * 2 + 1]);
    maxTree[node] = max(maxTree[node * 2], maxTree[node * 2 + 1]);
  }
  return;
}

pair<int, int> query(int node, int start, int end, int left, int right) {
  if (left > end || right < start)
    return make_pair(INT_MAX, 0);
  else if (left <= start && end <= right)
    return make_pair(minTree[node], maxTree[node]);

  pair<int, int> l = query(node * 2, start, (start + end) / 2, left, right);
  pair<int, int> r =
      query(node * 2 + 1, (start + end) / 2 + 1, end, left, right);
  return make_pair(min(l.X, r.X), max(l.Y, r.Y));
}

void solve() {
  cin >> n >> m;

  int h = 1 << ((int)ceil(log2(n)) + 1);
  minTree = vector<int>(h);
  maxTree = vector<int>(h);

  arr.push_back(0);
  for (int i = 1; i <= n; i++) {
    cin >> a;
    arr.push_back(a);
  }
  init(1, 1, n);

  while (m--) {
    cin >> a >> b;
    pair<int, int> out = query(1, 1, n, a, b);
    cout << out.X << ' ' << out.Y << endl;
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