#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000100
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
ll n,q;
set<ll> s;
multiset<ll> g;
void p() {
  if (s.size()==0) {
    cout<<"0\n";
    return;
  }
  ll r=*--s.end()-*s.begin();
  if (g.size()) {
    r-=*--g.end();
  }
  cout<<r<<'\n';
}
void rm(ll x) {
  g.erase(g.find(x));
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>q;
  for (ll i=0;i<n;i++) {
    ll x;
    cin>>x;
    s.insert(x);
  }
  {
    auto it=s.begin();
    for (ll i=0;i<n-1;i++) {
      ll c=*it;
      ++it;
      g.insert(*it-c);
    }
  }
  p();
  while (q--) {
    ll t,x;
    cin>>t>>x;
    if (t==0) {
      auto it=s.lower_bound(x);
      if (it==s.begin()) {
        ++it;
        if (it==s.end()) {
          s.erase(x);
          goto nxt;
        }
        ll o=*it;
        --it;
        rm(o-x);
        s.erase(x);
        goto nxt;
      }
      ++it;
      if (it==s.end()) {
        --it;
        ll o=*--it;
        rm(x-o);
        s.erase(x);
        goto nxt;
      }
      ll to=*it;
      --it;
      --it;
      ll bo=*it;
      rm(to-x);
      rm(x-bo);
      g.insert(to-bo);
      s.erase(x);
    } else {
      if (s.size()==0) {
        s.insert(x);
        goto nxt;
      }
      auto it=s.lower_bound(x);
      if (it==s.end()) {
        ll o=*--it;
        g.insert(x-o);
        s.insert(x);
        goto nxt;
      }
      if (it==s.begin()) {
        ll o=*it;
        g.insert(o-x);
        s.insert(x);
        goto nxt;
      }
      ll to=*it;
      --it;
      ll bo=*it;
      rm(to-bo);
      g.insert(to-x);
      g.insert(x-bo);
      s.insert(x);
    }
    nxt: p();
  }
}
