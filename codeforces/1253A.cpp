#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int a[100000];
int b[100000];
int d[100000];
int o = 0;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i+o];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i+o];
    }
    bool s = false;
    bool sd = false;
    int r = -1;
    for (int i = 0; i < n; i++) {
      d[i+o] = b[i+o] - a[i+o];
      if (d[i+o] != 0) {
        if (d[i+o]<0) {cout << "NO\n"; goto nxt;}
        if (sd) { cout << "NO\n"; goto nxt;}
        if (s) {
          if (d[i+o] != r) {
            cout << "NO\n";
            goto nxt;
          }
        } else {
          s = true;
          r = d[i+o];
        }
      } else if (s) {
        sd = true;
      }
    }
    cout << "YES\n";
    nxt:;
    o+=n;
  }
}
