#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,w[200000],s,deg[200000]={0};
vector<ll> adj[200000];
bool os[200000]={false},v[200000]={false};
ll ov[200000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m;
  for (ll i=0;i<n;i++)cin>>w[i];
  for (ll i=0;i<m;i++){
    ll u,v;
    cin>>u>>v;
    u--,v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
    deg[u]++;
    deg[v]++;
  }
  cin>>s; s--;
  stack<ll> stk;
  for (ll i=0;i<n;i++) {
    if (deg[i]<=1&&i!=s)stk.push(i),os[i]=true;
  }
  while (stk.size()) {
    ll c=stk.top();stk.pop();
    for (ll nb:adj[c]) {
      deg[nb]--;
      if (deg[nb]<=1&&!os[nb]&&nb!=s){
        stk.push(nb);
        os[nb]=true;
      }
    }
  }
  ll sn;
  for (sn=0;sn<n&&os[sn];sn++);
  if (sn==n) {
    sn=s;
  }
  stk.push(sn);
  v[sn]=true;
  ll mx=0;
  while (stk.size()) {
    ll c=stk.top(); stk.pop();
    for (ll nb:adj[c]) {
      if (v[nb]) continue;
      v[nb]=true;
      if (os[nb]) ov[nb]=ov[c]+w[nb];
      if (nb!=s)mx=max(mx,ov[nb]);
      stk.push(nb);
    }
  }
  ll tt=0;
  for (ll i=0;i<n;i++)if (!os[i]||i==sn)tt+=w[i];
  cout<<tt+mx+ov[s]<<"\n";
}
