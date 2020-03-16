// 283B - Cow Program
// Precompute ending-y values (sums) for each position, forwards and backwards in O(n).
// Use a three-valued status to detect loops, then print in O(n).
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[200000];
int g[200000][2]={{0}};
ll sm[200000][2];//0<,1>
int c[500000],cs=0;
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  for (int i=0;i<n-1;i++)cin>>a[i];
  for (int t=0;t<=1;t++){
    for (int i=0;i<n-1;i++){
      if (g[i][t]!=0)continue;
      cs=0;
      c[cs++]=i;
      int jp=t;
      ll s=a[i];
      g[i][jp]=1;
      while (1) {
        ll nx;
        if (jp) nx=c[cs-1]+a[c[cs-1]];
        else nx=c[cs-1]-a[c[cs-1]];
        jp=!jp;
        if (nx< -1||nx>=n-1){
          break;
        } else if (nx==-1||g[nx][jp]!=0) {
          if (nx==-1||sm[nx][jp]==-1||g[nx][jp]==1){
            for (int j=0,cjp=t;j<cs;j++,cjp=!cjp){
              sm[c[j]][cjp]=-1;
            }
            goto nxtcl;
          } else {
            s+=sm[nx][jp];
            break;
          }
        } else {
          g[nx][jp]=1;
          c[cs++]=nx;
          s+=a[nx];
        }
      }
      for (int j=0,cjp=t;j<cs;j++,cjp=!cjp){
        g[c[j]][cjp]=2;
        sm[c[j]][cjp]=s;
        s-=a[c[j]];
      }
      nxtcl:;
    }
  }
  for (int i=0;i<n-1;i++){
    ll s=sm[i][0];
    if (s!=-1){
      s+=(i+1);
    }
    cout<<s<<'\n';
  }
}
