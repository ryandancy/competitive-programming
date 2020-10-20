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
typedef unsigned long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll s[1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int m;
  cin>>m;
  for (int i=0;i<m;i++)cin>>s[i];
  ll ag=s[0];
  for (int i=1;i<m;i++) {
    ag=__gcd(ag,s[i]);
  }
  if (ag!=s[0])return cout<<"-1\n",0;
  cout<<2*m<<'\n';
  for (int i=0;i<m;i++) {
    cout<<s[i]<<' '<<ag<<(i==m-1?'\n':' ');
  }
}
