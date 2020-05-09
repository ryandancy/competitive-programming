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
int uf[30000], idx[30000]={0}, sz[30000];
void fai(int x, int& r, int& i) {
  if (x==uf[x]) { r=x, i=0; return; }
  fai(uf[x], r, i);
  i+=idx[x];
  uf[x]=r;
  idx[x]=i;
}
int find(int x) {
  int r, i;
  fai(x, r, i);
  return r;
}
int gidx(int x) {
  int r, i;
  fai(x, r, i);
  return i;
}
void mv(int x, int y) { // x onto y
  x=find(x), y=find(y);
  uf[x]=y;
  idx[x]=sz[y];
  sz[y]+=sz[x];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  for (int i=0;i<30000;i++)uf[i]=i, sz[i]=1;
  int p;
  cin>>p;
  char t; int x, y;
  for (int i=0;i<p;i++) {
    cin>>t;
    if (t=='M') {
      cin>>x>>y;
      mv(x-1, y-1);
    } else {
      cin>>x;
      cout<<gidx(x-1)<<'\n';
    }
  }
}
