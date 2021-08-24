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
ll a[2021],n;
void dosw(ll p) {
  for (ll i=0;i<p/2;i++) {
    swap(a[i],a[p-i-1]);
  }
  // debug('p', p);
  // for (ll i=0;i<n;i++) {
  //   debug(i, a[i]);
  // }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    cin>>n;
    vector<ll> res;
    for (ll i=0;i<n;i++)cin>>a[i];
    for (ll i=0;i<n;i++){
      if (a[i]%2==i%2) {
        cout<<"-1\n";
        goto nxt;
      }
    }
    for (ll k=n;k>1;k-=2) {
      ll i=find(a,a+k,k)-a;
      if (i!=0) {
        res.push_back(i+1); dosw(i+1);
      }
      i=find(a,a+k,k-1)-a;
      if (i!=1) {
        res.push_back(i); dosw(i);
        res.push_back(i+2); dosw(i+2);
        res.push_back(3); dosw(3);
      }
      // ll i=find(a,a+k,k-1)-a;
      // res.push_back(i+2);
      // dosw(i+2);
      // i=find(a,a+k,k)-a;
      // if (i!=0) {
      //   res.push_back(i-1);
      //   dosw(i-1);
      //   res.push_back(i+1);
      //   dosw(i+1);
      // }
      res.push_back(k);
      dosw(k);
    }
    for (ll i=0;i<n;i++) {
      if (a[i]!=i+1) {
        cout<<("NO!\n");
        for (ll i=0;i<n;i++) {
          cout<<(i)<<" "<<(a[i])<<"\n";
        }
        // return 1;
        break;
      }
    }
    if (res.size()>5*n/2) {
      cout<<("NO!\n");
      for (ll i=0;i<n;i++) {
          cout<<(i)<<" "<<(a[i])<<"\n";
        }
      // return 1;
    }
    cout<<res.size()<<'\n';
    for (ll i=0;i<res.size();i++) {
      cout<<res[i]<<(i==res.size()-1?'\n':' ');
    }
    nxt:;
  }
}
