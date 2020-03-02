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
vector<int> frm[200000], adj[200000];
int d[200000];
bool v[200000]={false};
int p[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin >> n >> m;
  for (int i=0;i<m;i++) {
    int a, b;
    cin >> a >> b;
    a--,b--;
    frm[b].push_back(a);
    adj[a].push_back(b);
  }
  int k;
  cin >> k;
  for (int i=0;i<k;i++){cin>>p[i];p[i]--;}
  int t=p[k-1];
  priority_queue<pii> q;
  q.push({0,t});
  v[t]=true;
  while (q.size()) {
    pii a=q.top();q.pop();
    // debug(a.second);
    int c=a.second;
    d[c]=-a.first;
    for (int nb : frm[c]) {
      if (v[nb])continue;
      v[nb]=true;
      // debug("nb",nb);
      q.push({a.first-1,nb});
    }
  }
  // for (int i=0;i<n;i++)debug('d',i,d[i]);
  int mnr=0,mxr=0;
  for (int i=0;i<k-1;i++) {
    bool mr=d[p[i+1]]>d[p[i]]-1;
    bool cr=mr;
    if (!cr) {
      for (int nb : adj[p[i]]) {
        if (nb!=p[i+1]&&d[nb]<=d[p[i]]-1) {
          cr=true;
          // debug(p[i],nb);
          break;
        }
      }
    }
    if (cr) {
      mxr++;
    }
    if (mr) {
      mnr++;
    }
  }
  cout<<mnr<<' '<<mxr<<'\n';
}
