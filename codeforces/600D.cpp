// 600D - Area of Two Circles' Intersection
// Lessons from this one:
// - do comparisons with integers if at all possible
// - use long double versions of functions for best precision
#include <bits/stdc++.h>
#define PI 3.14159265358979323846L
using namespace std;
typedef long double ld;
int main() {
  cout << setprecision(32);
  long long x1, y1, r1, x2, y2, r2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  
  long long ds = (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
  
  if (ds >= (r1+r2)*(r1+r2)) {
    cout << 0 << endl;
    return 0;
  }
  
  if (ds <= (r1-r2)*(r1-r2)) {
    cout << PI*min(r1, r2)*min(r1, r2) << endl;
    return 0;
  }
  
  ld d = sqrtl(ds);
  ld a = acosl((r2*r2+d*d-r1*r1)/(2.0L*r2*d)), b = acosl((r1*r1+d*d-r2*r2)/(2.0L*r1*d));
  ld res = r2*r2*(a - sinl(a)*cosl(a)) + r1*r1*(b - sinl(b)*cosl(b));
  cout << res << endl;
}
