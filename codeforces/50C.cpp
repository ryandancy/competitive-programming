#include <bits/stdc++.h>
using namespace std;
int x[100000], y[100000];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin>>n;
  int mnx=-1, mxx=-1, mny=-1, mxy=-1;
  int lymx, hymx, lypx, hypx;
  bool f=true;
  for (int i=0;i<n;i++){
    cin>>x[i]>>y[i];
    int ymx=y[i]-x[i], ypx=y[i]+x[i];
    if (f||x[i]<mnx)mnx=x[i];
    if (f||x[i]>mxx)mxx=x[i];
    if (f||y[i]<mny)mny=y[i];
    if (f||y[i]>mxy)mxy=y[i];
    if (f||ymx<lymx)lymx=ymx;
    if (f||ymx>hymx)hymx=ymx;
    if (f||ypx<lypx)lypx=ypx;
    if (f||ypx>hypx)hypx=ypx;
    f=false;
  }
  mnx--, mny--, mxx++, mxy++, lymx--, lypx--, hymx++, hypx++;
  cout<<(
    2*(mxx-mnx)+2*(mxy-mny)-(
      mxy-hymx-mnx + mxx-hypx+mxy + mxx-mny+lymx + lypx-mny-mnx
    )
  )<<'\n';
}
