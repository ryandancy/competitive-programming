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
int p[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  int T;
  cin>>T;
  while (T--){
    int n;
    cin>>n;
    for (int i=0;i<n;i++)cin>>p[i];
    int s=n-1,i=1;
    while (s>=0){
      int r=s;
      int l=s-(p[r]-i);
      if (l<0||p[l]!=i){cout<<"No\n";goto end;}
      i=p[r]+1;
      s=l-1;
      for (int j=l+1;j<=r;j++){
        if (p[j]!=p[j-1]+1){cout<<"No\n";goto end;}
      }
    }
    cout<<"Yes\n";
    end:;
  }
}
