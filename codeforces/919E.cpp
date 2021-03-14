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
ll a,b,p,x;
ll c,d;
ll invb[2000000];
void euclid(ll a, ll b, ll&x, ll&y) {
  if (b) euclid(b,a%b,y,x),y-=x*(a/b);
  else x=1,y=0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>a>>b>>p>>x;
  euclid(p,p-1,c,d);
  c=(c%p+p)%p;
  d=(d%p+p)%p;
  for (ll y=1;y<p;y++) {
    ll z;
    euclid(y,p,invb[y],z);
    invb[y]%=p;
    invb[y]*=b;
    invb[y]=(invb[y]%p+p)%p;
  }
  ll ppm=p*(p-1);
  ll res=0;
  for (ll e=1,i=0;i<p-1;i++,e*=a,e=(e%p+p)%p) {
    ll r=i*c*p+invb[e]*d*(p-1);
    r=(r%ppm+ppm)%ppm;
    res+=x/ppm;
    if (x%ppm>=r&&r!=0) res++;
  }
  cout<<res<<'\n';
}
