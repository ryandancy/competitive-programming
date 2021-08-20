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
ll a[1000]={0},n,m,c;
bool ok() {
  for (int i=0;i<n;i++) {
    if (a[i]==0) return false;
    if (i>0&&a[i-1]>a[i]) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>c;
  ll t=c/2;
  ll x;
  ll l=0,r=n;
  ll rd=0;
  while (!ok()&&rd<m) {
    cin>>x;
    if (x<=t) {
      ll*pl=upper_bound(a,a+l,x);
      if (pl==a+n) break; // ???
      *pl=x;
      cout<<pl-a+1<<endl;
      if (pl==a+l) l++;
    } else {
      ll*pl=lower_bound(a+r,a+n,x)-1;
      if (pl<a) break; // ???
      *pl=x;
      cout<<pl-a+1<<endl;
      if (pl==a+r-1) r--;
    }
    rd++;
  }
  if (!ok()) debug("OH NO");
}
