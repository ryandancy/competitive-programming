#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int n,m;
vector<int> adj[5000];
int p[5000]={0},d[5000]={0};
int f[5000][5000]={{0}};
vector<pii> e;
vector<tuple<int,int,int>> ask;
bool v[5000]={false};
pii a;
void fk(int x,int g) {
  int y=p[x];
  if (x>y) swap(x,y);
  if (f[x][y]) f[x][y]=max(f[x][y],g);
  else f[x][y]=g;
}
#define ok(x,g) y.first=x, y.second=p[x]; if (x>p[x]) swap(y.first,y.second); if (f[y.first][y.second] == g) goto nxt;
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
    adj[a].push_back(b);
    adj[b].push_back(a);
    if (a>b) swap(a,b);
    e.push_back({a,b});
  }
  stack<int> stk;
  v[0]=true;
  stk.push(0);
  while (stk.size()) {
    int c=stk.top(); stk.pop();
    for (int ch:adj[c]) {
      if (v[ch]) continue;
      v[ch]=true;
      p[ch]=c;
      d[ch]=d[c]+1;
      stk.push(ch);
    }
  }
  cin>>m;
  while (m--) {
    int a,b,g;
    cin>>a>>b>>g;
    a--,b--;
    ask.push_back({a,b,g});
    if (d[a]<d[b]) swap(a,b);
    while (d[a]>d[b]) {
      fk(a,g); a=p[a];
    }
    while (a!=b) {
      fk(a,g);
      fk(b,g);
      a=p[a];
      b=p[b];
    }
  }
  pii y;
  for (tuple<int,int,int> abg:ask) {
    int a,b,g;
    tie(a,b,g)=abg;
    if (d[a]<d[b]) swap(a,b);
    while (d[a]>d[b]) {
      ok(a,g); a=p[a];
    }
    while (a!=b) {
      ok(a,g);
      ok(b,g);
      a=p[a];
      b=p[b];
    }
    cout<<"-1\n";
    return 0;
nxt:;
  }
  for (pii ed:e) {
    if (f[ed.first][ed.second]) cout<<f[ed.first][ed.second];
    else cout<<1;
    if (ed==*--e.end()) cout<<'\n';
    else cout<<' ';
  }
}
