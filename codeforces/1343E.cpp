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
int n, m, a, b, c;
ll p[200000], pf[200001], ba[200000], bb[200000], bc[200000];
bool va[200000], vb[200000], vc[200000];
vector<int> adj[200000];
void bfs(int s, ll *bs, bool *v) {
  queue<int> q;
  q.push(s);
  bs[s]=0;
  v[s]=true;
  while(q.size()) {
    int ci=q.front(); q.pop();
    for (int&nb:adj[ci]) {
      if (v[nb])continue;
      v[nb]=true;
      bs[nb]=bs[ci]+1;
      q.push(nb);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    cin>>n>>m>>a>>b>>c;
    a--,b--,c--;
    for (int i=0;i<m;i++)cin>>p[i];
    sort(p,p+m);
    pf[0]=0;
    for (int i=1;i<=m;i++)pf[i]=pf[i-1]+p[i-1];
    for (int i=0;i<n;i++)adj[i].clear(),va[i]=vb[i]=vc[i]=false;
    for (int i=0;i<m;i++) {
      int x,y;
      cin>>x>>y;
      x--,y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    bfs(a,ba,va);
    bfs(b,bb,vb);
    bfs(c,bc,vc);
    ll bst=-1;
    for (int x=0;x<n;x++) {
      if (ba[x]+bb[x]+bc[x]>m) continue;
      ll en=pf[bb[x]]+pf[ba[x]+bb[x]+bc[x]];
      if (bst==-1||en<bst)bst=en;
    }
    cout<<bst<<'\n';
  }
}
