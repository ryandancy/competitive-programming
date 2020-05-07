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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--) {
    int a1, b1, a2, b2;
    cin>>a1>>b1>>a2>>b2;
    if (a1>b1)swap(a1,b1);
    if (a2>b2)swap(a2,b2);
    cout<<(b1==b2&&a1+a2==b1?"Yes\n":"No\n");
  }
}
