// 363D - Renting Bikes
// Simple binary search solution.
#include <bits/stdc++.h>
using namespace std;
int ns, nb, a;
int b[100000], s[100000];
bool ok(int sh) {
  int v=0;
  for (int i=sh,j=0;i<ns&&j<nb;i++,j++) {
    v+=max(0,b[j]-s[i]);
    if (v>a)return false;
  }
  return v<=a;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin>>ns>>nb>>a;
  for (int i=0;i<ns;i++)cin>>s[i];
  for (int i=0;i<nb;i++)cin>>b[i];
  sort(s,s+ns);
  sort(b,b+nb);
  int l=0,r=ns;
  int x=0;
  while (l<=r) {
    int m=(l+r)/2;
    if (ok(m)) {
      if (m>0&&!ok(m-1)) {
        x=m;
        break;
      } else {
        r=m-1;
      }
    } else {
      l=m+1;
    }
  }
  int bu=0;
  for (int i=x,j=0;i<ns&&j<nb;i++,j++) {
    if (b[j]>s[i]) {
      a-=b[j]-s[i];
      bu+=s[i];
    } else {
      bu+=b[j];
    }
  }
  bu-=a;
  cout<<min((ns-x),nb)<<' '<<max(bu,0)<<'\n';
}
