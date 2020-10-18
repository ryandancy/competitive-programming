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
ll n,m,k,t,w[1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m>>k>>t;
  for (int i=0;i<k;i++){
    ll a,b;
    cin>>a>>b;
    a--,b--;
    w[i]=a*m+b;
  }
  sort(w,w+k);
  while (t--) {
    ll a,b;
    cin>>a>>b;
    a--,b--;
    ll v=a*m+b;
    ll i=lower_bound(w,w+k,v)-w;
    if (i<k&&w[i]==v)cout<<"Waste\n";
    else {
      v-=i;
      v%=3;
      if (v==0)cout<<"Carrots\n";
      else if (v==1) cout<<"Kiwis\n";
      else cout<<"Grapes\n";
    }
  }
}
