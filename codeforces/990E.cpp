#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 100000000000000000
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
ll n,m,k,s[1020001],pv[1020001],a[1020001],vs[1020001];
ll es(ll x) {
  return a[x]*(n/x+(n%x==0?0:1));
}
ll cp(ll x) {
  ll c=0,i=0,res=0;
  while (c<n) {
    c+=x,res++;
    while (i<m&&s[i]<c)i++;
    if (i<m&&s[i]==c) c=pv[i];
    debug(c);
  }
  debug("cp", x,res,a[x]);
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m>>k;
  for (int i=0;i<m;i++)cin>>s[i];
  for (int i=1;i<=k;i++)cin>>a[i];
  if (m>0&&s[0]==0){return cout<<"-1\n",0;}
  ll lg=m>0?1:0;
  pv[0]=s[0]-1;
  for (ll i=1,gs=1;i<m;i++) {
    if (s[i]==s[i-1]+1)gs++,lg=max(gs,lg);
    else gs=1;
    pv[i]=s[i]-gs;
  }
  ll mk=lg+1;
  if (mk>k)return cout<<"-1\n",0;
  for (ll i=mk;i<=k;i++)vs[i-mk]=i;
  sort(vs,vs+k-mk+1,[&](ll x,ll y) {return es(x)<es(y);});
  ll bs=INF;
  for (ll i=0;i<k-mk+1;i++) {
    debug(i,vs[i],es(vs[i]));
    if (bs<es(vs[i])) break;
    bs=min(bs,a[vs[i]]*cp(vs[i]));
  }
  cout<<bs<<'\n';
}
