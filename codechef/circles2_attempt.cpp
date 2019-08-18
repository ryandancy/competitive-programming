// Attempt at CIRCLES2 - Two Circles
// Written during August Cook-Off 2019
#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20);
  int T;
  cin >> T;
  while (T--) {
    ll x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    if ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) <= (r2-r1)*(r2-r1) && r2 >= r1) {
      cout << "NO\n";
      continue;
    }
    cout << "YES\n";
    if ((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1) > r1+r2) {
      cout << x1 << ".000000 " << y1 << ".000000\n";
      continue;
    }
    if (x1 == x2) {
      if (y1 > y2) {
        cout << x1 << ".000000 " << y1+r1 << ".000000\n";
      } else {
        cout << x1 << ".000000 " << y1-r1 << ".000000\n";
      }
      continue;
    }
    ld m = (ld)(y2-y1) / (ld)(x2-x1);
    ld y = y1, x = x1, r = r1, yx = y2, xx = x2, rx = r2;
    ld b = y-m*x;
    ld d = sqrtl((m*b-x-m*y)*(m*b-x-m*y)-(m*m+1)*(x*x+y*y-r*r-2*b*y));
    ld dx = sqrtl((m*b-xx-m*yx)*(m*b-xx-m*yx)-(m*m+1)*(xx*xx+yx*yx-r*r-2*b*yx));
    ld xa = (x+m*y-m*b+d)/(m*m+1);
    ld ya = m*xa+b;
    ld xxa = (xx+m*yx-m*b+dx)/(m*m+1);
    ld yxa = m*xxa+b;
    ld xq = (xa+xxa)/2;
    ld yq = (ya+yxa)/2;
    if ((xx-xa)*(xx-xa) + (yx-ya)*(yx-ya) - rx*rx > 1e-6) {
      cout << xa << ' ' << ya << '\n';
      continue;
    }
    ld xb = (x+m*y-m*b-d)/(m*m+1);
    ld yb = m*xb+b;
    ld xxb = (xx+m*yx-m*b-dx)/(m*m+1);
    ld yxb = m*xxb+b;
    xq = (xb+xxb)/2;
    yq = (yb+yxb)/2;
    cout << xb << ' ' << yb << '\n';
  }
}
