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
ll n,a[300000],q;
ll spf[1000000],nspf=0;
bool sv[1000001]={false};
// ll mp[1000001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  sv[0]=sv[1]=true;
  for (ll p=2;p*p<=1000000;p++) {
    if (sv[p]) continue;
    spf[nspf++]+=p*p;
    for (ll w=p*2;w*w<=100000;w+=p) sv[w]=true;
  }
  int T;
  cin>>T;
  while (T--) {
    cin>>n;
    for (int i=0;i<n;i++){
      cin>>a[i];
      for (int j=0;j<nspf;j++) {
        while (a[i]%spf[j]==0) a[i]/=spf[j];
        if (a[i]<spf[j]) break;
      }
      // debug(i,a[i]);
    }
    sort(a,a+n);
    ll a0=0,n1=0,no=0;
    for (ll i=0;i<n;) {
      ll j=i+1;
      while (j<n&&a[i]==a[j])j++;
      a0=max(a0,j-i);
      if (a[i]==1||(j-i)%2==0)n1+=j-i;
      else no=max(no,j-i);
      i=j;
    }
    ll a1=max(n1,no);
    cin>>q;
    while (q--) {
      ll x;
      cin>>x;
      if (x==0)cout<<a0<<'\n';
      else cout<<a1<<'\n';
    }
  }
}
