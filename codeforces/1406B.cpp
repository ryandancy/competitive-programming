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
ll p[100000], np, ng[100000], nng, nz;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    ll n;
    cin>>n;
    np=nng=nz=0;
    ll ff=1;
    for (ll i=0;i<n;i++) {
      ll x;
      cin>>x;
      if (x==0)nz++;
      else if (x<0)ng[nng++]=x;
      else p[np++]=x;
      if (i<5)ff*=x;
    }
    if (n==5){cout<<ff<<'\n';continue;}
    if (np+nng<5){cout<<"0\n"; continue;}
    sort(p,p+np);
    sort(ng,ng+nng);
    // for (int i=0;i<np;i++)debug(p[i]);
    if (np==0) {
      if (nz>0) {cout<<0<<'\n'; continue;}
      ll res=1;
      for (int i=nng-1;i>=nng-5;i--) {
        res*=ng[i];
      }
      cout<<res<<'\n';
      continue;
    }
    ll bst=0;
    if (np>=5) {
      ll res=1;
      for (int i=0;i<5;i++) res*=p[np-i-1];
      bst=max(bst,res);
    }
    if (np>=3&&nng>=2) {
      ll res=1;
      for (int i=0;i<3;i++) res*=p[np-i-1];
      for (int i=0;i<2;i++) res*=ng[i];
      bst=max(bst,res);
    }
    if (np>=1&&nng>=4) {
      ll res=p[np-1]; //debug(p[np-1]);
      for (int i=0;i<4;i++) res*=ng[i];//,debug(ng[i]);
      bst=max(bst,res);
    }
    cout<<bst<<'\n';
  }
}
