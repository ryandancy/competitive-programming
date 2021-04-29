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
ll n,q,a[300000];
vector<ll> p[300001];
#define N 50
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>q;
  for (ll i=0;i<n;i++)cin>>a[i];
  for (ll i=0;i<n;i++) {
    p[a[i]].push_back(i);
  }
  ll l,r;//,ra[N];
  unsigned seed1 = std::chrono::system_clock::now().time_since_epoch().count();
  default_random_engine gen(seed1);
  while (q--) {
    cin>>l>>r;
    l--,r--;
    ll x=r-l+1;
    uniform_int_distribution<ll> rng(l,r);
    for (ll i=0;i<N;i++) {
      ll re=a[rng(gen)];
      ll b=upper_bound(p[re].begin(),p[re].end(),r)-lower_bound(p[re].begin(),p[re].end(),l);
      if (b>x/2+x%2) {
        cout<<2*b-x<<'\n';
        goto nxt;
      }
    }
    cout<<"1\n";
    nxt:;
  }
}
