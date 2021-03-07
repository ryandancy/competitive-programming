#include <bits/stdc++.h>
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
ll a[300000][8]={{0}};
ll mx[256]={0},o[256];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n,m;
  cin>>n>>m;
  for (int i=0;i<n;i++) {
    for (int j=0;j<m;j++) cin>>a[i][j];
  }
  ll v[256]={0};
  for (int i=0;i<n;i++) {
    for (int i=0;i<(1<<m);i++)v[i]=INF;
    for (int c=1,j=0;j<m;c=c<<1,j++) {
      for (int x=0;x<c;x++) {
        v[c|x]=min(v[x],a[i][j]);
        if (v[c|x]>mx[c|x]) {
          mx[c|x]=v[c|x];
          o[c|x]=i;
        }
      }
    }
  }
  int msk=(1<<m)-1;
  ll bs=0; int bb=0;
  for (int b=0;b<(1<<m);b++) {
    ll e=min(mx[b],mx[~b&msk]);
    if (e>bs) bs=e,bb=b;
  }
  int a=o[bb],b=o[~bb&msk];
  if (a>b)swap(a,b);
  cout<<a+1<<' '<<b+1<<'\n';
}
