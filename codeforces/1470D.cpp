#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> adj[300000];
ll st[300000]; bool val[300000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll t;
  cin>>t;
  while (t--) {
    ll n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++)adj[i].clear(),st[i]=0,val[i]=false;
    for (int i=0;i<m;i++){
      ll u,v;
      cin>>u>>v;
      u--,v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    ll nv=0;
    stack<ll> dfs;
    dfs.push(0);
    vector<ll> res;
    while (dfs.size()) {
      ll c=dfs.top();dfs.pop();
      st[c]=2; nv++;
      val[c]=true;
      for (ll nb:adj[c]) {
        if (st[nb]==0) {
          st[nb]=1;
          dfs.push(nb);
        } else if (st[nb]==2&&val[nb]) {
          val[c]=false;
        }
      }
      if (val[c]) res.push_back(c);
    }
    if (nv!=n) cout<<"NO\n";
    else {
      cout<<"YES\n"<<res.size()<<'\n';
      for (int i=0;i<res.size();i++) {
        cout<<res[i]+1<<(i==res.size()-1?'\n':' ');
      }
    }
  }
}
