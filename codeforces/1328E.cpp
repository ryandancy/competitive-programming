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
vector<int> adj[200050], qs[200050], ntq[200050];
int rk[200050]={0}, p[200050]={0};
bool in[200050]={false},qsat[200050]={false};
bool rcmp(int a,int b){
  return rk[a]<rk[b];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, q;
  cin>>n>>q;
  for (int i=0;i<n-1;i++){
    int a,b;
    cin>>a>>b;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> bstq;
  bstq.push(1);
  rk[1]=1;
  p[1]=1;
  while (bstq.size()){
    int c=bstq.front();bstq.pop();
    for (int nb:adj[c]){
      if (rk[nb]==0){
        rk[nb]=rk[c]+1;
        p[nb]=c;
        bstq.push(nb);
      }
    }
  }
  for (int i=0;i<q;i++){
    int nv;
    cin>>nv;
    for (int j=0;j<nv;j++){
      int a;
      cin>>a;
      if (a!=1){
        a=p[a];
      }
      qs[i].push_back(a);
    }
    sort(qs[i].begin(),qs[i].end(),rcmp);
    ntq[qs[i].back()].push_back(i);
  }
  stack<int> nd, tp;
  nd.push(1);
  tp.push(0);
  while (nd.size()) {
    int cn=nd.top();nd.pop();
    int t=tp.top();tp.pop();
    if (t==0){
      in[cn]=true;
      nd.push(cn);
      tp.push(1);
      for (int qu:ntq[cn]) {
        for (int hp:qs[qu]) {
          if (!in[hp]) goto bad;
        }
        qsat[qu]=true;
        bad:;
      }
      for (int nb:adj[cn]) {
        if (rk[nb]>rk[cn]) {
          nd.push(nb);
          tp.push(0);
        }
      }
    } else {
      in[cn]=false;
    }
  }
  for (int i=0;i<q;i++){
    cout<<(qsat[i]?"YES\n":"NO\n");
  }
}
