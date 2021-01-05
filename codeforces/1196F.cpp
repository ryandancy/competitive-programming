#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
ll n,m,k;
struct edge {ll x,y,w;} e[200000];
vector<pll> adj[200000];
vector<ll> res;
bool v[200000]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n>>m>>k;
  for (int i=0;i<m;i++) {
    cin>>e[i].x>>e[i].y>>e[i].w;
    e[i].x--,e[i].y--;
  }
  sort(e,e+m,[&](edge&a,edge&b){return a.w<b.w;});
  for (int i=0;i<k;i++) {
    adj[e[i].x].push_back({e[i].y,e[i].w});
    adj[e[i].y].push_back({e[i].x,e[i].w});
  }
  stack<ll> tcu;
  priority_queue<pll> pq;
  // could totally just do floyd-warshall lol, this is n * djikstra
  for (int s=0;s<n;s++) {
    pq.push({0,s});
    while (pq.size()) {
      pll a=pq.top(); pq.pop();
      ll d=-a.first,c=a.second;
      if (v[c]) continue;
      v[c]=true;
      tcu.push(c);
      if (d) res.push_back(d);
      for (pll&nb:adj[c]) {
        if (v[nb.first]) continue;
        pq.push({-(d+nb.second),nb.first});
      }
    }
    while (tcu.size()) {
      v[tcu.top()]=false;
      tcu.pop();
    }
  }
  sort(res.begin(),res.end());
  cout<<res[2*(k-1)]<<'\n';
}
