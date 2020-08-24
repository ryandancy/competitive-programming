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
ll pw[100],spw[100],mx,w;
unordered_set<int> seen;
bool ok(ll m) {
  if (m==0) return true;
  if (seen.count(m)) return false;
  seen.insert(m);
  ll*x=lower_bound(spw,spw+mx,m);
  int i=x-spw;
  m-=pw[i];
  if (m<0) m*=-1;
  return ok(m);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll m;
  cin>>w>>m;
  pw[0]=1; spw[0]=1; mx=0;
  for (int i=1;i<100;i++) {
    pw[i]=pw[i-1]*w;
    spw[i]=spw[i-1]+pw[i];
    mx=i;
    if (pw[i]>m) break;
  }
  cout<<(ok(m)?"YES\n":"NO\n");
}
