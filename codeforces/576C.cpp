#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll n;
pll xy[1000000];
vector<pll*> ct[1000][1000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  for (ll i=0;i<n;i++){
    cin>>xy[i].first>>xy[i].second;
    if (xy[i].first==1000000)xy[i].first--;
    if (xy[i].second==1000000)xy[i].second--;
  }
  for (ll i=0;i<n;i++){
    ct[xy[i].first/1000][xy[i].second/1000].push_back(&xy[i]);
  }
  ll i=0;
  for (ll y=0;y<1000;y++) {
    bool f=y%2==0;
    for (ll x=f?0:999;f?x<1000:x>=0;f?x++:x--) {
      sort(ct[x][y].begin(),ct[x][y].end(),[&](pll*a,pll*b){
        return *a < *b;
      });
      for (pll*p:ct[x][y]) {
        i++;
        cout<<p-xy+1;
        if (i==n)cout<<'\n';
        else cout<<' ';
      }
    }
  }
}
