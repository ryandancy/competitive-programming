#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n;
map<string,int> lmp; int nl=0;
int ls[100]={0};
vector<int> adj[100];
bool u[100]={false};
vector<int> s[100]; int ns=0;
bool rb(int a, int b) {
  // debug(a,b);
  stack<int> dfs;
  bool v[100]={false};
  dfs.push(a);
  v[a]=true;
  while(dfs.size()) {
    int c=dfs.top(); dfs.pop();
    if (c==b) return true;
    for (int nb:adj[c]) {
      if (!v[nb]) {
        dfs.push(nb);
        v[nb]=true;
      }
    }
  }
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n; string tw; getline(cin,tw);
  for (int i=0;i<n;i++) {
    string s,t;
    getline(cin,s);
    stringstream ss(s);
    ss>>t;
    ss>>t;
    debug(t);
    int l;
    if (lmp.count(t)) l=lmp[t];
    else {
      l=nl++;
      lmp[t]=l;
    }
    ls[l]++;
    while (ss>>t) {
      int c=0;
      if (lmp.count(t)) c=lmp[t];
      else lmp[t]=c=nl++;
      adj[l].push_back(c);
      debug(t, l, c);
    }
  }
  debug("nl", nl);
  for (int i=0;i<nl;i++) {
    if (u[i]) continue;
    u[i]=true;
    int ms=ns++;
    s[ms].push_back(i);
    for (int j=i+1;j<nl;j++) {
      if (rb(i,j)&&rb(j,i)) {
        s[ms].push_back(j);
        u[j]=true;
      }
    }
  }
  int bst=0;
  for (int i=0;i<ns;i++) {
    int sz=0;
    for (int l:s[i]) {
      sz+=ls[l];
    }
    bst=max(bst,sz);
  }
  cout<<n-bst<<'\n';
}
