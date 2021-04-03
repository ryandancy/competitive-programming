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
char c[2][200000]={{0}};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    ll n; string s;
    cin>>n>>s;
    if (s[0]=='0'||s[n-1]=='0') {
      cout<<"NO\n";
      continue;
    }
    vector<ll> v[2];
    for (ll i=0;i<n;i++) {
      v[s[i]=='0'].push_back(i);
    }
    if (v[0].size()%2==1||v[1].size()%2==1) {
      cout<<"NO\n";
      continue;
    }
    for (ll i=0;i<v[0].size()/2;i++) {
      debug(v[0][i],v[0][v[0].size()-i-1]);
      c[0][v[0][i]]=c[1][v[0][i]]='(';
      c[0][v[0][v[0].size()-i-1]]=c[1][v[0][v[0].size()-i-1]]=')';
    }
    for (ll i=0;i<v[1].size()/2;i++) {
      debug(v[0][i],v[0][v[0].size()-i-1]);
      c[0][v[1][i]]=i%2==0?'(':')';
      c[0][v[1][v[1].size()-i-1]]=i%2==0?')':'(';
      c[1][v[1][i]]=i%2==0?')':'(';
      c[1][v[1][v[1].size()-i-1]]=i%2==0?'(':')';
    }
    cout<<"YES\n";
    for (ll i=0;i<n;i++) {
      cout<<c[0][i];
    }
    cout<<'\n';
    for (ll i=0;i<n;i++) {
      cout<<c[1][i];
    }
    cout<<'\n';
  }
}
