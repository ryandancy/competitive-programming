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
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll a,b;
  cin>>a>>b;
  if (a>b)swap(a,b);
  // vector<pii> f,fa;
  vector<ll> fx,fy,fax,fay,fbx,fby;
  for (ll x=1;x*x<=a+b;x++) {
    if ((a+b)%x==0)fx.push_back(x),fy.push_back((a+b)/x),debug("a+b", x, (a+b)/x);
  }
  for (ll x=1;x*x<=a;x++) {
    if (a%x==0)fax.push_back(x),fay.push_back(a/x),debug("a", x, a/x);
  }
  for (ll x=1;x*x<=b;x++) {
    if (b%x==0)fbx.push_back(x),fby.push_back(b/x),debug("b", x, b/x);
  }
  for (int i=fx.size()-1;i>=0;i--) {
    ll p=fx[i],q=fy[i];
    ll xi=lower_bound(fax.begin(),fax.end(),p)-fax.begin();
    // if (xi==fax.size()||fax[xi]!=p)xi--;
    if (xi!=fax.size()&&fax[xi]!=p)xi--;
    ll yi=fay.rend()-lower_bound(fay.rbegin(),fay.rend(),q);
    if (yi==fay.size())yi++;
    bool r=xi>=yi;
    if (fax.size()==1) {
      r=fax[0]<=p&&fay[0]<=q;
    }
    ll xi2=lower_bound(fbx.begin(),fbx.end(),p)-fbx.begin();
    if (xi2!=fbx.size()&&fbx[xi2]!=p)xi2--;
    ll yi2=fby.rend()-lower_bound(fby.rbegin(),fby.rend(),q);
    if (yi2==fby.size())yi2++;
    bool s=xi2>=yi2;
    if (fbx.size()==1) {
      s=fbx[0]<=p&&fby[0]<=q;
    }
    debug(p,q,xi,yi,xi2,yi2);
    if (r||s) {
      cout<<2ll*(p+q)<<'\n';
      return 0;
    }
  }
}
