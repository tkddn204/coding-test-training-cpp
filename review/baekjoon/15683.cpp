#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define x first
#define y second

int n, m, l;
int office[10][10];
int temp[10][10];
pair<int, int> cctv[101];

bool isOut(int x, int y) {
  return x < 0 || x >= n || y < 0 || y >= m;
}

void insert(pair<int, int> cur, int dir) {
  int curX = cur.x;
  int curY = cur.y;

  while (true) {
    if (dir == 0) curY++; //오른쪽
    else if (dir == 1) curY--; // 왼쪽
    else if (dir == 2) curX--; // 위쪽
    else if (dir == 3) curX++; // 아래쪽
    if (isOut(curX, curY)) break;
    if (temp[curX][curY] == 6) break;
    if (temp[curX][curY] == 0)
      temp[curX][curY] = -1;
  }
}

void print() {
  for (int i = 0 ; i < n; i++) {
    for (int j = 0 ; j < m; j++) {
      cout << temp[i][j] << " ";
    }
    cout << endl;
  }
  cout << "------------------" << endl;
}

void solve() {
  cin >> n >> m;

  int res = 0;
  for (int i = 0 ; i < n; i++) {
    for (int j = 0 ; j < m; j++) {
      cin >> office[i][j];
      if (office[i][j] > 0 && office[i][j] < 6) {
        cctv[l++] = {i, j};
      }
      if (office[i][j] == 0) res++;
    }
  }

  // cctv의 상태는 최대 4가지이므로
  // cctv 하나당 한자리수로 설정
  // 예) cctv 3개 -> 001 -> 1상태/1상태/2상태
  int ms = (int)pow(4, l);
  for (int s = 0 ; s < ms; s++) {
    
    // 초기 상태 설정
    for (int i = 0 ; i < n; i++) {
      for (int j = 0 ; j < m; j++) {
        temp[i][j] = office[i][j];
      }
    }

    int turn = s;
    for (int i = 0; i < l; ++i) { 
      pair<int, int> cur = cctv[i];

      int dir = turn % 4;
      turn /= 4;

      int camera = office[cur.x][cur.y];
      if (camera == 1) { // 1번 - 오른쪽
        insert(cur, dir);
      } else if (camera == 2) { // 2번 - 위아래
        if (dir <= 2) {
          dir = 0;
          insert(cur, dir);
          insert(cur, dir + 1);
        } else {
          dir = 2;
          insert(cur, dir);
          insert(cur, dir + 1);
        }
      } else if (camera == 3) { // 3번 - 오른쪽과 직각
        insert(cur, dir / 2);
        insert(cur, (dir % 2) + 2);
      } else if (camera == 4) { // 4번 - 3방향
        for (int k = 0 ; k < 4; k++) {
          if (k == dir) continue;
          insert(cur, k);
        }
      } else { // 5번은 체크할 필요없음
        for (int k = 0 ; k < 4; k++) {
          insert(cur, k);
        }
      }
    }

    int count = 0;
    for (int i = 0 ; i < n; i++) {
      for (int j = 0 ; j < m; j++) {
        if (temp[i][j] == 0) count++;
      }
    }
    res = min(res, count);
  }

  cout << res;
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