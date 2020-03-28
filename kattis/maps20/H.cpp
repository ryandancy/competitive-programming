#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifndef DEBUG
#define debug(args...)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll ds[50], q[50], ans[50];
ll na[1001]={0}, na2[1001];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int C,N,M;
  cin>>C>>N>>M;
  for (int i=0;i<N;i++){
    int c;
    cin>>c;
    na[c]++;
  }
  for (int i=0;i<M;i++){
    cin>>ds[i];
    q[i]=i;
  }
  sort(q,q+M,[&](int a,int b){return ds[a]<ds[b];});
  int d=1;
  for (int i=0;i<M;i++){
    int dl=ds[q[i]];
    for (;d<=dl;d++){
      for (int i=1;i<=C;i++){
        if (i*2<=C){
          na2[2*i]+=na[i];
        } else {
          na2[i]+=2ll*na[i];
        }
      }
      for (int i=1;i<=C;i++){
        na[i]=na2[i];
        na2[i]=0;
      }
    }
    ll k=0;
    for (int i=1;i<=C;i++)k+=na[i];
    ans[q[i]]=k;
  }
  for (int i=0;i<M;i++)cout<<ans[i]<<'\n';
}
