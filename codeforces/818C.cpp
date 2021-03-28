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
ll d,n,m;
struct sf { ll x1,y1,x2,y2; } s[100000];
vector<ll> ls, rs, ts, bs;
ll l,r,t,b;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>d>>n>>m;
  for (ll i=0;i<d;i++) {
    cin>>s[i].x1>>s[i].y1>>s[i].x2>>s[i].y2;
    ls.push_back(min(s[i].x1,s[i].x2));
    rs.push_back(max(s[i].x1,s[i].x2));
    ts.push_back(min(s[i].y1,s[i].y2));
    bs.push_back(max(s[i].y1,s[i].y2));
  }
  cin>>l>>r>>t>>b;
  sort(ls.begin(),ls.end());
  sort(rs.begin(),rs.end());
  sort(ts.begin(),ts.end());
  sort(bs.begin(),bs.end());
  for (ll i=0;i<d;i++) {
    ll nl=lower_bound(ls.begin(),ls.end(),max(s[i].x1,s[i].x2))-ls.begin();
    if (s[i].x1!=s[i].x2)nl--;
    ll nr=rs.end()-upper_bound(rs.begin(),rs.end(),min(s[i].x1,s[i].x2));
    if (s[i].x1!=s[i].x2)nr--;
    ll nt=lower_bound(ts.begin(),ts.end(),max(s[i].y1,s[i].y2))-ts.begin();
    if (s[i].y1!=s[i].y2)nt--;
    ll nb=bs.end()-upper_bound(bs.begin(),bs.end(),min(s[i].y1,s[i].y2));
    if (s[i].y1!=s[i].y2)nb--;
    if (nl==l&&nr==r&&nt==t&&nb==b) {
      cout<<i+1<<'\n';
      return 0;
    }
  }
  cout<<"-1\n";
}
