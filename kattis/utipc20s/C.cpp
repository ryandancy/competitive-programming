#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int c[1000000], n, k;
int nj(int j) {
  int r=0;
  for (int i=0;i<n-1;){
    int nx=i;
    while (nx<n-1&&j+c[i]>=c[nx+1])nx++;
    if (nx==i)return INF;
    i=nx;
    r++;
  }
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>k;
  for (int i=0;i<n;i++)cin>>c[i];
  int l=0,r=c[n-1];
  while (l<=r){
    int m=(l+r)/2;
    int rs=nj(m);
    if (rs>=k){
      l=m+1;
    } else {
      r=m-1;
    }
  }
  int rs=-1;
  if (r+1<n&&nj(r+1)==k)rs=r+1;
  else if (nj(r)==k)rs=r;
  else if (nj(l)==k)rs=l;
  else if (l-1>=0&&nj(l-1)==k)rs=l-1;
  cout<<rs<<'\n';
}
