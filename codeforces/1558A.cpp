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
void add(vector<ll>&v,ll a,ll b,ll del=0) {
  ll m=(a+b)/2;
  for (ll s=m-a;s<=m+a;s+=2) {
    v.push_back(s+del);
  }
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
    ll a,b;
    cin>>a>>b;
    if (a>b) swap(a,b);
    vector<ll> v;
    if ((a+b)%2==0) add(v,a,b);
    else {
      add(v,a-1,b,0);
      add(v,a,b-1,1);
      add(v,a-1,b,1);
      add(v,a,b-1,0);
    }
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()), v.end());
    cout<<v.size()<<'\n';
    for (ll i=0;i<v.size();i++) {
      cout<<v[i]<<(i==v.size()-1?'\n':' ');
    }
  }
}
