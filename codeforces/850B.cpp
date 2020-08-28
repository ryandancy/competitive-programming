// this has a super hard to analyze time complexity
// seems like O(n^2) or at least O(n^1.5) but fast enough in practice
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cpp[1000001]={0}, nh[1000001]={0}, b[1000001]={0}, n, x, y;
int k[1000001]={0};
bool sieve[1000001]={false};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>x>>y;
  for (int i=0;i<n;i++){
    ll a;
    cin>>a;
    b[a]++;
  }
  sieve[0]=sieve[1]=true; k[0]=0; k[1]=1;
  for (int i=2;i<=1000000;i++) {
    k[i]=i;
    if (sieve[i]) continue;
    for (int j=i;j<=1000000;j+=i) {
      if (j>i) sieve[j]=true;
      nh[i]+=b[j];
    }
  }
  sort(k,k+1000001,[&](int X, int Y){return nh[X]>nh[Y];});
  ll m=n*min(x,y);
  for (int i=0;i<=1000000&&nh[k[i]];i++) {
    int p=k[i];
    ll tc=nh[p],r=0;
    if (y>=x) {
      r=x*(n-tc);
      if (r>=m) break;
      m=r;
      continue;
    }
    if (y*(n-tc)>=m) break;
    for (int j=1;j<p;j++) {
      if (j*y>=x) {
        r+=x*(n-tc);
        break;
      }
      ll pr=j*y*(n-tc)+r;
      if (pr>=m)goto nxt;
      ll thc=0;
      for (int x=p-j;x<=1000000;x+=p) {
        thc+=b[x];
      }
      r+=thc*j*y;
      tc+=thc;
    }
    m=min(r,m);
    nxt:;
  }
  cout<<m<<'\n';
}
