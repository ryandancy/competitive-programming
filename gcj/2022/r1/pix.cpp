#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define c(x,y) ((x)+R+((y)+R)*(2*R+1))
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin>>T;
  for (ll t=1;t<=T;t++) {
    cout<<"Case #"<<t<<": ";
    ll R;
    cin>>R;
    vector<bool> fw((2*R+1)*(2*R+1));
    for (ll r=0;r<=R;r++) {
      for (ll x=-r;x<=r;x++) {
        ld s=sqrtl(r*r-x*x);
        ll y=roundl(s);
        fw[c(x,y)]=true;
        fw[c(x,-y)]=true;
        fw[c(y,x)]=true;
        fw[c(-y,x)]=true;
      }
    }
    ll ans=0;
    for (ll x=-R;x<=R;x++) {
      for (ll y=-R;y<=R;y++) {
        if (fw[c(x,y)]!=(4*(x*x+y*y)<=4*R*R+4*R+1)) {
          ans++;
        }
      }
    }
    cout<<ans<<'\n';
  }
}
