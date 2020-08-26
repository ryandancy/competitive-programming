#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin>>t;
  while (t--) {
    ll p,f,cs,cw,s,w;
    cin>>p>>f>>cs>>cw>>s>>w;
    if (s>w)swap(s,w),swap(cs,cw);
    vector<pll> rp,rf;
    for (ll a=0;a<=cs;a++) {
      if (a*s>p)continue;
      rp.push_back({a,min(cw,(p-a*s)/w)});
    }
    for (ll a=0;a<=cs;a++) {
      if (a*s>f)continue;
      rf.push_back({a,min(cw,(f-a*s)/w)});
    }
    ll ans=0;
    for (pll&q:rp) {
      ll x=cs-q.first,y=cw-q.second;
      if (x>=rf.size())x=rf.size()-1;
      ll o=min(y,rf[x].second);
      ll res=q.first+q.second+x+o;
      ans=max(res,ans);
    }
    cout<<ans<<'\n';
  }
}
