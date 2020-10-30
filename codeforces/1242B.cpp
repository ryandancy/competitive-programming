#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
bool v[100000]={false};
set<int> u;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;
  cin>>n>>m;
  for (int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i=0;i<n;i++)sort(adj[i].begin(),adj[i].end()),u.insert(i);
  stack<int> stk;
  int res=0;
  for (int s=0;s<n;s++) {
    if (v[s]) continue;
    res++;
    u.erase(s);
    v[s]=true;
    stk.push(s);
    while (stk.size()) {
      int c=stk.top(); stk.pop();
      auto ait=adj[c].begin();
      for (auto uit=u.begin();uit!=u.end();) {
        while (ait!=adj[c].end()&&*ait<*uit)++ait;
        if (ait!=adj[c].end()&&*uit==*ait) ++uit;
        else stk.push(*uit),v[*uit]=true,uit=u.erase(uit);
      }
    }
  }
  cout<<res-1<<'\n';
}
