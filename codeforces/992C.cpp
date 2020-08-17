#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;
ll qpow2(ll n) {
  if (n==0) return 1;
  if (n==1) return 2;
  ll o2=qpow2(n/2);
  o2*=o2;
  o2%=MOD;
  if (n%2)o2*=2,o2%=MOD;
  return o2;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll x, k;
  cin>>x>>k;
  if (x==0) return cout<<"0\n",0;
  x%=MOD;
  x*=2;
  x%=MOD;
  ll p2=qpow2(k);
  x=p2*(x-1); x%=MOD;
  x+=MOD; x%=MOD;
  x++; x%=MOD;
  x+=MOD; x%=MOD;
  cout<<x<<'\n';
}
