#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
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
  cin>>t;
  while (t--) {
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++) for (int j=0;j<m;j++) {
      ll a;
      cin>>a;
      bool o=i%2==j%2;
      if (a%2!=o) a++;
      cout<<a;
      cout<<(j==m-1?'\n':' ');
    }
  }
}
