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
int a[50000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int on, m;
  while (scanf("%d %d", &on, &m), on!=-1) {
    ll n=on;
    int l=0, r=n-1, s=1;
    while (n>0) {
      if (m <= (n-1)*(n-2)/2) {
        a[l++]=s;
      } else {
        m-=n-1;
        a[r--]=s;
      }
      n--, s++;
    }
    for (int i=0;i<on;i++) {
      printf("%d%c", a[i], i==on-1?'\n':' ');
    }
  }
}
