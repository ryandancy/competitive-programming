#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll h[1000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll n;
  cin>>n;
  ll H=0;
  for (int i=0;i<n;i++)cin>>h[i],H+=h[i];
  ll k=H-n*(n-1)/2;
  // debug(H,k,n*(n+1)/2);
  for (int i=0;i<n;i++){
    cout<<(i+max(k-i,0ll)/n+(max(k-i,0ll)%n!=0))<<(i==n-1?'\n':' ');
  }
}
