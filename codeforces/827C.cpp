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
string s; ll q; ll N;
ll b[4][11][10][100001]={{{{0}}}}; // [char][mod][residue]
void add(ll *bit, ll x, ll v) {
  x++;
  while (x<=N) {
    bit[x]+=v;
    x+=x&-x;
  }
}
ll sum(ll *bit, ll x) {
  x++;
  ll res=0;
  while (x>0) {
    res+=bit[x];
    x-=x&-x;
  }
  return res;
}
ll rs(ll *bit, ll l, ll r) {
  ll res=sum(bit, r);
  if (l!=0) res-=sum(bit, l-1);
  return res;
}
ll cv(char c) {
  if (c=='A') return 0;
  if (c=='T') return 1;
  if (c=='G') return 2;
  return 3;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>s>>q;
  N=s.size();
  for (ll i=0;i<N;i++) {
    ll x=cv(s[i]);
    for (ll m=1;m<=10;m++) {
      add(b[x][m][i%m],i,1);
    }
  }
  while (q--) {
    ll t;
    cin>>t;
    if (t==1) {
      ll x; char ch;
      cin>>x>>ch;
      x--;
      ll c=cv(ch);
      ll pv=cv(s[x]);
      for (ll m=1;m<=10;m++) {
        add(b[pv][m][x%m],x,-1);
        add(b[c][m][x%m],x,1);
      }
      s[x]=ch;
    } else {
      ll l,r; string e;
      cin>>l>>r>>e;
      l--,r--;
      ll m=e.size();
      ll res=0;
      for (ll i=0;i<m;i++) {
        ll c=cv(e[i]);
        res+=rs(b[c][m][(l+i)%m],l,r);
      }
      cout<<res<<'\n';
    }
  }
}
