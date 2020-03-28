#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
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
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int N;
  cin>>N;
  cout<<setprecision(20);
  while (N--){
    ld n, l, d, g;
    cin>>n>>l>>d>>g;
    ld th = PI*(n-2)/n;
    ld a=n*l*l/4.0l/tan(PI/n);
    a+=d*l*n*g;
    ld phi=PI-th;
    a+=phi/2.0l * (d*g)*(d*g)*n;
    cout<<a<<'\n';
  }
}
