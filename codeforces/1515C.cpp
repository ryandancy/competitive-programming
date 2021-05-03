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
ll h[100000],res[100000],v[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    ll n,m,x;
    cin>>n>>m>>x;
    for (ll i=0;i<n;i++)cin>>h[i];
    priority_queue<pll> pq;
    for (ll i=0;i<m;i++) {
      pq.push({0,i});
      v[i]=0;
    }
    for (ll i=0;i<n;i++) {
      ll c=pq.top().second; pq.pop();
      v[c]+=h[i];
      res[i]=c;
      pq.push({-v[c],c});
    }
    ll mn=INF,mx=0;
    for (ll i=0;i<m;i++) mn=min(mn,v[i]),mx=max(mx,v[i]);
    if (mx-mn>x) cout<<"NO\n";
    else {
      cout<<"YES\n";
      for (ll i=0;i<n;i++) {
        cout<<res[i]+1;
        if (i==n-1)cout<<'\n';
        else cout<<' ';
      }
    }
  }
}
