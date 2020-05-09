// this is wayy overkill since there are only 2 nodes to compute
// O(n log n) preprocessing + O(log n) query when we could totally do it in
// O(n) preprocessing + O(n) query.
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <algorithm>
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
vector<int> ch[10000];
int p[10000][15], d[10000];
void av(int& c, int x) {
  debug("advancing", c, "by", x);
  for (int b=0;b<15;b++) {
    if (x&(1<<b)) {
      c=p[c][b];
      debug("advancing", 1<<b);
    }
  }
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
    int n;
    cin>>n;
    for (int i=0;i<n;i++){
      ch[i].clear();
      p[i][0]=i;
    }
    for (int i=0;i<n-1;i++){
      int a, b;
      cin>>a>>b;
      a--, b--;
      ch[a].push_back(b);
      p[b][0]=a;
    }
    int rt;
    for (int i=0;i<n;i++) if (p[i][0]==i) {
      rt=i;
      break;
    }
    for (int k=1;k<15;k++){
      for (int i=0;i<n;i++){
        p[i][k]=p[p[i][k-1]][k-1];
      }
    }
    stack<int> st;
    st.push(rt);
    d[rt]=0;
    while (st.size()) {
      int i=st.top(); st.pop();
      for (int j=0;j<ch[i].size();j++) {
        int c=ch[i][j];
        d[c]=d[i]+1;
        st.push(c);
      }
    }
    int a, b;
    cin>>a>>b;
    a--, b--;
    debug(a, b, d[a], d[b]);
    if (d[a]>d[b])swap(a,b);
    av(b, d[b]-d[a]);
    debug(a, b);
    if (a==b) { cout<<a+1<<'\n'; continue; }
    for (int k=14;k>=0;k--) {
      if (p[a][k]!=p[b][k]) a=p[a][k], b=p[b][k];
    }
    cout<<p[a][0]+1<<'\n';
  }
}
