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
int n;
pii xy[300];
bool cw(pii& a, pii& b, pii& c) {
  int ax=b.first-a.first,ay=b.second-a.second;
  int bx=c.first-b.first,by=c.second-b.second;
  return ax*by-ay*bx>=0;
}
ld ar(pii& a, pii& b, pii& c) {
  int ax=b.first-a.first,ay=b.second-a.second;
  int bx=c.first-b.first,by=c.second-b.second;
  return abs(ax*by-ay*bx)/2.0L;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  cout<<setprecision(20);
  for (int i=0;i<n;i++){
    cin>>xy[i].first>>xy[i].second;
  }
  ld ga=0;
  for (int i=0;i<n;i++) {
    for (int j=0;j<n;j++) {
      if(i==j)continue;
      pii &a=xy[i], &b=xy[j];
      ld ta=0,ba=0;
      for (int k=0;k<n;k++) {
        if (k==i||k==j)continue;
        if (cw(a,xy[k],b)) {
          ta=max(ta,ar(a,xy[k],b));
        } else {
          ba=max(ba,ar(a,xy[k],b));
        }
      }
      if (ta!=0&&ba!=0)ga=max(ga,ta+ba);
    }
  }
  cout<<ga<<endl;
}
