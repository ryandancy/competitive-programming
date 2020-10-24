#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
int dp[1<<18][2]; // delta for current player: 0=A, 1=B
int chk[18][2][2] = {
  {{1, 2}, {20, 20}}, // 0
  {{0, 2}, {20, 20}}, // 1
  {{0, 1}, {4, 5}}, // 2
  {{4, 7}, {20, 20}}, // 3
  {{3, 7}, {2, 5}}, // 4
  {{2, 4}, {6, 8}}, // 5
  {{5, 8}, {20, 20}}, // 6
  {{3, 4}, {10, 11}}, // 7
  {{5, 6}, {12, 13}}, // 8
  {{10, 15}, {20, 20}}, // 9
  {{9, 15}, {7, 11}}, // 10
  {{7, 10}, {12, 16}}, // 11
  {{11, 16}, {8, 13}}, // 12
  {{8, 12}, {14, 17}}, // 13
  {{13, 17}, {20, 20}}, // 14
  {{9, 10}, {20, 20}}, // 15
  {{11, 12}, {20, 20}}, // 16
  {{13, 14}, {20, 20}}, // 17
};
int nbm[19][19] = {
  [1] = {[2] = 0, [3] = 1},
  [2] = {[3] = 2, [4] = 3, [5] = 4},
  [3] = {[5] = 5, [6] = 6},
  [4] = {[5] = 7, [7] = 9, [8] = 10},
  [5] = {[6] = 8, [8] = 11, [9] = 12},
  [6] = {[9] = 13, [10] = 14},
  [7] = {[8] = 15},
  [8] = {[9] = 16},
  [9] = {[10] = 17},
};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  dp[(1<<18)-1][0]=0;
  dp[(1<<18)-1][1]=0;
  for (int bm=(1<<18)-2;bm>=0;bm--) {
    for (int t=0;t<=1;t++) {
      int bst=-INF;
      for (int b=0;b<18;b++) {
        if (bm&(1<<b))continue;
        int c=0;
        if ((bm&(1<<chk[b][0][0]))&&(bm&(1<<chk[b][0][1]))) c++;
        if ((bm&(1<<chk[b][1][0]))&&(bm&(1<<chk[b][1][1]))) c++;
        if (c>0) {
          c+=dp[bm|(1<<b)][t];
        } else {
          c-=dp[bm|(1<<b)][!t];
        }
        bst=max(bst,c);
      }
      dp[bm][t]=bst;
    }
  }
  int G;
  cin>>G;
  for (int g=1;g<=G;g++) {
    int m;
    cin>>m;
    int sc[2]={0},t=0;
    int bm=0;
    for (int i=0;i<m;i++) {
      int x,y;
      cin>>x>>y;
      int e = nbm[x][y];
      int c=0;
      if ((bm&(1<<chk[e][0][0]))&&(bm&(1<<chk[e][0][1]))) c++;
      if ((bm&(1<<chk[e][1][0]))&&(bm&(1<<chk[e][1][1]))) c++;
      sc[t]+=c;
      if (c==0) t=!t;
      bm|=(1<<e);
    }
    sc[t]+=dp[bm][t];
    cout<<"Game "<<g<<": ";
    if (sc[0]>sc[1]) cout<<"A wins.\n";
    else cout<<"B wins.\n";
  }
}
