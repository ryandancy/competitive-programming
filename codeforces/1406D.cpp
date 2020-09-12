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
ll a[100000], d[100000];
ll sp=0;
ll res() {
  // return (sp+a[0])/2+sp<0?-1:1)*(sp+a[0])%2;
  ll v=sp+a[0];
  if (v>=0) return v/2+v%2;
  else return v/2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i];
  int q;cin>>q;
  for (int i=0;i<n-1;i++)d[i]=a[i+1]-a[i];
  for (int i=0;i<n-1;i++)if (d[i]>0)sp+=d[i];
  cout<<res()<<'\n';
  while (q--){
    ll l,r,x;
    cin>>l>>r>>x;
    l--,r--;
    if (l-1>=0&&l-1<n-1) {
      if (d[l-1]>0)sp-=d[l-1];
      d[l-1]+=x;
      if (d[l-1]>0)sp+=d[l-1];
    }
    if (r>=0&&r<n-1) {
      if (d[r]>0)sp-=d[r];
      d[r]-=x;
      if (d[r]>0)sp+=d[r];
    }
    if (l==0)a[0]+=x;
    cout<<res()<<'\n';
  }
}
