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
ll r[2000001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  r[1]=r[2]=0;
  for (ll k=3;k<=2000000;k++){
    r[k]=r[k-1]+2*r[k-2]+4*(k%3==0);
    r[k]%=MOD;
    r[k]+=MOD;
    r[k]%=MOD;
  }
  int T;
  cin>>T;
  while (T--) {
    int n;
    cin>>n;
    cout<<r[n]<<'\n';
  }
}
