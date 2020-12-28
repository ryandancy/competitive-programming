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
int n,a[50000],sm=0,mn=INF;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i],sm+=a[i],mn=min(mn,a[i]);
  int rs=sm;
  for (int i=0;i<n;i++){
    for (int x=1;x*x<=a[i];x++) {
      if (a[i]%x!=0)continue;
      rs=min(rs,sm-a[i]+a[i]/x-mn+mn*x);
      int y=a[i]/x;
      rs=min(rs,sm-a[i]+a[i]/y-mn+mn*y);
    }
  }
  cout<<rs<<'\n';
}
