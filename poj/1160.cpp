// Simple O(V^2 P) DP, lots of number twiddling
#include <iostream>
#include <cstdio>
#define INF 1000000000
using namespace std;
int x[301], dp[301][31], rs[301];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int V, P;
  scanf("%d %d", &V, &P);
  for (int i=1;i<=V;i++) scanf("%d", &x[i]);
  for (int i=0;i<=V;i++) for (int j=0;j<=P;j++) dp[i][j]=INF;
  dp[1][1]=0;
  for (int v=2;v<=V;v++) dp[1][1]+=x[v]-x[1];
  for (int v=2;v<=V;v++) {
    dp[v][1]=dp[v-1][1]+(2*v-V-2)*(x[v]-x[v-1]);
  }
  rs[1]=dp[1][1];
  for (int v=2;v<=V;v++){
    rs[v]=rs[v-1]-(V-v+1)*(x[v]-x[v-1]);
  }
  for (int p=2;p<=P;p++){
    for (int v=p;v<=V;v++){
      int ad=0, ad2=0, cp=v-1;
      for (int v2=v-1;v2>=p-1;v2--,ad2+=(cp-v2)*(x[v2+1]-x[v2])){
        while (cp>v2&&x[v]-x[cp]<x[cp]-x[v2]) ad+=x[v]-x[cp], ad2-=x[cp]-x[v2], cp--;
        dp[v][p]=min(dp[v][p], dp[v2][p-1]-rs[v2]+rs[v]+ad+ad2);
      }
    }
  }
  int bst=INF;
  for (int v=P;v<=V;v++){
    bst=min(bst,dp[v][P]);
  }
  printf("%d\n", bst);
}
