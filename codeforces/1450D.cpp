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
int a[300000];
int ex[300001];
int res[300001];
vector<int> bkt[300001];
set<int> lt;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    lt.clear();
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)bkt[i].clear(),ex[i]=0,res[i]=0;
    for (int i=0;i<n;i++)cin>>a[i];
    for (int i=0;i<n;i++) {
      bkt[a[i]].push_back(i);
    }
    for (int c=1;c<=n;c++) {
      for (int i:bkt[c]) {
        auto it=lt.upper_bound(i);
        int r=it==lt.end()?n:*it;
        int l=it==lt.begin()?-1:*--it;
        int myex=r-l-1;
        ex[c]=max(ex[c],myex);
      }
      for (int i:bkt[c]) lt.insert(i);
    }
    int mn=INF;
    for (int q=1;q<=n;q++) {
      mn=min(mn,ex[q]);
      if (mn>=n-q+1) res[n-q+1]=1;
    }
    for (int i=1;i<=n;i++)cout<<res[i];
    cout<<'\n';
  }
}
