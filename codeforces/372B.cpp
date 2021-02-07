// lol it's O(qn^2 + n^4) but fast enough in practice
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,q;
string mp[40];
ll rd[40];
ll r[40][40][40][40]={{{{0}}}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>m>>q;
  for (ll i=0;i<n;i++)cin>>mp[i];
  for (ll a=0;a<n;a++) {
    for (ll c=a;c<n;c++) {
      for (ll i=0;i<m;i++) {
        rd[i]=0;
        for (ll j=a;j<=c;j++) {
          if (mp[j][i]=='1') {
            rd[i]=1;
            break;
          }
        }
      }
      for (ll b=0;b<m;b++) {
        ll rn=0,s=0;
        for (ll d=b;d<m;d++) {
          if (rd[d]==0) s++;
          else rn+=s*(s+1)/2,s=0;
          r[a][c][b][d]=rn+s*(s+1)/2;
        }
      }
    }
  }
  while (q--) {
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    a--,b--,c--,d--;
    ll res=0;
    for (ll na=a;na<=c;na++) {
      for (ll nc=na;nc<=c;nc++) {
        res+=r[na][nc][b][d];
      }
    }
    cout<<res<<'\n';
  }
}
