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
int d[4][50],m[2][100],n,k;
vector<tuple<int,int,int>> res;
#ifdef ONLINE_JUDGE
#define print() (0)
#else
void print() {
  for (int i=0;i<2*n;i++) cout<<m[0][i]<<' ';
  cout<<'\n';
  for (int i=0;i<2*n;i++) cout<<m[1][i]<<' ';
  cout<<"\n----\n";
}
#endif
void adl(int x, int r, int c) {
  int rr=c<n?(r==0?2:1):(r==0?3:4);
  int rc=c<n?c+1:n-(c-n);
  res.push_back({x,rr,rc});
}
void home() {
  for (int i=0;i<2*n;i++) {
    if (m[0][i]&&m[0][i]==m[1][i]) {
      adl(m[0][i],1,i);
      m[0][i]=0;
    }
  }
  print();
}
bool rot() {
  int z;
  for (z=0;z<2*n;z++) if (m[0][z]==0) break;
  if (z==2*n) return false;
  for (int i=2*n;i>0;i--) {
    int c=(z+i)%(2*n);
    int nx=(c+1)%(2*n);
    if (m[0][c]&&!m[0][nx]) {
      adl(m[0][c],0,nx);
      m[0][nx]=m[0][c];
      m[0][c]=0;
      debug(c,nx);
    }
  }
  print();
  return true;
}
bool done() {
  bool r=true;
  for (int i=0;i<2*n;i++) if (m[0][i]) {r=false;break;}
  return r;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>k;
  for (int i=0;i<4;i++) {
    for (int j=0;j<n;j++) cin>>d[i][j];
  }
  for (int i=0;i<n;i++) {
    m[0][i]=d[1][i];
    m[0][n+i]=d[2][n-i-1];
    m[1][i]=d[0][i];
    m[1][n+i]=d[3][n-i-1];
  }
  print();
  home();
  while (!done()) {
    if (!rot()) return cout<<"-1\n",0;
    home();
  }
  cout<<res.size()<<'\n';
  for (tuple<int,int,int>&v:res) {
    int a,b,c;
    tie(a,b,c)=v;
    cout<<a<<' '<<b<<' '<<c<<'\n';
  }
}
