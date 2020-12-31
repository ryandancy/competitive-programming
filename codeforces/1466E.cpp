#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll x[500000],n,bc[60],oj[500000],js[60];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll T;
  cin>>T;
  while (T--) {
    cin>>n;
    fill_n(bc,60,0);
    fill_n(oj,n,0);
    fill_n(js,60,0);
    for (ll i=0;i<n;i++){
      cin>>x[i];
      for (ll b=0;b<60;b++) {
        if (x[i]&(1ll<<b)) bc[b]++;
      }
    }
    for (ll j=0;j<n;j++) {
      for (ll b=0;b<60;b++) {
        if (x[j]&(1ll<<b)) {
          oj[j]+=(n%MOD)*((1ll<<b)%MOD);
        } else {
          oj[j]+=(bc[b]%MOD)*((1ll<<b)%MOD);
        }
        oj[j]%=MOD;
      }
      oj[j]+=MOD;
      oj[j]%=MOD;
    }
    for (ll b=0;b<60;b++) {
      for (ll j=0;j<n;j++) {
        if (x[j]&(1ll<<b)) {
          js[b]+=((1ll<<b)%MOD)*(oj[j]%MOD);
          js[b]%=MOD;
        }
      }
      js[b]+=MOD;
      js[b]%=MOD;
    }
    ll res=0;
    for (ll i=0;i<n;i++) {
      for (ll b=0;b<60;b++) {
        if (x[i]&(1ll<<b)) {
          res+=js[b]%MOD;
          res%=MOD;
        }
      }
    }
    res+=MOD;
    res%=MOD;
    cout<<res<<'\n';
  }
}
