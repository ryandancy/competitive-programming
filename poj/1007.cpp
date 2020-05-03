// Totally overkill O(mn + mlogm) solution when O(mn^2 + mlogm) would suffice.
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <algorithm>
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
string s[100];
int cnt[100][50][4]={{{0}}};
int v[100], idx[100];
const string V="ACGT";
bool cmp(int a, int b){
  return v[a]<v[b];
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int n, m;
  cin>>n>>m;
  for (int i=0;i<m;i++)cin>>s[i], idx[i]=i;
  for (int i=0;i<m;i++){
    cnt[i][0][V.find(s[i][0])]=1;
    v[i]=0;
    for (int j=1;j<n;j++){
      int r=V.find(s[i][j]);
      int inv=0;
      for (int k=3;k>=0;k--){
        cnt[i][j][k]=cnt[i][j-1][k];
        if (k==r) {
          cnt[i][j][k]++;
        } else if (k>r) {
          inv+=cnt[i][j][k];
        }
      }
      v[i]+=inv;
    }
  }
  stable_sort(idx, idx+m, cmp);
  for (int i=0;i<m;i++){
    cout<<s[idx[i]]<<'\n';
  }
}
