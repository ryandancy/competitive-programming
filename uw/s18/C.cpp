#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
double trial() {
  int m;
  scanf("%d",&m);
  double r[8];
  for (int i=0;i<m;i++)scanf("%lf",r+i);
  sort(r,r+m);
  double bst=-1;
  double p[8];
  do {
    p[0]=r[0];
    for (int i=1;i<m;i++) {
      double mxp=-1;
      for (int j=0;j<i;j++) {
        double np=p[j]+2*sqrt(r[i]*r[j]);
        if (np<r[i])np=r[i];
        if (mxp<0||np>mxp)mxp=np;
      }
      p[i]=mxp;
    }
    double fm=0;
    for (int i=0;i<m;i++) {
      fm=max(fm,p[i]+r[i]);
    }
    double v=fm;
    if (bst<0||v<bst) {
      bst=v;
    }
  } while (next_permutation(r,r+m));
  return bst;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  while (n--) printf("%.3f\n", trial());
}
