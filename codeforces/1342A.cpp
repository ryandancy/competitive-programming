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
  int T;
  cin>>T;
  while (T--) {
    ll x,y,a,b;
    cin>>x>>y>>a>>b;
    cout<<min(abs(x)*a+abs(y)*a, min(abs(x)*b+abs(y-x)*a, abs(y)*b+abs(y-x)*a))<<'\n';
  }
}
