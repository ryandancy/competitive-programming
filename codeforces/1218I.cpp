// 1218I - The Light Square
// Just propagate through and try to make everything work, give up if it doesn't
// O(Nˆ2)? which I think is optimal?
#include <bits/stdc++.h>
using namespace std;
int st[2000][2000];
int en[2000][2000];
int d[2000][2000];
int c[2000][2000] = {{0}};
int w[2000];
bool row[2000] = {false};
bool col[2000] = {false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int N;
  cin >> N;
  string s;
  for (int y = 0; y < N; y++) {
    cin >> s;
    for (int x = 0; x < N; x++) {
      st[y][x] = s[x] == '1';
    }
  }
  for (int y = 0; y < N; y++) {
    cin >> s;
    for (int x = 0; x < N; x++) {
      en[y][x] = s[x] == '1';
    }
  }
  cin >> s;
  for (int x = 0; x < N; x++) {
    w[x] = s[x] == '1';
  }
  for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      d[y][x] = (st[y][x] != en[y][x]);
      if (d[y][x] && !w[x] && !w[y]) {
        cout << "-1\n";
        return 0;
      }
    }
  }
  int next = 0;
  stack<int> todo;
  while (1) {
    int curr;
    if (todo.size()) {
      curr = todo.top(); todo.pop();
    } else {
      curr = next++;
      if (curr >= N*N) break;
    }
    int y = curr/N, x = curr%N;
    // debug(x, y, c[y][x], col[x], row[y]);
    if (d[y][x]) {
      if ((col[x] && w[y]) && (row[y] && w[x])) return cout << "-1\n", 0;
      if ((col[x] && w[y]) != (row[y] && w[x])) continue;
    } else {
      if ((col[x] && w[y]) == (row[y] && w[x])) continue;
    }
    if (w[x] && !row[y]) { // use row even in both case
      for (int i = 0; i < N; i++) {
        if (!w[i]) continue;
        c[y][i]++;
        if (c[y][i] >= (d[y][i] ? 2 : 3)) return cout << "-1\n", 0;
        if (!d[y][i] && c[y][i] == 1) todo.push(y*N+i);
      }
      row[y] = true;
    } else { // use column
      if (!w[y] || col[x]) return cout << "-1\n", 0;
      for (int i = 0; i < N; i++) {
        if (!w[i]) continue;
        c[i][x]++;
        if (c[i][x] >= (d[i][x] ? 2 : 3)) return cout << "-1\n", 0;
        if (!d[i][x] && c[i][x] == 1) todo.push(i*N+x);
      }
      col[x] = true;
    }
  }
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (row[i]) cnt++;
    if (col[i]) cnt++;
  }
  cout << cnt << "\n";
  for (int i = 0; i < N; i++) {
    if (row[i]) cout << "row " << i << "\n";
    if (col[i]) cout << "col " << i << "\n";
  }
  // for (int y = 0; y < N; y++) for (int x = 0; x < N; x++) {
  //   debug(x, y, d[y][x]);
  // }
  /*for (int y = 0; y < N; y++) {
    for (int x = 0; x < N; x++) {
      if (d[y][x] && c[y][x] == 0 && w[x] != w[y]) {
        for (int i = 0; i < N; i++) {
          if (!w[i]) continue;
          if (w[x]) {
            c[i][y]++;
            if (d[i][y] && c[i][y] > 1) return cout << "-1\n", 0;
          } else {
            c[x][i]++;
            if (d[x][i] && c[x][i] > 1) return cout << "-1\n", 0;
          }
        }
        if (w[x]) col[x] = true;
        else row[y] = true;
      }
    }
  }
  bool didsth;
  do {
    didsth = false;
    for (int y = 0; y < N; y++) {
      for (int x = 0; x < N; x++) {
        if (d[y][x]) {
          if (c[y][x] != 0) continue;
          
        } else if (c[y][x] == 1) {
          if (w[x] != w[y]) return cout << "-1\n", 0;
          if (row[y]) {
            // do col=x
            for (int i = 0; i < N; i++) {
              if (!w[i]) continue;
              c[x][i]++;
              if (c[x][i] > 1) return cout << "-1\n", 0;
            }
            col[x] = true;
          } else {
            // do row=y
            for (int i = 0; i < N; i++) {
              if (!w[i]) continue;
              c[i][y]++;
              if (c[i][y] > 1) return cout << "-1\n", 0;
            }
            row[y] = true;
          }
          didsth = true;
        }
      }
    }
  } while (didsth);*/
  
}
