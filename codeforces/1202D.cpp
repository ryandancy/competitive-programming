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
    ll n;
    cin>>n;
    ll m=1;
    while (m*(m+1ll)/2ll<=n)m++;
    if (m<=2){
      cout<<"133";
      for (int i=0;i<n;i++)cout<<'7';
      cout<<'\n';
      continue;
    }
    ll df=n-(m*(m-1ll)/2ll);
    cout<<"133";
    for (int i=0;i<df;i++)cout<<'7';
    for (int i=0;i<m-2;i++)cout<<'3';
    cout<<"7\n";
  }
}
