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
bool e[100000], v[100000]={false};
int nph[100000]={0}, vs[100000]={0}, nv=0;
vector<int> d[100000];
queue<int> q0,q1;
void tr(queue<int>& q, queue<int>& oq, bool vl) {
  while (q.size()) {
    int c=q.front(); q.pop();
    if (v[c]||vs[c]<nph[c]) continue;
    debug(c,vl);
    v[c]=true, nv++;
    for (int nb:d[c]) {
      if (v[nb]) continue;
      (e[nb]==vl?q:oq).push(nb);
      vs[nb]++;
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n,m;
  cin>>n>>m;
  for (int i=0;i<n;i++)cin>>e[i];
  for (int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    d[b].push_back(a); nph[a]++;
  }
  int res=0;
  for (int i=0;i<n;i++) {
    if (nph[i]==0) (e[i]?q1:q0).push(i);
  }
  while (nv<n) {
    tr(q0,q1,false);
    if (nv>=n) break;
    res++;
    tr(q1,q0,true);
  }
  cout<<res<<'\n';
}
