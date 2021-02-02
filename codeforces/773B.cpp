// put it in a convenient format and then brute force it lol
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[5],b[5],cs[5]={0},d[5]={0};
bool ok(ll p,bool*dn) {
  ll res=0;
  *dn=true;
  for (int i=0;i<5;i++) {
    ll an=n;
    if ((d[i]>0&&a[i]>0)||a[i]==0)an+=p;
    ll mul=1;
    if (cs[i]*2<=an)mul=2;
    if (cs[i]*4<=an)mul=3;
    if (cs[i]*8<=an)mul=4;
    if (cs[i]*16<=an)mul=5;
    if (cs[i]*32<=an)mul=6; else if (d[i]>0&&a[i]>0) *dn=false;
    res+=mul*d[i];
  }
  return res>0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>n;
  for (int i=0;i<5;i++){cin>>a[i];if(a[i]!=-1)cs[i]++,a[i]=2*(250-a[i]);else a[i]=0;}
  for (int i=0;i<5;i++){cin>>b[i];if(b[i]!=-1)cs[i]++,b[i]=2*(250-b[i]);else b[i]=0;}
  for (int i=0;i<5;i++)d[i]=a[i]-b[i];
  for (int i=0;i<n-2;i++){
    for (int j=0;j<5;j++) {
      ll x;
      cin>>x;
      if (x!=-1)cs[j]++;
    }
  }
  bool dn=false; ll p=0;
  do {
    if (ok(p,&dn)) {
      cout<<p<<"\n";
      return 0;
    }
    p++;
  } while (!dn);
  cout<<"-1\n";
}
