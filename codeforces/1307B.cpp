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
int a[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin >> T;
  while (T--) {
    int n, x;
    cin >> n >> x;
    int mx=0;
    bool ri=false;
    for (int i=0;i<n;i++) {
      cin >> a[i];
      mx=max(mx,a[i]);
      if (a[i]==x)ri=true;
    }
    if (ri){cout<<"1\n";continue;}
    if (2*mx>=x){cout<<"2\n";continue;}
    int c=x/mx-1;
    x-=c*mx;
    bool ok=false;
    for (int i=0;i<n;i++) {
      if (a[i]==x){ok=true;break;}
    }
    if (ok)c++;
    else c+=2;
    cout<<c<<'\n';
  }
}
