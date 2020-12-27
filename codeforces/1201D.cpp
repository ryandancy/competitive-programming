#include <bits/stdc++.h>
#define int long long
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
struct { int l,r,ldp,rdp; } rw[200000];
int n,m,k,q,nr=0;
pii rc[200000];
int sf[200000],bsf[200000];
int f(int x,int a) {
  if (a<x)swap(a,x);
  int *y=lower_bound(sf,sf+q,x);
  if (y<sf+q&&*y<=a)return a-x;
  int z=INF;
  if (y<sf+q)z=*y;
  int *p=lower_bound(bsf,bsf+q,a,[&](int w, int e){return w>e;});
  int j=-INF;
  if (p<bsf+q)j=*p;
  z-=a;
  j=x-j;
  int v=min(j,z);
  return 2*v+a-x;
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m>>k>>q;
  for (int i=0;i<k;i++) cin>>rc[i].first>>rc[i].second;
  for (int i=0;i<q;i++) cin>>sf[i];
  sort(rc,rc+k);
  sort(sf,sf+q);
  for (int i=0;i<q;i++) bsf[i]=sf[q-i-1];
  for (int i=0,c=-1;i<k;i++) {
    if (rc[i].first!=c)c=rc[i].first,nr++,rw[nr-1].l=rc[i].second;
    rw[nr-1].r=rc[i].second;
  }
  rw[nr-1].ldp=rw[nr-1].rdp=0;
  for (int r=nr-2;r>=0;r--) {
    rw[r].ldp=min(f(rw[r].l,rw[r+1].l)+rw[r+1].r-rw[r+1].l+rw[r+1].rdp,f(rw[r].l,rw[r+1].r)+rw[r+1].r-rw[r+1].l+rw[r+1].ldp);
    rw[r].rdp=min(f(rw[r].r,rw[r+1].l)+rw[r+1].r-rw[r+1].l+rw[r+1].rdp,f(rw[r].r,rw[r+1].r)+rw[r+1].r-rw[r+1].l+rw[r+1].ldp);
  }
  if (rc[0].first==1)return cout<<min(rw[0].ldp+rw[0].r-1+rw[0].r-rw[0].l,rw[0].rdp+rw[0].r-1)+rc[k-1].first-1<<'\n',0;
  int v=min(f(1,rw[0].l)+rw[0].r-rw[0].l+rw[0].rdp,f(1,rw[0].r)+rw[0].r-rw[0].l+rw[0].ldp)+rc[k-1].first-1;
  cout<<v<<'\n';
}
