#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cassert>
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
struct nd {
  string lb; int p, i; nd *l, *r;
} *nds[50000], *mx[50000][16];
bool lbcmp(const nd* const& a, const nd* const& b) {
  return a->lb<b->lb;
}
nd *mmx(nd *a, nd *b) {
  return a->p<b->p?b:a;
}
nd *mxr(int l, int r) { // [l,r)
  int k=31-__builtin_clz(r-l);
  return mmx(mx[l][k], mx[r-(1<<k)][k]);
}
void mk(nd *rt, int l, int r) { // [l,r)
  int i=rt->i;
  if (i>l) rt->l = mxr(l, i), mk(rt->l, l, i);
  if (i<r-1) rt->r = mxr(i+1, r), mk(rt->r, i+1, r);
}
void pr(nd *c) {
  if (!c) return;
  cout<<'(';
  if (c->l) pr(c->l);
  cout<<c->lb<<'/'<<c->p;
  if (c->r) pr(c->r);
  cout<<')';
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  for (int i=0;i<50000;i++){
    nds[i]=new nd;
  }
  int n;
  while (cin>>n, n) {
    for (int i=0;i<n;i++) {
      string s;
      cin>>s;
      int slh=s.find('/');
      nds[i]->lb=s.substr(0, slh);
      nds[i]->p=atoi(s.substr(slh+1).c_str());
      nds[i]->l=nds[i]->r=NULL;
    }
    sort(nds,nds+n,lbcmp);
    for (int i=0;i<n;i++) {
      mx[i][0]=nds[i];
      nds[i]->i=i;
    }
    for (int k=1,s=2;k<16;k++,s*=2) {
      for (int i=0;i<=n-s;i++){
        mx[i][k]=mmx(mx[i][k-1], mx[i+s/2][k-1]);
      }
    }
    nd *rt=mxr(0, n);
    mk(rt, 0, n);
    pr(rt);
    cout<<'\n';
  }
  for (int i=0;i<50000;i++) {
    delete nds[i];
  }
}
