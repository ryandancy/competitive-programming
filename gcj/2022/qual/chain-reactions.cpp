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

ll f[200000];
ll res[200000];
void solve(ll i, vector<vector<ll>>& ch) {
  if (ch[i].empty()) {
    res[i]=f[i];
    return;
  }
  for (ll c:ch[i]) solve(c,ch);
  ll m=-1,mi=-1;
  for (ll c:ch[i]) {
    if (m==-1||res[c]<m) {
      m=res[c];
      mi=c;
    }
  }
  res[mi]=0;
  res[i]=max(m,f[i]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin>>T;
  for (ll t=1;t<=T;t++) {
    cout<<"Case #"<<t<<": ";
    ll n;
    cin>>n;
    for (ll i=0;i<n;i++) cin>>f[i];
    vector<vector<ll>> ch(n);
    vector<ll> roots;
    for (ll i=0;i<n;i++) {
      ll p;
      cin>>p;
      if (p==0) {
        roots.push_back(i);
      } else {
        p--;
        ch[p].push_back(i);
      }
    }
    for (ll r:roots) solve(r,ch);
    ll v=0;
    for (ll i=0;i<n;i++) v+=res[i];
    cout<<v<<'\n';
  }
}
