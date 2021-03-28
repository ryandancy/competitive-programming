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
ll n,m;
vector<ll> f[100000];
ll ta[100000]={0},res[100000]={0},u[100000]={0};
bool fl[100000]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    cin>>n>>m;
    ll mx=m/2+m%2;
    for (ll i=0;i<max(n,m);i++)f[i].clear(),ta[i]=res[i]=u[i]=0,fl[i]=false;
    for (ll i=0;i<m;i++) {
      ll k;
      cin>>k;
      for (ll j=0;j<k;j++) {
        ll x;
        cin>>x;
        x--;
        ta[x]++;
        f[i].push_back(x);
      }
    }
    ll v;
    for (v=0;ta[v]<=mx&&v<n;v++);
    if (v==n) v=0;
    for (ll i=0;i<m;i++) {
      bool cv=false,co=false; ll o;
      for (ll x:f[i]) {
        if (x==v) cv=true;
        else co=true,o=x;
      }
      if (!co) res[i]=v;
      else if (!cv) res[i]=o;
      else {
        if (ta[v]>mx) res[i]=o,ta[v]--;
        else res[i]=v;
      }
    }
    ll a=0;
    for (ll i=0;i<m;i++) if (res[i]==v) a++;
    if (a>mx) {
      cout<<"NO\n";
    } else {
      cout<<"YES\n";
      for (ll i=0;i<m;i++) {
        cout<<res[i]+1;
        if (i==m-1)cout<<'\n';
        else cout<<' ';
      }
    }
    // for (ll i=0;i<n;i++) {
    //   if (fl[i]) continue;
    //   for (ll x:f[i]) {
    //     if (ta[x]<los) {
    //       fl[i]=true;
    //       res[i]=x;
    //       break;
    //     }
    //   }
    // }
  }
}
