#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
ld x[16], y[16];
ld dp[1<<17];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  char _[200];
  int c=0;
  while(1){
    scanf("%d",&n);
    if (n==0)break;
    c++;
    for (int i=0;i<2*n;i++)scanf("%s %Lf %Lf", _, &x[i], &y[i]);
    dp[0]=0;
    for (int a=0;a<2*n;a++){
      for (int b=0;b<2*n;b++){
        if (a==b)continue;
        dp[(1<<a)|(1<<b)]=sqrtl((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
      }
    }
    for (int i=7;i<(1<<(2*n));i++){
      int pc=__builtin_popcount(i);
      if (pc<=2||pc%2)continue;
      dp[i]=-1;
      for (int a=0;a<2*n;a++){
        for (int b=0;b<2*n;b++){
          if (a==b||(i&(1<<a))==0||(i&(1<<b))==0)continue;
          ld d = dp[i&~((1<<a)|(1<<b))]+dp[(1<<a)|(1<<b)];
          if (dp[i]==-1||d<dp[i])dp[i]=d;
        }
      }
    }
    printf("Case %d: %.2Lf\n", c, dp[(1<<(2*n))-1]);
  }
}
