#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
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
bool v[100000]={false};
int bp[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin>>n>>m;
  for (int i=0;i<m;i++){
    int a, b;
    cin>>a>>b;
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  queue<int> q;
  q.push(0);
  v[0]=true;
  int cnt=1;
  while (q.size()) {
    int c=q.front(); q.pop();
    for (int nb:adj[c]) {
      if (v[nb]) continue;
      v[nb]=true;
      bp[nb]=c;
      q.push(nb);
      cnt++;
    }
  }
  if (cnt!=n) return cout<<"No\n",0;
  cout<<"Yes\n";
  for (int i=1;i<n;i++) cout<<bp[i]+1<<'\n';
  return 0;
}
