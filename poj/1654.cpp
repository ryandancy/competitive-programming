#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  scanf("%d", &t);
  while (t--) {
    ll A=0;
    ll x1=0, y1=0;
    while (1) {
      char s;
      scanf("%c", &s);
      int c=s-'0';
      if (c==5)break;
      ll x2=x1+(c==6||c==9||c==3)-(c==4||c==7||c==1);
      ll y2=y1+(c==8||c==9||c==7)-(c==2||c==3||c==1);
      A+=x1*y2-y1*x2;
      x1=x2, y1=y2;
    }
    if (A<0) A=-A;
    printf("%I64d", A/2);
    if (A%2) printf(".5");
    printf("\n");
  }
}
