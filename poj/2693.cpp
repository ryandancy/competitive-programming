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
#define EPS 1e-9L
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
vector<ld> xs, ys;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  {
    ld xp, yp;
    while (cin>>xp>>yp) {
      xs.push_back(xp), ys.push_back(yp);
    }
  }
  int n=xs.size();
  int res=1;
  for (int i=0;i<n;i++) {
    ld x1=xs[i], y1=ys[i];
    for (int j=i+1;j<n;j++) {
      ld x2=xs[j], y2=ys[j];
      ld d=hypotl(x1-x2, y1-y2)/2.0L;
      if (d>2.5L+EPS)continue;
      ld x=(x1+x2)/2.0, y=(y1+y2)/2.0L;
      ld s=sqrtl(6.25L-d*d);
      
      ld dx=y-y1, dy=x1-x;
      ld nf=hypotl(dx,dy);
      dx/=nf, dy/=nf;
      ld cx=x+dx*s, cy=y+dy*s;
      int cnt=2;
      for (int k=0;k<n;k++){
        if (k==i||k==j)continue;
        ld x3=xs[k], y3=ys[k];
        // if (hypotl(x3-cx, y3-cy)<=2.5L+EPS) {
        if ((x3-cx)*(x3-cx)+(y3-cy)*(y3-cy)<=6.25L+EPS) {
          cnt++;
        }
        res=max(res,cnt);
      }
      
      dx=y1-y, dy=x-x1;
      dx/=nf, dy/=nf;
      cx=x+dx*s, cy=y+dy*s;
      cnt=2;
      for (int k=0;k<n;k++){
        if (k==i||k==j)continue;
        ld x3=xs[k], y3=ys[k];
        if ((x3-cx)*(x3-cx)+(y3-cy)*(y3-cy)<=6.25L+EPS) {
          cnt++;
        }
        res=max(res,cnt);
      }
    }
  }
  cout<<res<<'\n';
}
