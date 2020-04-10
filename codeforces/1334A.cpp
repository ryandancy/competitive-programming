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
  while (T--){
    int n;
    cin>>n;
    int op, oc;
    cin>>op>>oc;
    bool ok=op>=oc;
    for (int i=0;i<n-1;i++){
      int p, c;
      cin>>p>>c;
      if (c>p||(c-oc)>(p-op)||c<oc||p<op){ok=false;}
      op=p,oc=c;
    }
    cout<<(ok?"YES\n":"NO\n");
  }
}
