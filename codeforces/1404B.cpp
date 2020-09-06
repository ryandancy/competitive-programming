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
int n,a,b,da,db;
vector<int> adj[100000];
bool v[100000], v2[100000]; int dsa[100000], dsm[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    cin>>n>>a>>b>>da>>db;
    a--,b--;
    for (int i=0;i<n;i++)adj[i].clear(),v[i]=false,v2[i]=false;
    for (int i=0;i<n-1;i++) {
      int x,y;
      cin>>x>>y;
      x--,y--;
      adj[x].push_back(y);
      adj[y].push_back(x);
    }
    if (db<2*da+1){cout<<"Alice\n"; continue;}
    queue<int> bfs, ds;
    bfs.push(a); ds.push(0);
    int mx=0,mi=0;
    while (bfs.size()) {
      int c=bfs.front(); bfs.pop();
      int d=ds.front(); ds.pop();
      v[c]=true;
      dsa[c]=d;
      if (d>mx) {mx=d; mi=c;}
      for (int&nb:adj[c]) {
        if (!v[nb]) bfs.push(nb), ds.push(d+1);
      }
    }
    // debug(dsa[b]);
    if (dsa[b]<=da) {cout<<"Alice\n";continue;}
    bfs.push(mi); ds.push(0);
    int mx2=0;
    while (bfs.size()) {
      int c=bfs.front(); bfs.pop();
      int d=ds.front(); ds.pop();
      v2[c]=true;
      dsm[c]=d;
      mx2=max(mx2,d);
      for (int&nb:adj[c]) {
        if (!v2[nb]) bfs.push(nb), ds.push(d+1);
      }
    }
    // debug(mx2);
    if (mx2<2*da+1) cout<<"Alice\n";
    else cout<<"Bob\n";
  }
}
