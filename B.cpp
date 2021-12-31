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
bool pc[100000]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    ll n;
    string s;
    cin>>n>>s;
    if (n==1) {
      cout<<s<<s<<'\n';
      continue;
    }
    for (ll i=0;i+2<n;i++) {
      if (i==0) pc[i]=s[i]<=s[i+2];
      else pc[i]=s[i]<s[i+2]||(s[i]==s[i+2]&&pc[i-1]);
      // debug(i,pc[i]);
    }
    ll i=0;
    for (;i<n-1;i++) {
      if (i==0) {
        if (s[0]<=s[1]) {
          cout<<s[0]<<s[0]<<'\n';
          goto nxt;
        }
      } else {
        if (s[i]<s[i+1]||(s[i]==s[i+1]&&pc[i-1])) {
          for (ll j=0;j<=i;j++) cout<<s[j];
          for (ll j=i;j>=0;j--) cout<<s[j];
          cout<<'\n';
          goto nxt;
        }
        // debug(i,s[i+1]);
        // if (s[1]<=s[i+1]||s[0]<=s[i+1]) {
        // if (
        //   s[1]<s[i+1]||(s[1]==s[i+1]&&s[0]<=s[i+1])
        // ) {
        //   for (ll j=0;j<=i;j++) cout<<s[j];
        //   for (ll j=i;j>=0;j--) cout<<s[j];
        //   cout<<'\n';
        //   goto nxt;
        // }
      }
    }
    cout<<s;
    for(ll j=n-1;j>=0;j--) cout<<s[j];
    cout<<'\n';
    nxt:;
  }
}
