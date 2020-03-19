#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;
int p[200000];
int d[200000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin>>n>>k;
  for (int i=0;i<n;i++){cin>>p[i];d[i]=i;}
  sort(d,d+n,[&](int a, int b){return p[a]>p[b];});
  ll s=0;
  for (int i=0;i<k;i++)s+=p[d[i]];
  ll v=1;
  sort(d,d+k);
  for (int i=0;i<k-1;i++){
    ll df=d[i+1]-d[i];
    v*=df;
    v%=MOD;
  }
  cout<<s<<' '<<v<<'\n';
}
