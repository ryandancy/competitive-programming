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
// #ifndef ONLINE_JUDGE
//   freopen("inp.txt", "r", stdin);
// #endif
  ll n;
  cin>>n;
  for (ll y=0;y<n;y++){
    for (ll x=0;x<n;x++){
      ll d=x+y-1;
      if (d<0||y%2==0) cout<<0;
      else cout<<(1ll<<d);
      cout<<(x==n-1?"\n":" ");
    }
    cout.flush();
  }
  ll q;
  cin>>q;
  while (q--){
    ll k;
    cin>>k;
    int x=0,y=0;
    cout<<"1 1\n";
    while (x<n-1||y<n-1) {
      if ((k&1)^(y%2))y++;
      else x++;
      cout<<y+1<<' '<<x+1<<'\n';
      k>>=1;
      cout.flush();
    }
  }
}
