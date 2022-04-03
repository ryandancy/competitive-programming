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
ll a[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin>>T;
  for (ll t=1;t<=T;t++) {
    cout<<"Case #"<<t<<": ";
    ll n;
    cin>>n;
    for (ll i=0;i<n;i++) cin>>a[i];
    sort(a,a+n);
    ll res=0;
    ll exp=1;
    for (ll i=0;i<n;i++) {
      if (a[i]>=exp) {
        exp++;
        res++;
      }
    }
    cout<<res<<'\n';
  }
}
