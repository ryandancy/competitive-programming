#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000001
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
vector<int> adj[100000];
int a[100000], p[100000][20], d[100000];
bool si[100000][20], sd[100000][20], sb[100000][20]; // going UP
bool v[100000];
int lst[100000][20];
void adv(int&x, int v) {
  for (int b=0;(1<<b)<=v;b++) {
    if ((1<<b)&v)x=p[x][b];
  }
}
int lca(int a, int b) {
  if (d[a]>d[b]) swap(a,b);
  adv(b,d[b]-d[a]);
  if (a==b) return a;
  for (int k=19;k>=0;k--) {
    if (p[a][k]!=p[b][k]) a=p[a][k],b=p[b][k];
  }
  return p[a][0];
}
bool isi(int x, int v) {
  int l=-1;
  for (int b=0;(1<<b)<=v;b++) {
    if ((1<<b)&v) {
      bool r=si[x][b]&&l<a[x];
      if (!r) return false;
      l=lst[x][b];
      x=p[x][b];
    }
  }
  return true;
}
bool isd(int x, int v) {
  int l=INF;
  for (int b=0;(1<<b)<=v;b++) {
    if ((1<<b)&v) {
      bool r=sd[x][b]&&l>a[x];
      if (!r) return false;
      l=lst[x][b];
      x=p[x][b];
    }
  }
  return true;
}
bool isb(int x, int v) {
  int l=-1, rv=v;
  for (int b=0;(1<<b)<=v;b++) {
    if ((1<<b)&v) {
      // debug(x,b,sb[x][b]);
      rv&=~(1<<b);
      if (sb[x][b]&&isd(p[x][b],rv)) return true;
      if (!(si[x][b]&&l<a[x])) return false;
      l=lst[x][b];
      x=p[x][b];
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    int n, q;
    cin>>n>>q;
    for (int i=0;i<n;i++)adj[i].clear(),v[i]=false;
    for (int i=0;i<n-1;i++) {
      int a,b;
      cin>>a>>b;
      a--,b--;
      adj[a].push_back(b);
      adj[b].push_back(a);
    }
    for (int i=0;i<n;i++)cin>>a[i];
    queue<int> bfs;
    bfs.push(0);
    p[0][0]=d[0]=0;
    v[0]=true;
    while(bfs.size()) {
      int c=bfs.front();bfs.pop();
      si[c][0]=a[c]<a[p[c][0]];
      sd[c][0]=a[c]>a[p[c][0]];
      sb[c][0]=a[c]!=a[p[c][0]];
      lst[c][0]=a[c];
      for (int nb:adj[c]) {
        if (v[nb])continue;
        v[nb]=true;
        d[nb]=d[c]+1;
        p[nb][0]=c;
        bfs.push(nb);
      }
    }
    for (int k=1;k<20;k++) {
      for (int i=0;i<n;i++) {
        p[i][k]=p[p[i][k-1]][k-1];
        si[i][k]=si[i][k-1]&&si[p[i][k-1]][k-1]&&lst[i][k-1]<a[p[i][k-1]];
        sd[i][k]=sd[i][k-1]&&sd[p[i][k-1]][k-1]&&lst[i][k-1]>a[p[i][k-1]];
        sb[i][k]=(sb[i][k-1]&&sd[p[i][k-1]][k-1])||(si[i][k-1]&&sb[p[i][k-1]][k-1])
          ||(si[i][k-1]&&sd[p[i][k-1]][k-1]&&lst[i][k-1]!=a[p[i][k-1]]);
        lst[i][k]=lst[p[i][k-1]][k-1];
      }
    }
    // for (int x=6;x>=0;x--) for (int i=0;i<3;i++) debug(x+1,i,si[x][i],sd[x][i],sb[x][i]);
    // debug(isb(6,3));
    while (q--) {
      int x,y;
      cin>>x>>y;
      // debug(x,y);
      x--,y--;
      int c=lca(x,y);
      int ld=d[x]-d[c],rd=d[y]-d[c];
      bool il=isi(x,ld),dl=isd(x,ld),bl=isb(x,ld);
      bool ir=isi(y,rd),dr=isd(y,rd),br=isb(y,rd);
      // debug(x+1,y+1,c+1,il,dl,bl,ir,dr,br);
      cout<<(
        (il&&dr)||(dl&&ir)||(il&&ir)||(bl&&ir)||(il&&br)
      );
    }
    cout<<'\n';
  }
}
