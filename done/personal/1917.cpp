#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int mp[7][7];
int expansion[7][7];
int blueprint[11][3][5];

int xlen, ylen;

void printExpansion() {
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      cout << expansion[i][j] << ' ';
    }
    cout << endl;
  }
  cout << "----------------" << endl;
}

void initBlueprint() {
  for (int b = 0; b < 6; b++) {
    if (b < 4) {
      blueprint[b][0][0] = 1;
      blueprint[b][2][b] = 1;
    } else {
      blueprint[b][0][1] = 1;
      blueprint[b][2][b - 3] = 1;
    }
    for (int j = 0; j < 4; j++) {
      blueprint[b][1][j] = 1;
    }
  }
  
  for (int b = 6; b < 9; b++) {
    blueprint[b][0][0] = blueprint[b][0][1] = 1;
    for (int j = 1; j <= 3; j++) {
      blueprint[b][1][j] = 1;
    }
    blueprint[b][2][b - 5] = 1;
  }

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      blueprint[9][i][j + i] = 1;
    }
  }
  for (int j = 0; j < 3; j++) {
    blueprint[10][0][j] = 1;
  }
  for (int j = 0; j < 3; j++) {
    blueprint[10][1][j + 2] = 1;
  }
  // for (int i = 0; i < 11; i++) {
  //   cout << '#' << (i + 1) << endl;
  //   for (int j = 0; j < 3; j++) {
  //     for (int k = 0; k < 5; k++) {
  //       cout << blueprint[i][j][k] << ' ';
  //     }
  //     cout << endl;
  //   }
  //   cout << endl;
  // }
}

void findExpansion() {
  for (int i = 0; i < 6; i++)
    fill(expansion[i], expansion[i] + 6, 0);

  int minx = 7, maxx = 0;
  int miny = 7, maxy = 0;
  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      if (mp[i][j] == 1) {
        minx = min(minx, i);
        maxx = max(maxx, i);
        miny = min(miny, j);
        maxy = max(maxy, j);
      }
    }
  }
  xlen = maxx - minx + 1;
  ylen = maxy - miny + 1;
  if (xlen > ylen) {
    for (int i = 0; i < xlen; i++) {
      for (int j = 0; j < ylen; j++) {
        expansion[j][i] = mp[minx + i][miny + j];
      }
    }
    swap(xlen, ylen);
  } else {
    for (int i = 0; i < xlen; i++) {
      for (int j = 0; j < ylen; j++) {
        expansion[i][j] = mp[minx + i][miny + j];
      }
    }
  }
}

void invertExpansion(int d) {
  // 0 -> 아래, 1 -> 오른쪽, 2 -> 위
  int temp[7][7], rearrange[7][7];
  for (int i = 0; i < 6; i++)
    fill(rearrange[i], rearrange[i] + 6, 0);
  
  if (d % 2 == 0) {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        temp[i][j] = expansion[6 - i - 1][j];
      }
    }
    for (int i = 0; i < xlen; i++) {
      for (int j = 0; j < 6; j++) {
        rearrange[i][j] = temp[6 - xlen + i][j];
      }
    }
  } else {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        temp[i][j] = expansion[i][6 - j - 1];
      }
    }
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < ylen; j++) {
        rearrange[i][j] = temp[i][6 - ylen + j];
      }
    }
  }

  for (int i = 0; i < 6; i++) {
    for (int j = 0; j < 6; j++) {
      expansion[i][j] = rearrange[i][j];
    }
  }

  // printExpansion();
}

bool isAble() {
  for (int b = 0; b < 11; b++) {
    int cnt = 0;
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        cnt += blueprint[b][i][j] and expansion[i][j];
      }
    }
    if (cnt == 6) return true;
  }
  return false;
}

void solve() {
  int t = 3;
  initBlueprint();
  while (t--) {
    for (int i = 0; i < 6; i++) {
      for (int j = 0; j < 6; j++) {
        cin >> mp[i][j];
      }
    }

    findExpansion();
    if (isAble()) {
      cout << "yes" << endl;
      continue;
    } else {
      bool isYes = false;
      for (int i = 0; i < 3; i++) {
        invertExpansion(i);
        isYes = isAble();
        if (isYes) break;
      }
      if (isYes) cout << "yes" << endl;
      else cout << "no" << endl;
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