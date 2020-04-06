#include <bits/stdc++.h>
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
int a[1000];
int p[11]={2,3,5,7,11,13,17,19,23,29,31};
int pa[1000];
bool u[11]={false};
int tmx[11]={0};
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int t;
  cin>>t;
  while (t--){
    int n;cin>>n;
    fill_n(u,11,false);
    for (int i=0;i<n;i++)cin>>a[i];
    for (int i=0;i<n;i++){
      for (int j=0;j<11;j++){
        if (a[i]%p[j]==0) {
          pa[i]=j;
          u[j]=true;
          break;
        }
      }
    }
    int m=0;
    for (int i=0;i<11;i++){
      if (u[i]) {
        m++;
        tmx[i]=m;
      }
    }
    cout<<m<<'\n';
    for (int i=0;i<n;i++){
      cout<<tmx[pa[i]]<<(i==n-1?'\n':' ');
    }
  }
}
