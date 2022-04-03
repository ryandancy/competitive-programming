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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin>>T;
  for (ll t=0;t<T;t++) {
    cout<<"Case #"<<(t+1)<<": ";
    ll c=INF,m=INF,y=INF,k=INF;
    for (int i=0;i<3;i++) {
      ll ci,mi,yi,ki;
      cin>>ci>>mi>>yi>>ki;
      c=min(c,ci);
      m=min(m,mi);
      y=min(y,yi);
      k=min(k,ki);
    }
    if (c+m+y+k<1000000) {
      cout<<"IMPOSSIBLE\n";
      continue;
    } else if (c+m+y<1000000) {
      k=1000000-(c+m+y);
    } else if (c+m<1000000) {
      k=0;
      y=1000000-(c+m);
    } else if (c<1000000) {
      y=k=0;
      m=1000000-c;
    } else {
      m=y=k=0;
      c=1000000;
    }
    cout<<c<<" "<<m<<" "<<y<<" "<<k<<"\n";
  }
}
