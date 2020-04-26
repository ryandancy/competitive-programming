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
ll a[2][1000000];
ll ps[2][1000000], t[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[0][i];
  for (int i=0;i<n;i++)cin>>a[1][i];
  ll ts=0,ws0=0,ws1=0;
  for (int i=0;i<n;i++){
    ts+=a[0][i]+a[1][i];
    ws0+=i*a[0][i]+(2*n-i-1)*a[1][i];
    ws1+=(2*n-i-1)*a[0][i]+i*a[1][i];
  }
  ps[0][0]=ws0, ps[1][0]=ws1, t[0]=ts;
  for (int i=1;i<n;i++){
    ts-=a[0][i-1]+a[1][i-1];
    t[i]=ts;
    ps[0][i]=ps[0][i-1]-(2*(n-i+1)-1)*a[1][i-1]-ts;
    ps[1][i]=ps[1][i-1]-(2*(n-i+1)-1)*a[0][i-1]-ts;
  }
  ll res=ps[0][0],zz=0;
  for (int i=1,ub=1,f=2;i<n;i++,ub=!ub,f+=2){
    zz+=(f-2)*a[!ub][i-1]+(f-1)*a[ub][i-1];
    res=max(res,zz+f*t[i]+ps[ub][i]);
  }
  cout<<res<<'\n';
}
