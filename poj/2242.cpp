#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <algorithm>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ld x1, y1, x2, y2, x3, y3;
  while (cin>>x1>>y1>>x2>>y2>>x3>>y3) {
    ld e=(x3-x1)/2.0, f=(y3-y1)/2.0;
    ld a=y2-y1, b=x1-x2, c=y2-y3, d=x3-x2;
    ld s=(d*e-c*f)/(a*d-b*c);
    ld x=a*s+(x1+x2)/2.0, y=b*s+(y1+y2)/2.0;
    ld C=2*PI*hypot(x-x1, y-y1);
    printf("%.2Lf\n", C);
  }
}
