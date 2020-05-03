#include <cstdio>
#include <iostream>
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
  double sum=0;
  for (int i=0;i<12;i++){
    double nxt;
    scanf("%lf", &nxt);
    sum+=nxt;
  }
  printf("$%.2f\n", sum / 12.0);
}
