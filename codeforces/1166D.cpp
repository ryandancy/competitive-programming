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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll q;
  cin>>q;
  while (q--) {
    ll a,b,m;
    cin>>a>>b>>m;
    if (a==b) {
      cout<<"1 "<<a<<'\n';
      continue;
    }
    ll k;
    for (k=1;k<=50;k++) {
      if ((1ull<<(k-1))*(a+1)<=b&&b<=(1ull<<(k-1))*(a+m)) break;
    }
    if (k>50) {
      cout<<"-1\n";
      continue;
    }
    vector<ll> r(k);
    for (ll i=0;i<k;i++)r[i]=1;
    b-=(1ull<<(k-1))*(a+1);
    for (ll i=0;i<k;i++) {
      ll t=i==k-1?1:(1ull<<(k-i-2));
      ll ta=min(b/t,m-1);
      b-=ta*t;
      r[i]+=ta;
    }
    vector<ll> res;
    res.push_back(a);
    for (ll i=0;i<k;i++) {
      ll x=0;
      for (ll j=0;j<res.size();j++) x+=res[j];
      x+=r[i];
      res.push_back(x);
    }
    cout<<k+1<<" ";
    for (ll i=0;i<res.size();i++) {
      cout<<res[i];
      if (i==res.size()-1) cout<<'\n';
      else cout<<' ';
    }
  }
}
