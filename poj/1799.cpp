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
  int T;
  scanf("%d\n", &T);
  for (int sc=1;sc<=T;sc++) {
    printf("Scenario #%d:\n", sc);
    float R; int n;
    scanf("%f %d\n", &R, &n);
    float sn=sin((float)PI/(float)n);
    float r=R*sn/(sn+1.0);
    float res=round(r*1000.0)/1000.0;
    printf("%.3f\n\n", res);
  }
}
