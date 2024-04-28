#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000001
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

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--) {
    ll n,c,d;
    cin>>n>>c>>d;
    vector<ll> b(n*n);
    ll a=INF;
    for (int i=0;i<n*n;i++) {
      ll bi;
      cin>>bi;
      b.push_back(bi);
      if (bi<a) a=bi;
    }
    vector<ll> exp(n*n);
    for (int i=0;i<n;i++) for (int j=0;j<n;j++) {
      exp.push_back(a + i*c + j*d);
    }
    sort(b.begin(),b.end());
    sort(exp.begin(),exp.end());
    if (b==exp) cout<<"YES\n";
    else cout<<"NO\n";
  }
}
