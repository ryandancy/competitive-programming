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
bool cont(vector<ll>&v,ll h) {
  for (ll x:v) if (h==x) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin>>T;
  for (ll t=1;t<=T;t++) {
    vector<ll> all;
    ll n;
    cin>>n;
    ll sum=0;
    ll c=0;
    for (ll i=0;i<=29;i++) {
      c++;
      cout<<(1<<i)<<' ';
      sum+=(1<<i);
      all.push_back(1<<i);
    }
    // c+=2;
    // cout<<(1<<29)-1<<' '<<(1<<29)+1<<' ';
    // sum+=(1<<29);
    // all.push_back((1<<29)-1);
    // all.push_back((1<<29)+1);
    ll k=1;
    while (c<n) {
      while (cont(all,k))k++;
      all.push_back(k);
      cout<<k;
      sum+=k;
      k++;
      c++;
      cout<<(c==n?'\n':' ');
    }
    cout.flush();
    for (ll i=0;i<n;i++){ll x;cin>>x;all.push_back(x);sum+=x;}
    ll ta=sum/2,tb=sum/2;
    // cout<<sum<<"\n";
    sort(all.begin(),all.end());
    vector<ll>a;
    for (ll i=all.size()-1;i>=0;i--) {
      // cout<<all[i]<<' '<<ta<<' '<<tb<<'\n';
      if (ta>tb) {
        a.push_back(all[i]);
        ta-=all[i];
      } else tb-=all[i];
    }
    for (ll i=0;i<a.size();i++) {
      cout<<a[i]<<(i==a.size()-1?'\n':' ');
    }
    cout.flush();
  }
}
