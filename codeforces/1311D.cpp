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
#define FOO 12000
vector<ll> dv[FOO+1];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  for (ll i=1;i<=FOO;i++) {
    for (ll j=i;j<=FOO;j+=i) {
      dv[j].push_back(i);
    }
  }
  int t;
  cin>>t;
  while (t--) {
    ll a,b,c;
    cin>>a>>b>>c;
    ll ba=-1,bb=-1,bc=-1,bs=INF;
    for (ll C=1;C<=FOO;C++) {
      for (ll ai=0;ai<dv[C].size();ai++) {
        for (ll bi=ai;bi<dv[C].size();bi++) {
          ll A=dv[C][ai],B=dv[C][bi];
          if (B%A!=0) continue;
          ll s=abs(a-A)+abs(b-B)+abs(c-C);
          if (s<bs) {
            bs=s;
            ba=A;
            bb=B;
            bc=C;
          }
        }
      }
    }
    cout<<bs<<'\n';
    cout<<ba<<" "<<bb<<" "<<bc<<"\n";
  }
}
