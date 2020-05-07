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
vector<int> gt[200000], lt[200000];
int vs[200000]={0};
bool vl[200000]={false}, vg[200000]={false};
bool A[200000]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin>>n>>m;
  for (int i=0;i<m;i++){
    int a,b;
    cin>>a>>b;
    a--, b--;
    gt[b].push_back(a);
    lt[a].push_back(b);
  }
  stack<int> st, ts;
  for (int i=0;i<n;i++){
    if (vs[i])continue;
    st.push(i), ts.push(0);
    while (st.size()) {
      int t=ts.top(), c=st.top();
      ts.pop(), st.pop();
      if (t==0) {
        if (vs[c]==2)continue;
        if (vs[c]==1)return cout<<"-1\n",0;
        vs[c]=1;
        ts.push(1);
        st.push(c);
        for (int nx:gt[c]) {
          if (vs[nx]==2)continue;
          if (vs[nx]==1)return cout<<"-1\n",0;
          ts.push(0);
          st.push(nx);
        }
      } else {
        vs[c]=2;
      }
    }
  }
  int res=0;
  for (int i=0;i<n;i++){
    if (!vg[i]&&!vl[i]) {
      A[i]=true;
      res++;
    }
    st.push(i);
    while (st.size()) {
      int c=st.top(); st.pop();
      if (vg[c])continue;
      vg[c]=true;
      for (int g:gt[c]) {
        if (!vg[g])st.push(g);
      }
    }
    st.push(i);
    while (st.size()) {
      int c=st.top(); st.pop();
      if (vl[c])continue;
      vl[c]=true;
      for (int l:lt[c]) {
        if (!vl[l])st.push(l);
      }
    }
  }
  cout<<res<<'\n';
  for (int i=0;i<n;i++){
    cout<<(A[i]?'A':'E');
  }
  cout<<'\n';
}
