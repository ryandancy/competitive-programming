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
ll lc[200000],rc[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    ll n,l,r;
    cin>>n>>l>>r;
    for (ll i=0;i<l;i++)cin>>lc[i],lc[i]--;
    for (ll i=0;i<r;i++)cin>>rc[i],rc[i]--;
    sort(lc,lc+l);
    sort(rc,rc+r);
    ll tl=0,tr=0,pl=0,pr=0;
    for (ll c=0;c<n;c++) {
      ll vl=upper_bound(lc,lc+l,c)-lower_bound(lc,lc+l,c);
      ll vr=upper_bound(rc,rc+r,c)-lower_bound(rc,rc+r,c);
      ll mn=min(vl,vr);
      vl-=mn;
      vr-=mn;
      tl+=vl;
      tr+=vr;
      pl+=vl/2;
      pr+=vr/2;
    }
    if (l<r) swap(tl,tr),swap(pl,pr),swap(l,r);
    ll tm=(l-r)/2;
    ll mp=min(tm,pl);
    tl-=mp*2;
    cout<<tm+(tl+tr)/2<<'\n';
  }
}
