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
#define A 101
ll n,k;
ll mat[A][A]={{0}};//,mat2[18][18]={{0}},mat3[18][18]={{0}};
void mcpy(ll dst[A][A],ll a[A][A]);
void mmul(ll dst[A][A],ll a1[A][A],ll a2[A][A]) {
  ll dtm[A][A];
  for (int y=0;y<k;y++) {
    for (int x=0;x<k;x++) {
      dtm[x][y]=0;
      for (int q=0;q<k;q++) {
        dtm[x][y]+=a1[q][y]*a2[x][q]%MOD;
        dtm[x][y]%=MOD;
      }
    }
  }
  mcpy(dst,dtm);
}
void mcpy(ll dst[A][A],ll a[A][A]) {
  for (int y=0;y<k;y++)for (int x=0;x<k;x++)dst[x][y]=a[x][y];
}
void pow(ll d) {
  if (d==0) {
    for (int y=0;y<k;y++)for(int x=0;x<k;x++)mat[x][y]=(x==y);
    return;
  }
  if (d==1) return;
  ll nxt[A][A];
  mcpy(nxt,mat);
  pow(d/2);
  mmul(mat,mat,mat);
  if (d%2==1) {
    mmul(mat,mat,nxt);
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>k;
  if (n<k)return cout<<"1\n",0;
  if (n==k)return cout<<"2\n",0;
  for (int i=0;i<k-1;i++) {
    mat[i+1][i]=1;
  }
  for (int i=0;i<k;i++) mat[i][k-1]=(i==0||i==k-1);
  // for (int y=0;y<k;y++){
  //   for(int x=0;x<k;x++) {
  //     cout<<mat[x][y]<<' ';
  //   }
  //   cout<<'\n';
  // }
  // cout<<"\n";
  pow(n);
  // for (int y=0;y<k;y++){
  //   for(int x=0;x<k;x++) {
  //     cout<<mat[x][y]<<' ';
  //   }
  //   cout<<'\n';
  // }
  // cout<<"\n";
  // ll res=0;
  // for (int i=0;i<k;i++) {
  //   res+=(i==0?0:1)*mat[i][k-1]%MOD;
  //   res%=MOD;
  // }
  cout<<(mat[k-1][k-1]%MOD+MOD)%MOD<<'\n';
}
