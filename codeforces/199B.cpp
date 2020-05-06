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
inline bool isec(int x1, int y1, int r1, int x2, int y2, int r2) {
  int d2=(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
  return d2 < (r1+r2)*(r1+r2) && d2 > (r1-r2)*(r1-r2);
}
inline bool ins(int x1, int y1, int r1, int x2, int y2, int r2) {
  int d2=(x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
  return d2 <= (r1-r2)*(r1-r2) && r1<r2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int x1, y1, r1, R1, x2, y2, r2, R2;
  cin>>x1>>y1>>r1>>R1>>x2>>y2>>r2>>R2;
  int res=0;
  bool i11=isec(x1,y1,r1,x2,y2,r2), i12=isec(x1,y1,r1,x2,y2,R2),
    i21=isec(x1,y1,R1,x2,y2,r2), i22=isec(x1,y1,R1,x2,y2,R2);
  if (!i11&&!i12&&!(ins(x1,y1,r1,x2,y2,R2)&&!ins(x1,y1,r1,x2,y2,r2)))res++;
  if (!i21&&!i22&&!(ins(x1,y1,R1,x2,y2,R2)&&!ins(x1,y1,R1,x2,y2,r2)))res++;
  if (!i11&&!i21&&!(ins(x2,y2,r2,x1,y1,R1)&&!ins(x2,y2,r2,x1,y1,r1)))res++;
  if (!i12&&!i22&&!(ins(x2,y2,R2,x1,y1,R1)&&!ins(x2,y2,R2,x1,y1,r1)))res++;
  cout<<res<<'\n';
}
