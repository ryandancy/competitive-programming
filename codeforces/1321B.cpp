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
ll b[200000];
ll bl[200000];
ll blv[1000000]={0};
// vector<int> bv[4000000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin >> n;
  for (int i=0;i<n;i++){cin>>b[i];}//bv[b[i]].push_back(i);}
  for (int i=0;i<n;i++)bl[i]=b[i]-i+400000;
  for (int i=0;i<n;i++)blv[bl[i]] += b[i];
  ll mx=blv[bl[0]];
  for (int i=0;i<n;i++)mx=max(mx,blv[bl[i]]);
  cout<<mx<<'\n';
  // dp[n-1]=b[n-1];
  
}
