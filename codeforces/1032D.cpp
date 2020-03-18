// 1032D - Barcelonian Distance
// Just try going to each side, O(1).
// Special cases are BAD BAD BAD.
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
#ifndef ONLINE_JUDGE
  freopen("inp.txt", "r", stdin);
#endif
  ld a, b, c, x1, y1, x2, y2;
  cin>>a>>b>>c>>x1>>y1>>x2>>y2;
  cout<<setprecision(20);
  ld u=abs(x1-x2)+abs(y1-y2);
  ld xi1=(-c-b*y1)/a, xi2=(-c-b*y2)/a, yi1=(-c-a*x1)/b, yi2=(-c-a*x2)/b;
  for (int i=0;i<=1;i++){
    for (int j=0;j<=1;j++){
      ld nu=0;
      ld nx1,ny1,nx2,ny2;
      if (i) nx1=xi1,ny1=y1,nu+=abs(xi1-x1);
      else nx1=x1,ny1=yi1,nu+=abs(yi1-y1);
      if (j) nx2=xi2,ny2=y2,nu+=abs(xi2-x2);
      else nx2=x2,ny2=yi2,nu+=abs(yi2-y2);
      nu+=hypotl(abs(nx1-nx2),abs(ny1-ny2));
      u=min(u,nu);
    }
  }
  cout<<u<<'\n';
}
