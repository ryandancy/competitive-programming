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
int a[50];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifdef DEBUG
  freopen("inp.txt", "r", stdin);
#endif
  int n;
  cin>>n;
  for (int i=0;i<n;i++)cin>>a[i];
  cout<<setprecision(20);
  ld c=0;
  ld f=1;
  for (int i=0;i<n;i++){
    c+=f*a[i];
    f*=0.8;
  }
  cout<<c/5.0l<<'\n';
  ld tot=0;
  for (int s=0;s<n;s++){
    ld g=0;
    f=1;
    for (int i=0;i<n;i++){
      if (i==s)i++;
      g+=f*a[i];
      f*=0.8l;
    }
    tot+=g/5.0l;
  }
  cout<<tot/(ld)n<<'\n';
}
