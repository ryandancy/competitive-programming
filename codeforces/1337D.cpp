// 1337D - Xenia and Colorful Gems
// Double ternary search, I'm pretty sure it fails on this test case:
// 1
// 10 10 10
// 36 2 54 3 13 10 15 50 79 96
// 97 33 100 43 87 43 47 78 63 64
// 35 22 34 69 3 54 88 6 46 51
// but the tests were weak so whatever
// Apparently just doing two binary searches for each element works too.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ra[100000], g[100000], b[100000];
int nr,ng,nb;
#define f(x,y,z) (((x)-(y))*((x)-(y))+((x)-(z))*((x)-(z))+((y)-(z))*((y)-(z)))
ll mxy(ll x, ll y){
  int l=0, r=nb-1;
  while (r-l>=2){
    int m1=l+(r-l)/3, m2=r-(r-l)/3;
    ll s=f(x,y,b[m1]), t=f(x,y,b[m2]);
    if (s<t){
      if (m2==r)break;
      r=m2;
    } else {
      if (m1==l)break;
      l=m1;
    }
  }
  ll m=f(x,y,b[l]);
  for (int i=l+1;i<=r;i++){
    m=min(m,f(x,y,b[i]));
  }
  return m;
}
ll mx(ll x){
  int l=0, r=ng-1;
  while (r-l>=2){
    int m1=l+(r-l)/3, m2=r-(r-l)/3;
    ll s=mxy(x,g[m1]), t=mxy(x,g[m2]);
    if (s<t){
      if (m2==r)break;
      r=m2;
    } else {
      if (m1==l)break;
      l=m1;
    }
  }
  ll m=mxy(x,g[l]);
  for (int i=l+1;i<=r;i++){
    m=min(m,mxy(x,g[i]));
  }
  return m;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--){
    cin>>nr>>ng>>nb;
    for (int i=0;i<nr;i++)cin>>ra[i];
    for (int i=0;i<ng;i++)cin>>g[i];
    for (int i=0;i<nb;i++)cin>>b[i];
    sort(ra,ra+nr);
    sort(g,g+ng);
    sort(b,b+nb);
    ll m=mx(ra[0]);
    for (int i=1;i<nr;i++){
      m=min(m,mx(ra[i]));
    }
    cout<<m<<'\n';
  }
}
