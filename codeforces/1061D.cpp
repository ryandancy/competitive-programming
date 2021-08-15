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
vector<ll> b; multiset<ll> a;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n,x,y;
  cin>>n>>x>>y;
  ll res=0;
  for (int i=0;i<n;i++) {
    ll q,w;
    cin>>q>>w;
    a.insert(q);
    b.push_back(w);
    res+=(x+(w-q)*y%MOD)%MOD;
    res%=MOD;
  }
  sort(b.begin(),b.end());
  for (ll i=b.size()-1;i>=0;i--) {
    ll r=b[i];
    auto lp=a.upper_bound(r);
    if (lp==a.end()) continue;
    ll l=*lp;
    if (y*(l-r)>=x) continue;
    a.erase(lp);
    res-=x;
    res+=y*(l-r);
    res%=MOD;
    res+=MOD;
    res%=MOD;
  }
  cout<<res<<'\n';
}
