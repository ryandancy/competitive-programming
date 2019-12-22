// 1181C - Flags
// O(n^2)-ish, just brute force all the individual flags and use 1+2+..+n = n(n+1)/2
// for the combinations. An exercise in reading the problem carefully: the third is not
// necessarily distinct from the first.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
string c[1000];
bool v[1000][1000] = {{false}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) cin >> c[i];
  ll r = 0;
  for (int i = 0; i < n-2; i++) {
    for (int j = 0; j < m; j++) {
      if (v[i][j]) continue;
      v[i][j] = true;
      if (c[i][j] != c[i+1][j] && c[i+1][j] != c[i+2][j]) {
        ll x = 1;
        for (int j2 = j+1; j2 < m; j2++) {
          if (c[i][j] == c[i][j2] && c[i+1][j] == c[i+1][j2] && c[i+2][j] == c[i+2][j2]) {
            x++;
            v[i][j2] = true;
          } else break;
        }
        r += x*(x+1)/2;
      } else if (c[i][j] == c[i+1][j]) {
        int h = 2;
        char c1 = c[i][j];
        for (int i2 = i+2; i2 < n; i2++) {
          if (c[i2][j] == c1) h++;
          else break;
        }
        if (i <= n-h*3) {
          char c2 = c[i+h][j];
          if (c1 == c2) continue;
          for (int i2 = i+h; i2 < i+2*h; i2++) {
            if (c[i2][j] != c2) goto nxt;
          }
          char c3 = c[i+2*h][j];
          if (c2 == c3) continue;
          for (int i2 = i+2*h; i2 < i+3*h; i2++) {
            if (c[i2][j] != c3) goto nxt;
          }
          ll x = 1;
          for (int j2 = j+1; j2 < m; j2++) {
            bool ok = true;
            for (int i2 = i; i2 < i+h; i2++) {
              if (c[i2][j2] != c1) {ok = false; break;}
            }
            if (!ok) break;
            for (int i2 = i+h; i2 < i+2*h; i2++) {
              if (c[i2][j2] != c2) {ok = false; break;}
            }
            if (!ok) break;
            for (int i2 = i+2*h; i2 < i+3*h; i2++) {
              if (c[i2][j2] != c3) {ok = false; break;}
            }
            if (!ok) break;
            v[i][j2] = true;
            x++;
          }
          r += x*(x+1)/2;
        }
      }
      nxt:;
    }
  }
  cout << r << "\n";
}
