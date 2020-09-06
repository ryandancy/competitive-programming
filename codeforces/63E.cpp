// bitmask dp
#include <bits/stdc++.h>
using namespace std;
bool dp[1 << 19];
int re[19] = {2, 2, 2, 6, 6, 6, 6, 11, 11, 11, 11, 11, 15, 15, 15, 15, 18, 18, 18};
int nbr[19] = {4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, -1, 16, 17, 18, -1, -1, -1, -1};
int nbl[19] = {3, 4, 5, 7, 8, 9, 10, -1, 12, 13, 14, 15, -1, 16, 17, 18, -1, -1, -1};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  dp[0]=false;
  for (int bm=1;bm<(1<<19);bm++) {
    dp[bm]=false;
    for (int b=0;b<19;b++) {
      if (!(bm&(1<<b)))continue;
      int nbm=bm&~(1<<b);
      if (!dp[nbm]) {dp[bm]=true; goto nx;}
      for (int nb=b+1;nb<=re[b];nb++) {
        if (!(bm&(1<<nb)))break;
        nbm&=~(1<<nb);
        if (!dp[nbm]) {dp[bm]=true; goto nx;}
      }
      nbm=bm&~(1<<b);
      for (int nb=nbr[b];nb!=-1;nb=nbr[nb]){
        if (!(bm&(1<<nb)))break;
        nbm&=~(1<<nb);
        if (!dp[nbm]) {dp[bm]=true; goto nx;}
      }
      nbm=bm&~(1<<b);
      for (int nb=nbl[b];nb!=-1;nb=nbl[nb]) {
        if (!(bm&(1<<nb)))break;
        nbm&=~(1<<nb);
        if (!dp[nbm]) {dp[bm]=true; goto nx;}
      }
    }
    nx:;
  }
  string inp;
  int bm=0;
  for (int i=0;i<19;i++) {
    cin>>inp;
    bm=(bm<<1)|(inp=="O");
  }
  cout<<(dp[bm]?"Karlsson":"Lillebror")<<'\n';
}
