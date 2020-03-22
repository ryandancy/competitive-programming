// 1089F - Fractions
// I knew MATH 135 was useful in the real world.
// Formally proving everything was probably a bit overkill though.
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;
  cin>>n;
  ll a=-1,b=-1;
  for (int i=2;i*i<=n;i++) {
    if (n%i==0){
      bool cop=(n/i)%i!=0;
      for (int j=2;j*j<=i&&cop;j++){
        if (i%j==0&&(n/i)%j==0){
          cop=false;
          break;
        }
      }
      if (cop){a=i,b=n/i;break;}
    }
  }
  if (a==-1)return cout<<"NO\n",0;
  ll s0=1,s1=0,t0=0,t1=1,r0=a,r1=b;
  while (r1) {
    ll q=r0/r1;
    ll ns=s0-q*s1,nt=t0-q*t1,nr=r0-q*r1;
    s0=s1,t0=t1,r0=r1;
    s1=ns,t1=nt,r1=nr;
  }
  ll s=s0,t=t0;
  ll d0=s*(n-1), c0=t*(n-1);
  ll k=c0/a;
  if (k<0)k--;
  ll d=d0+b*k, c=c0-a*k;
  cout<<"YES\n2\n"<<c<<' '<<a<<'\n'<<d<<' '<<b<<'\n';
}
