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
int n,s,a[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  cin>>n>>s;
  for (int i=0;i<n;i++)cin>>a[i];
  s--;
  bool add1=a[s]!=0;
  a[s]=0;
  sort(a,a+n);
  int fnz=0;
  while (fnz<n&&a[fnz]==0)fnz++;
  if (fnz==n){cout<<n-1+add1<<'\n'; return 0;}
  int fr0=fnz-1;
  int bst=INF;
  int en=0,nfe=0;
  for (int i=fnz;i<n;i++) {
    en+=max(a[i]-a[i-1]-1,0);
    if (a[i]==a[i-1])nfe++;
    int fe=fr0+n-i-1;
    int res=fe;
    int el=en-fe;
    if (el>0){
      res+=nfe;
      el-=nfe;
      if (el>0) continue;
    }
    debug(i, a[i], fe, nfe, res);
    bst=min(bst,res);
  }
  cout<<bst+add1<<'\n';
}
