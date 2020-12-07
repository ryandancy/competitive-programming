#include <bits/stdc++.h>
#define MOD 1000000007
#define INF 1000000000
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795L
#ifdef ONLINE_JUDGE
#define debug(args...) (0)
#else
#include "debug.h"
#endif
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
string m[300];
int main() { // actuall C1
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--) {
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>m[i];
    int v[3]={0};
    for (int i=0;i<n;i++)for(int j=0;j<n;j++) if (m[i][j]=='X') {
      v[(i+j)%3]++;
    }
    int mn=min(min(v[0],v[1]),v[2]);
    int w=v[0]==mn?0:v[1]==mn?1:2;
    for (int s=w;s<2*n;s+=3) {
      int i=s,j=0;
      while (i>=0) {
        if (i<n&&j<n&&m[i][j]=='X')m[i][j]='O';
        i--,j++;
      }
    }
    for (int i=0;i<n;i++) cout<<m[i]<<'\n';
  }
}
