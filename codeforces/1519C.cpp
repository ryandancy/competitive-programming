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
ll n;
pll us[200000];
ll lu[200000]={0};
vector<ll> u[200000], ps[200000];
vector<ll> au; ll eaus;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    cin>>n;
    for (ll i=0;i<n;i++) cin>>us[i].first,us[i].first--,lu[us[i].first]=t,u[us[i].first].clear();
    for (ll i=0;i<n;i++) cin>>us[i].second;
    for (ll i=0;i<n;i++) {
      u[us[i].first].push_back(us[i].second);
    }
    au.clear();
    for (ll i=0;i<n;i++) {
      if (u[i].size()&&lu[i]==t) {
        au.push_back(i);
        sort(u[i].begin(),u[i].end(),[&](ll sa,ll sb){return sb<sa;});
      }
    }
    sort(au.begin(),au.end(),[&](ll a,ll b){return u[b].size()<u[a].size();});
    eaus=au.size();
    for (ll i=0;i<eaus;i++) {
      ll a=au[i];
      ps[a].clear();
      ll r=0;
      for (ll j=0;j<u[a].size();j++) {
        r+=u[a][j];
        ps[a].push_back(r);
      }
    }
    ll k;
    for (k=1;k<=n;k++) {
      if (eaus==0) break;
      ll s=0;
      for (ll i=0;i<eaus;i++) {
        ll a=au[i];
        ll l=u[a].size();
        if (l<k) {eaus=i; break;}
        s+=ps[a][l-l%k-1];
      }
      cout<<s;
      if (k==n) cout<<'\n';
      else cout<<' ';
    }
    for (; k<=n; k++) {
      cout<<'0';
      if (k==n) cout<<"\n";
      else  cout<<' ';
    }
  }
}
