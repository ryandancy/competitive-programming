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
int sp[200000];
vector<int> adj[200000];
int b[200000],b2[200000];
bool v[200000]={false},v2[200000]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m, k;
  cin >> n >> m >> k;
  for (int i=0;i<k;i++){cin>>sp[i];sp[i]--;}
  for (int i=0;i<m;i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  b[0]=0;
  v[0]=true;
  queue<int> q;
  q.push(0);
  while (!q.empty()) {
    int c=q.front();q.pop();
    for (int e:adj[c]) {
      if (!v[e]) {
        q.push(e);
        b[e]=b[c]+1;
        v[e]=true;
      }
    }
  }
  // for (int i=0;i<n;i++)debug(i,b[i]);
  sort(sp,sp+k,[&](int x, int y){return b[x]<b[y];});
  int ba=-1,bb=-1,bd=INF;
  for (int i=0;i<k-1;i++) {
    if (b[sp[i+1]]-b[sp[i]]<bd) {
      bd=b[sp[i+1]]-b[sp[i]];
      ba=sp[i];
      bb=sp[i+1];
    }
  }
  // debug(ba,bb,bd);
  if (bd==0) return cout<<b[n-1]<<'\n',0;
  adj[ba].push_back(bb);
  adj[bb].push_back(ba);
  b2[0]=0;
  v2[0]=true;
  q.push(0);
  while (!q.empty()) {
    int c=q.front();q.pop();
    for (int e:adj[c]) {
      // debug(c,e,v2[e]);
      if (!v2[e]) {
        q.push(e);
        b2[e]=b2[c]+1;
        v2[e]=true;
      }
    }
  }
  // for (int i=0;i<n;i++)debug(i,b2[i]);
  cout<<b2[n-1]<<'\n';
}
