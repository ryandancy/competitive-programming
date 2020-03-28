#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll a[200000];
ll dpl[200000], dpr[200000], lr[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n, k;
  cin>>n>>k;
  for (int i=0;i<n;i++)cin>>a[i];
  sort(a,a+n);
  ll cr=1, ri=0;
  for (ll i=1;i<n;i++){
    if (a[i]==a[ri]) {
      cr++;
    } else {
      for (ll j=ri;j<i;j++){
        lr[j]=cr;
      }
      cr=1;
      ri=i;
    }
  }
  for (ll j=ri;j<n;j++){
    lr[j]=cr;
  }
  for (int i=0;i<n;i++)debug("lr", i, lr[i]);
  for (int i=0;i<lr[0];i++)dpl[i]=0;
  for (ll i=lr[0];i<n;){
    ll p=i-lr[i-1];
    dpl[i]=dpl[p]+p+i*(a[i]-1-a[p]);
    for (int j=1;j<lr[i];j++)dpl[i+j]=dpl[i];
    i+=lr[i];
  }
  for (int i=0;i<n;i++)debug("dpl", i, dpl[i]);
  for (int i=0;i<lr[n-1];i++)dpr[n-i-1]=0;
  for (ll i=n-1-lr[n-1];i>=0;){
    ll p=i+lr[i+1];
    dpr[i]=dpr[p]+(n-p-1)+(n-i-1)*(a[p]-a[i]-1);
    for (int j=1;j<lr[i];j++)dpr[i-j]=dpr[i];
    debug(i,p);
    i-=lr[i];
  }
  for (int i=0;i<n;i++)debug("dpr", i, dpr[i]);
  ll b=-1;
  for (ll i=0;i<n;){
    ll rl=lr[i];
    ll nd=k-rl;
    if (nd<=0){b=0;break;}
    ll v=dpl[i]+dpr[i]+nd;
    if (i-rl+1>=nd){
      v=min(v,dpl[i]+nd);
    }
    if (n-(i+rl)>=nd){
      v=min(v,dpr[i]+nd);
    }
    b=(b==-1?v:min(b,v));
    debug(i,v,dpl[i],dpr[i],nd);
    i+=rl;
  }
  cout<<b<<'\n';
}
