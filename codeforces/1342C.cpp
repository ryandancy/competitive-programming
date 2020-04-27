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
bool v[40000];
ll ps[40000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin>>T;
  while (T--) {
    ll a, b, q;
    cin>>a>>b>>q;
    for (int i=0;i<a*b;i++){
      v[i]=(i%a)%b!=(i%b)%a;
    }
    ps[0]=v[0];
    for (int i=1;i<a*b;i++){
      ps[i]=ps[i-1]+v[i];
    }
    ll l, r;
    for (int i=0;i<q;i++){
      cin>>l>>r;
      ll nl=ps[a*b-1]*((l-1)/(a*b))+ps[(l-1)%(a*b)];
      ll nr=ps[a*b-1]*(r/(a*b))+ps[r%(a*b)];
      cout<<nr-nl<<(i==q-1?'\n':' ');
    }
  }
}
