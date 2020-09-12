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
vector<int> adj[100000], ch[100000];
bool v[100000]; int sz[100000], p[100000];
int bsz(int c) {
  sz[c]=1;
  for (int&h:ch[c]) {
    sz[c]+=bsz(h);
  }
  return sz[c];
}
void ta() {
  int o=adj[0][0]+1;
  cout<<"1 "<<o<<"\n1 "<<o<<'\n';
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
    int n;
    cin>>n;
    for (int i=0;i<n;i++)adj[i].clear(),ch[i].clear(),v[i]=false,sz[i]=p[i]=0;
    for (int i=0;i<n-1;i++) {
      int a,b;
      cin>>a>>b;
      a--,b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    if (n%2==1){
      ta();
      continue;
    }
    stack<int> stk;
    stk.push(0); v[0]=true; p[0]=0;
    while (stk.size()) {
      int c=stk.top(); stk.pop();
      for (int&nb:adj[c]) {
        if (!v[nb]) {
          stk.push(nb);
          ch[c].push_back(nb);
          p[nb]=c;
          v[nb]=true;
        }
      }
    }
    bsz(0);
    int q=-1;
    for (int i=0;i<n;i++) {
      if (sz[i]==n/2) {
        q=i;
        break;
      }
    }
    if (q==-1) {
      ta();
      continue;
    }
    int lf=q;
    while (ch[lf].size()) {
      lf=ch[lf][0];
    }
    cout<<lf+1<<' '<<p[lf]+1<<'\n'<<lf+1<<' '<<p[q]+1<<'\n';
  }
}
