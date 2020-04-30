#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
ll ix[1000000], s[1000001], mm[1000001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  while (T--) {
    ll n, a, b, c;
    cin>>n>>a>>b>>c;
    s[0]=0, mm[0]=0;
    for (int i=0;i<n;i++) cin>>ix[i], s[i+1]=s[i]+ix[i];
    vector<pll> ln{{0ll,0ll}};
    vector<ld> isec;
    for (int i=1;i<=n;i++) {
      ll x=s[i];
      int p=lower_bound(isec.begin(),isec.end(),(ld)x)-isec.begin();
      pll&l=ln[p];
      mm[i]=l.first*x+l.second+a*x*x+b*x+c;
      ll mi=-2*a*s[i], bi=a*s[i]*s[i]-b*s[i]+mm[i];
      while (1) {
        pll&l2=ln.back();
        ld is=(ld)(l2.second-bi)/(ld)(mi-l2.first);
        if (!isec.empty()&&is<=isec.back()) {
          ln.pop_back();
          isec.pop_back();
        } else {
          ln.push_back({mi,bi});
          isec.push_back(is);
          break;
        }
      }
    }
    cout<<mm[n]<<'\n';
  }
}
