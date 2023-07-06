#include <bits/stdc++.h>
using namespace std;

#ifdef ONLINE_JUDGE
constexpr bool ndebug = true;
#else
constexpr bool ndebug = false;
#endif

#define endl "\n"
#define dbgl(x) \
    if constexpr (!ndebug) cout << #x << endl
#define dbg(x) \
    if constexpr (!ndebug) cout << x
#define dbge(x, e) \
    if constexpr (!ndebug) cout << x << e

int r, c, m;
int mp[102][102];
int tmp[102][102];
int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};
struct shark {
  int idx;
  int x, y;
  int s; // 속력
  int d; // 이동방향
  int z; // 크기
};
vector<shark> sharks;
vector<shark> chk[102][102];

void printMap(int k) {
  for (int i = 1; i <= c; i++) {
    if (i == k) {
      dbg("V ");
    } else {
      dbg("- ");
    }
  }
  dbg(endl);
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (mp[i][j] == 0) {
        dbge(0, ' ');
      } else {
        dbge((char)('A' + mp[i][j] - 1), ' ');
      }
    }
    dbg(endl);
  }
  dbge("----------------", endl);
}

int catchShark(int k) {
  for (int i = 1; i <= r; i++) {
    if (mp[i][k] > 0) {
      int size = sharks[mp[i][k]].z;
      sharks[mp[i][k]] = {};
      mp[i][k] = 0;
      return size;
    }
  }
  return 0;
}

void moveShark() {
  for (int i = 1; i <= r; i++) {
    fill(tmp[i] + 1, tmp[i] + c + 1, 0);
  }

  for (int i = 1; i <= m; i++) {
    auto& sk = sharks[i];
    if (sk.z < 1) continue;

    int s;
    if (sk.d <= 2) {
      s = sk.s % ((r - 1) * 2);
    } else {
      s = sk.s % ((c - 1) * 2);
    }
    while (s--) {
      // dbge(sk.d, ")");
      // dbge(dx[sk.d], ',');
      // dbge(dy[sk.d], " > ");
      // dbge(sk.x, ',');
      // dbge(sk.y, " -> ");
      sk.x += dx[sk.d];
      sk.y += dy[sk.d];
      if (sk.d <= 2) {
        if (sk.x <= 0 or sk.x > r) {
          sk.d += (sk.d % 2 == 0) ? -1 : 1;
          if (r == 1) sk.x = 1;
          else if (sk.x <= 0) sk.x = 2;
          else sk.x = r - 1;
        }
      } else {
        if (sk.y <= 0 or sk.y > c) {
          sk.d += (sk.d % 2 == 0) ? -1 : 1;
          if (c == 1) sk.y = 1;
          else if (sk.y <= 0) sk.y = 2;
          else sk.y = c - 1;
        }
      }
      // dbge(sk.x, ',');
      // dbge(sk.y, " (");
      // dbge(sk.d, endl);
    }
    chk[sk.x][sk.y].push_back(sk);
  }

  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      if (!chk[i][j].empty()) {
        sort(chk[i][j].begin(), chk[i][j].end(),
            [](shark& a, shark& b) -> bool {
              return a.z > b.z;
            });
        tmp[i][j] = chk[i][j][0].idx;
        for (int k = 1; k < chk[i][j].size(); k++) {
          sharks[chk[i][j][k].idx] = {};
        }
        chk[i][j].clear();
      }
    }
  }
  for (int i = 1; i <= r; i++) {
    for (int j = 1; j <= c; j++) {
      mp[i][j] = tmp[i][j];
    }
  }
}

void solve() {
  cin >> r >> c >> m;
  sharks.push_back({}); // 편의상 1부터 시작
  for (int i = 1; i <= m; i++) {
    int x, y, s, d, z;
    cin >> x >> y >> s >> d >> z;
    sharks.push_back({i, x, y, s, d, z});
    if (mp[x][y] > 0) {
      if (sharks[mp[x][y]].z < z) {
        sharks[mp[x][y]] = {};
        mp[x][y] = i;
      }
    } else {
      mp[x][y] = i;
    }
  }

  if (m == 0) {
    cout << 0;
    return;
  }
  
  int sum = 0;
  for (int k = 1; k <= c; k++) {
    sum += catchShark(k);
    moveShark();
    //printMap(k);
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