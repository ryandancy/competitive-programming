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
ll n,m,k;
vector<pair<ll,string>> res;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m>>k;
  if (k>4*n*m-2*n-2*m)return cout<<"NO\n",0;
  for (ll c=0;k&&c<m-1;c++) {
    if (k>=3*(n-1)) {
      res.push_back({n-1,"DRL"});
      k-=3*(n-1);
    } else {
      if (k/3) res.push_back({k/3,"DRL"});
      k%=3;
      if (k) res.push_back({1,k==1?"D":"DR"});
      k=0;
      break;
    }
    if (k) {
      res.push_back({min(k,n-1),"U"});
      k-=min(k,n-1);
    }
    if (k) res.push_back({1,"R"}),k--;
  }
  if (k) {
    res.push_back({min(k,n-1), "D"});
    k-=min(k,n-1);
  }
  if (k) {
    res.push_back({min(k,n-1), "U"});
    k-=min(k,n-1);
  }
  if (k) {
    res.push_back({min(k,m-1), "L"});
    k-=min(k,m-1);
  }
  if (k) cout<<"NO\n";
  else {
    ll sz=0;
    for (const pair<ll,string>&p:res) {
      if (p.first) sz++;
    }
    cout<<"YES\n"<<sz<<'\n';
    for (const pair<ll,string>&p:res) {
      if (p.first)cout<<p.first<<" "<<p.second<<"\n";
    }
  }
}
