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
int a[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>a[i];
    if (a[n-1]==0) {
      for (int i=1;i<=n+1;i++) cout<<i<<(i==n+1?'\n':' ');
      continue;
    }
    if (a[0]==1) {
      cout<<n+1;
      for (int i=1;i<=n;i++)cout<<' '<<i;
      cout<<'\n';
      continue;
    }
    int i=0;
    for (i=0;i<n;i++) if (a[i]==1) break;
    vector<int> res;
    for (int j=0;j<i;j++) res.push_back(j);
    res.push_back(n);
    for (int j=i;j<n;j++) res.push_back(j);
    for (int i=0;i<res.size();i++) {
      cout<<res[i]+1<<(i==res.size()-1?'\n':' ');
    }
  }
}
