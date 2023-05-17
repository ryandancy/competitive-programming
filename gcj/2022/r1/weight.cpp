#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
map<pair<ll,ll>,ll> m;
ll x[10],lx[10];
ll delta(vector<ll> &a,vector<ll> &b) {
  // common prefix length
  ll pf=0;
  for (pf=0;pf<min(a.size(),b.size());pf++) {
    if (a[pf]!=b[pf]) break;
  }
  return a.size()-pf+b.size()-pf;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin>>T;
  for (ll t=1;t<=T;t++) {
    cout<<"Case #"<<t<<": ";
    m.clear();
    ll e,w; cin>>e>>w;
    for (ll E=0;E<e;E++) {
      ll sum=0;
      vector<ll> perm;
      for (ll i=0;i<w;i++) {
        cin>>x[i],sum+=x[i];
        for (ll k=0;k<x[i];k++)perm.push_back(i);
      }
      sort(perm.begin(),perm.end());
      vector<ll> lperm;
      if (E>0) for (ll i=0;i<w;i++) for (ll k=0;k<lx[i];k++) lperm.push_back(i);
      ll pn=0;
      ll sm=INF;
      do {
        ll bst=INF;
        ll ipn=0;
        if (E>0) {do {
          bst=min(bst,delta(perm,lperm)+m[{E-1,ipn}]);
          ipn++;
        } while (next_permutation(lperm.begin(),lperm.end()));}
        else bst=sum;
        m[{E,pn}]=bst;
        sm=min(bst,sm);
        pn++;
      } while (next_permutation(perm.begin(),perm.end()));
      if (E==e-1) {
        ll res=sm+sum;
        cout<<res<<'\n';
      }
      for (ll i=0;i<w;i++) lx[i]=x[i];
    }
  }
}
