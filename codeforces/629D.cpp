#include <bits/stdc++.h>
#define PI 3.1415926535897932384626433832795L
using namespace std;
typedef long long ll;
typedef long double ld;
ll vp[100000], bit[100001]={0}, q[100000], k[100000], ne[100000]={0};
int n;
void bit_set(int x, ll v) {
  x++;
  while (x<=n){
    bit[x]=max(bit[x],v);
    x+=x&-x;
  }
}
ll bit_max(int x) {
  x++;
  ll res=0;
  while (x>0){
    res=max(res,bit[x]);
    x-=x&-x;
  }
  return res;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n;
  cout<<setprecision(30);
  for (int i=0;i<n;i++){
    ll r,h;
    cin>>r>>h;
    vp[i]=r*r*h;
    q[i]=i;
  }
  sort(q,q+n,[&](ll a, ll b){return vp[a]<vp[b];});
  for (int i=0;i<n;i++) k[q[i]] = i;
  ne[q[0]]=0;
  for (int i=1;i<n;i++){
    if (vp[q[i]]==vp[q[i-1]]) ne[q[i]]=ne[q[i-1]]+1;
    else ne[q[i]]=0;
  }
  bit_set(k[0],vp[0]);
  for (int i=1;i<n;i++){
    ll nw=vp[i]+bit_max(k[i]-ne[i]-1);
    bit_set(k[i],nw);
  }
  cout<<PI*(ld)bit_max(n-1)<<'\n';
}
