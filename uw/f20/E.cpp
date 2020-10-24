#include <bits/stdc++.h>
#define INF 1000000000
#define PI 3.141592653589793LL
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
int n,m;
int dn[200000]={0}, dl[200000]={0}, st[200000]={0}, dp[200000]={0};//, rc=0;
vector<int> adj[200000];
vector<pii> e;
// set<pii> ue;
map<pii,pii> mp;
vector<pii> brg;
map<pii,int> bf,ef;
int c=0;
void br(int u) {
  dl[u]=dn[u]=c++;
  // cout<<u<<endl;
  for (int j=0;j<adj[u].size();j++) {
    int v=adj[u][j];
    pii mpa=u<v?pii{u,v}:pii{v,u};
    if (!mp.count(mpa)) {
      // cout<<u<<" "<<v<<'\n';
      mp[mpa]={u,v};
    }
    if (dn[v]==-1) {
      dp[v]=u;
      // if (u==0) rc++;
      br(v);
      if (dl[v]>dn[u]){
        brg.push_back(mpa);
      }
      dl[u]=min(dl[u], dl[v]);
    } else if (v!=dp[u]) {
      dl[u]=min(dl[u], dn[v]);
    }
    // if (!ue.count(mpa)){
    //   mp[mpa]={u,v};
    //   ue.insert(mpa);
    //   cout<<u<<' '<<v<<'\n';
    // }
  }
}
int main() {
  cin>>n>>m;
  fill_n(dn,200000,-1);
  for (int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    // if (a>b)swap(a,b);`
    a--,b--;
    e.push_back({a,b});
    pii s=a<=b?pii{a,b}:pii{b,a};
    ef[s]++;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  br(0);
  sort(brg.begin(),brg.end());
  for (pii&eg:e) {
    pii s=eg.first<=eg.second?eg:pii{eg.second,eg.first};
    if (binary_search(brg.begin(),brg.end(),s)) {
      if (ef[s]>1) {
        if (bf[s]==0) {
          cout<<"<\n";
        } else {
          cout<<">\n";
        }
        bf[s]++;
      } else {
        cout<<"=\n";
      }
      // auto pit=equal_range(brg.begin(),brg.end(),s);
      // if (pit.second-pit.first!=1) {
      //   if (bf[s]>0) {
      //     cout<<">\n";
      //   } else {
      //     cout<<"<\n";
      //   }
      //   bf[s]++;
      // } else {
      //   cout<<"=\n";
      // }
    } else if (mp[s]==eg) {
      cout<<"<\n";
    } else cout<<">\n";
  }
}
