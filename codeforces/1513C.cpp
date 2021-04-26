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
void pm(ll a[10][10]) {
#ifndef ONLINE_JUDGE
  debug("====");
  for (ll i=0;i<10;i++) {
    for (ll j=0;j<10;j++) {
      cout<<a[i][j]<<' ';
    }
    cout<<'\n';
  }
#endif
}
void mmul(ll d[10][10],ll a[10][10]) {
  memset(&d[0][0],0,100*sizeof(ll));
  for (ll j=0;j<10;j++) {
    ll k=(j+1)%10;
    for (ll i=0;i<10;i++) {
      // for (ll k=0;k<10;k++) {
        d[i][j]+=a[i][k];
      // }
      d[i][j]%=MOD;
    }
    if (j==9) {
      for (ll i=0;i<10;i++) {
      // for (ll k=0;k<10;k++) {
        d[i][j]+=a[i][1];
      // }
        d[i][j]%=MOD;
      }
    }
  }
}
pair<string,pll> tc[200000], *s[200000];
ll res[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  for (ll i=0;i<t;i++) {
    string n; ll m;
    cin>>n>>m;
    tc[i]={n,{m,i}};
    s[i]=&tc[i];
  }
  sort(s,s+t,[&](pair<string,pll>*a,pair<string,pll>*b) {
    return a->second<=b->second;
  });
  ll d[10][10]={{0}};
  for (ll i=0;i<10;i++) d[i][i]=1;
  ll sp[10][10];
  ll (*x)[10][10]=&d,(*y)[10][10]=&sp;
  ll e=0;
  for (ll i=0;i<t;i++) {
    for (;e<s[i]->second.first;e++) {
      mmul(*y,*x);
      // for (ll i=0;i<10;i++) for (ll j=0;j<10;j++) d[i][j]=sp[i][j];
      swap(y,x);
    }
    ll b[10]={0};
    for (char c:s[i]->first) {
      b[c-'0']++;
    }
    ll sm=0;
    for (ll i=0;i<10;i++) {
      for (ll j=0;j<10;j++) {
        sm+=(*x)[i][j]*b[j];
        sm%=MOD;
      }
    }
    sm%=MOD;
    sm+=MOD;
    sm%=MOD;
    res[s[i]->second.second]=sm;
  }
  for (ll i=0;i<t;i++) {
    cout<<res[i]<<'\n';
  }
  // ll t;
  // cin>>t;
  // while (t--) {
  //   string n; ll m;
  //   cin>>n>>m;
  //   ll b[10]={0};
  //   for (char c:n) {
  //     b[c-'0']++;
  //   }
  //   ll T[10][10]={{0}};
  //   for (ll i=0;i<10;i++){
  //     T[(i+1)%10][i]=1;
  //     if (i==9) T[(i+2)%10][i]=1;
  //   }
  //   // pm(T);
  //   ll d[10][10]={{0}};
  //   fexp(d,T,m);
  //   // pm(d);
  //   ll r[10]={0};
  //   for (ll i=0;i<10;i++) {
  //     for (ll j=0;j<10;j++) {
  //       r[i]+=d[i][j]*b[j];
  //       r[i]%=MOD;
  //     }
  //   }
  //   ll sm=0;
  //   for (ll i=0;i<10;i++) sm+=r[i],sm%=MOD;
  //   sm%=MOD;
  //   sm+=MOD;
  //   sm%=MOD;
  //   cout<<sm<<'\n';
  // }
}
