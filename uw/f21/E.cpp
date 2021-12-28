#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
string mp[50];ll r,c;
ll pos[50][50]={{0}};
#define L 1
#define R 2
#define U 4
#define D 8
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>r>>c;
  for (ll i=0;i<r;i++){
    cin>>mp[i];
  }
  for (ll i=0;i<r;i++) {
    for (ll j=0;j<c;j++) {
      if (mp[i][j]=='>') pos[i][j]|=R;
      if (mp[i][j]=='<') pos[i][j]|=L;
      if (mp[i][j]=='^') pos[i][j]|=U;
      if (mp[i][j]=='v') pos[i][j]|=D;
    }
  }
  ll per=lcm(r,c);
  set<pair<ll,pair<ll,ll>>> s;
  queue<pair<ll,pair<ll,ll>>> q;
  q.push({0,{0,0}});
  s.insert({0,{0,0}});
  ll gt=0;
  while (q.size()) {
    ll t=q.front().first;
    auto rc=q.front().second;
    q.pop();
    if (rc==make_pair(r-1,c-1)) {
      cout<<t<<'\n';
      return 0;
    }
    if (t!=gt) {
      ll nxt[50][50]={{0}};
      for (ll i=0;i<r;i++) {
        for (ll j=0;j<c;j++) {
          if (pos[i][j]&R) nxt[i][(j+1)%c]|=R;
          if (pos[i][j]&L) nxt[i][(j-1+c)%c]|=L;
          if (pos[i][j]&D) nxt[(i+1)%r][j]|=D;
          if (pos[i][j]&U) nxt[(i-1+r)%r][j]|=U;
        }
      }
      for (ll i=0;i<r;i++) for (ll j=0;j<c;j++) pos[i][j]=nxt[i][j];
      gt=t;
    }
    t++;
    ll i,j;
    tie(i,j)=rc;
    if (pos[i][j]&R) {
      if (!s.count({t%per,{i,(j+1)%c}})) {
        s.insert({t%per,{i,(j+1)%c}});
        q.push({t,{i,(j+1)%c}});
      }
    }
    if (pos[i][j]&L) {
      if (!s.count({t%per,{i,(j+c-1)%c}})) {
        s.insert({t%per,{i,(j+c-1)%c}});
        q.push({t,{i,(j+c-1)%c}});
      }
    }
    if (pos[i][j]&D) {
      if (!s.count({t%per,{(i+1)%r,j}})) {
        s.insert({t%per,{(i+1)%r,j}});
        q.push({t,{(i+1)%r,j}});
      }
    }
    if (pos[i][j]&U) {
      if (!s.count({t%per,{(i+r-1)%r,j}})) {
        s.insert({t%per,{(i+r-1)%r,j}});
        q.push({t,{(i+r-1)%r,j}});
      }
    }
  }
  cout<<"-1\n";
}
