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
ll w[100];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ll t;
  cin>>t;
  while (t--)
 {
   ll n,x;
   cin>>n>>x;
   for (ll i=0;i<n;i++)cin>>w[i];
   sort(w,w+n);
   ll p=0,i;
   for (i=0;i<n;i++) {
     p+=w[i];
     if (p==x) break;
   }
   if (i!=n) {
     if (i==n-1) {cout<<"NO\n"; continue;}
     swap(w[i],w[n-1]);
   }
   cout<<"YES\n";
   for (ll i=0;i<n;i++) {
     cout<<w[i];
     if (i==n-1) cout<<'\n';
     else cout<<" ";
   }
 }}
