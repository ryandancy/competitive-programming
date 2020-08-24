// this worked the first try??? that never happens
#include <bits/stdc++.h>
#define INF 1000000000
using namespace std;
typedef pair<int, int> pii;
int n;
vector<pair<int, bool>> adj[3000]; // bool is in
bool va[3000][3000]={{false}};
pii cst(int c, bool*v) { // w/ 0, w/ 1
  int w0=0,w1=0;
  v[c]=true;
  int mn=0;
  for (pair<int,bool>&pib:adj[c]) {
    int nb; bool in;
    tie(nb,in)=pib;
    if (v[nb]) {
      (in?w1:w0)++;
      continue;
    }
    const pii&r=cst(nb,v);
    if (r.second-r.first<mn)mn=r.second-r.first;
    w0+=r.first;
    w1+=r.first;
  }
  w1+=mn;
  return {w0,w1};
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (int i=0;i<n-1;i++) {
    int a,b;
    cin>>a>>b;
    a--,b--;
    adj[a].push_back({b,false});
    adj[b].push_back({a,true});
  }
  if (n<=2)return cout<<"0\n",0;
  int res=INF;
  for (int a=0;a<n;a++) {
    va[a][a]=true;
    int w=0,ds[2]={0};
    for (pair<int,bool>&pib:adj[a]) {
      const pii&r=cst(pib.first,va[a]);
      w+=r.first;
      int d=r.second-r.first;
      if (d<ds[0]) {ds[1]=ds[0]; ds[0]=d;}
      else if (d<ds[1]) {ds[1]=d;}
    }
    w+=ds[0]+ds[1];
    res=min(w,res);
  }
  cout<<res<<'\n';
}
