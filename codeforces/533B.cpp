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
vector<int> ch[200000]; ll p[200000], a[200000], mxo[200000], mxe[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  int rt;
  for (int i=0;i<n;i++){
    cin>>p[i]>>a[i];
    if (p[i]==-1)rt=i;
    else ch[p[i]-1].push_back(i);
  }
  stack<pii> st;
  st.push({0,rt});
  while (!st.empty()) {
    int t, c;
    tie(t,c)=st.top();st.pop();
    if (t==0) {
      if (ch[c].size()==0) {
        mxo[c] = a[c];
        mxe[c] = 0;
        continue;
      }
      st.push({1,c});
      for (int chl:ch[c])st.push({0,chl});
      continue;
    }
    mxo[c]=mxe[c]=0;
    vector<int> be, bo;
    for (int chl:ch[c]) (mxo[chl]>mxe[chl]?bo:be).push_back(chl);
    if (bo.size()%2==1) {
      if (be.size()) sort(be.begin(),be.end(),[&](int a,int b){return mxe[a]-mxo[a]>mxe[b]-mxo[b];});
      if (bo.size()) sort(bo.begin(),bo.end(),[&](int a,int b){return mxo[a]-mxe[a]>mxo[b]-mxe[b];});
      if (!be.empty()&&mxe[be.back()]-mxo[be.back()]<mxo[bo.back()]-mxe[bo.back()]) {
        bo.push_back(be.back());
        be.pop_back();
      } else {
        be.push_back(bo.back());
        bo.pop_back();
      }
    }
    for (int e:be) {
      mxe[c]+=mxe[e];
    }
    for (int o:bo) {
      mxe[c]+=mxo[o];
    }
    if (bo.size()%2==0) {
      if (be.empty()&&bo.empty()) goto nx;
      if (be.size()) sort(be.begin(),be.end(),[&](int a,int b){return mxe[a]-mxo[a]>mxe[b]-mxo[b];});
      if (bo.size()) sort(bo.begin(),bo.end(),[&](int a,int b){return mxo[a]-mxe[a]>mxo[b]-mxe[b];});
      if (!be.empty()&&(bo.empty()||mxe[be.back()]-mxo[be.back()]<mxo[bo.back()]-mxe[bo.back()])) {
        bo.push_back(be.back());
        be.pop_back();
      } else {
        be.push_back(bo.back());
        bo.pop_back();
      }
    }
    nx:
    for (int e:be) {
      mxo[c]+=mxe[e];
    }
    for (int o:bo) {
      mxo[c]+=mxo[o];
    }
    mxo[c]=max(mxo[c], mxe[c]+a[c]);
  }
  cout<<max(mxe[rt], mxo[rt])<<'\n';
}
