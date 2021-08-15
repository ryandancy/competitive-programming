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
ll a[1000],b[1000];
vector<pll> pa,pb;
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
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) cin>>b[i];
    pa.clear(), pb.clear();
    if (n%2==1 && a[n/2]!=b[n/2]){cout<<"No\n";continue;}
    for (int i=0,j=n-1;i<j;i++,j--) {
      pa.push_back({min(a[i],a[j]),max(a[i],a[j])});
      pb.push_back({min(b[i],b[j]),max(b[i],b[j])});
    }
    sort(pa.begin(),pa.end());
    sort(pb.begin(),pb.end());
    if (pa==pb) cout<<"Yes\n";
    else cout<<"No\n";
  }
}
