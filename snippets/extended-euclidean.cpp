#include <bits/stdc++.h>
typedef long long ll;

// solve a*x + b*y = gcd(a,b), put gcd(a,b) in d
// solutions are:
// x = x0 + k*b/gcd
// y = y0 - k*a/gcd
void euclid(ll a, ll b, ll&x, ll&y, ll&d) {
  if (b) euclid(b, a%b, y, x, d), y-=x*(a/b);
  else x=1, y=0, d=a;
}

// solve a*x + b*y = c
bool find_any_solution(ll a, ll b, ll c, ll&x0, ll&y0, ll&g) {
  euclid(abs(a), abs(b), x0, y0, g);
  if (c%g != 0) return false;
  x0 *= c/g;
  y0 *= c/g;
  if (a<0) x0=-x0;
  if (b<0) y0=-y0;
  return true;
}
