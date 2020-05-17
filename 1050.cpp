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
// this is glorified brute force lol and won't work
int n, a[100][100], s[100][100], bst=-INF;
inline int S(int i1, int j1, int i2, int j2) {
  return s[i2][j2]-(i1?s[i1-1][j2]:0)-(j1?s[i2][j1-1]:0)+(i1&&j1?s[i1-1][j1-1]:0);
}
int g(int i, int j, int J) {
  int r=-INF;
  for (int k=0;k<=i;k++) r=max(r,S(k,J,i,j));
  bst=max(bst,r);
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  scanf("%d", &n);
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) scanf("%d", &a[i][j]);
  for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
    s[i][j]=a[i][j];
    if (i>0) s[i][j]+=s[i-1][j];
    if (j>0) s[i][j]+=s[i][j-1];
    if (i>0&&j>0) s[i][j]-=s[i-1][j-1];
  }
  for (int i=0;i<n;i++) {
    int J=0;
    for (int j=0;j<n;j++) {
      int v=g(i,j,J);
      while (J<j) {
        int v2=g(i,j,J+1);
        // debug(i,j,J,v,v2);
        if (v2>v) v=v2, J++;
        else break;
      }
      debug(i,j,J,v);
    }
  }
  printf("%d\n", bst);
}
